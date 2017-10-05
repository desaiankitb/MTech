/*
 * 	edinvoke.c
 *      works 29-1-07
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/select.h>
#include <fcntl.h>

static FILE *sndfp, *rcvfp, *errfp;
char unique[100]; /* unique reply from ed */
static int setnoblock(int fd1);

static edinvoke(){
	int pfdout[2], pfdin[2], pfderr[2];
	/* ed outputs significant errors on stderr */
	
	if(pipe(pfdout) == -1 || pipe(pfdin) == -1 || pipe(pfderr) == -1){
		perror("pipe");
		exit(-1);	
	}
	sndfp = fdopen(pfdout[1], "w");
	rcvfp = fdopen(pfdin[0], "r");
	errfp = fdopen(pfderr[0], "r");
	
	switch((int)fork()){
		case -1: perror("fork"); exit(-1);
		case 0: 
			if(dup2(pfdout[0],0) == -1){
				perror("dup2"); 
				exit(-2);
			}
			if(dup2(pfdin[1],1) == -1){
				perror("dup2"); 
				exit(-3);
			}/*
			if(dup2(pfderr[1],2) == -1){
				perror("dup2"); 
				exit(-3);
			}*/
		/*setnoblock(1);*/	
			if(close(pfdout[0]) == -1 ||
			   close(pfdout[1]) == -1 ||
			   close(pfdin[0]) == -1 
			   || close(pfdin[1]) == -1)
				perror("close"); 
			execl("/bin/ed", "ed", "-pED:",  "-s", NULL);
			perror("execlp"); 
			exit(-1);
		default: break;	
	}
	if(close(pfdout[0]) == -1 || close(pfdin[1]) == -1)
	       perror("close");  
}

static int setnoblock(int fd1){
	int flags;
	if((flags = fcntl(fd1, F_GETFL, 0)) == -1)
			perror("fcntl");
	return(fcntl(fd1, F_SETFL, flags | O_NONBLOCK));
}

static void edsnd(char *s){
	int fd;
	fd = fileno(sndfp);
	/*if(fputs(s, sndfp) == EOF){
		perror("edsnd");
		exit(-4);
	}*/
	write(fd, s, strlen(s));
}

static int edrcv(char *s, int max){
	  int fd, n = 0;
	  fd = fileno(rcvfp);
	  /*if(fgets(s, max, rcvfp) == NULL){
		perror("edrcv");
		exit(-5);
	}*/
         n = read(fd, s, max);	
       	
	return(n);
}

static int ederr(char *t, int max){
	if(fgets(t, 100, errfp) == NULL){
		perror("edrcv:err");
		exit(-7);
	}
	return(strlen(t));
}
static void turnaround(){
	edsnd("r zzzzzz\n");
	fflush(sndfp);
}

static void rcvall(){
	char s[512]={0,0,0};
	fd_set rfds;
        struct timeval tv;
	int retval, fd, n;
	
	fd = fileno(rcvfp);
	FD_ZERO(&rfds);
	FD_SET(fd, &rfds);
	/* Wait up to 2 seconds. */
	tv.tv_sec = 2;
	tv.tv_usec = 0;
        retval = select(15, &rfds, NULL, NULL, &tv);
	/* Don’t rely on the value of tv now! */
	 if (retval == -1)
               perror("select()");
         else if (retval && FD_ISSET(fd, &rfds)){
		 
		while(strstr(s, "ED:") == NULL){
		       edrcv(s, 512);	
			printf("%s", s);
		}
	
	 } else printf("rcvall() timed out\n");
}

static void get_unique(){
	turnaround();
	if(fgets(unique, 100, errfp) == NULL){
		perror("get_unique");
		exit(-2);
	}
}

static int prompt(char *msg, char *result){
	printf("\n%s?", msg);
	fgets(result, 100, stdin);
	result[strlen(result)-1] = '\0';
	return(strlen(result));	
}

int main(){
	char s[100], line[100];
	int fd1;
	
	edinvoke(); 
	fd1 = fileno(rcvfp); 
	/*setnoblock(fd1);*/ 
	/*get_unique(); */
       /*fprintf(stderr,"[%s]\n", unique);*/	
	/*printf("[%s] %d\n", s, edrcv(s,100));*/
	rcvall();
	if(!prompt("File", s)) exit (0);
	sprintf(line, "e %s\n", s);
	edsnd(line); 
	rcvall();
	/*printf("[%s] %d\n", s, edrcv(s,100)); */
	while(prompt("Search pattern", s)){
		sprintf(line, "g/%s/p\n", s);
		edsnd(line);
		rcvall();
	} 
	edsnd("q\n"); 
	exit(0);
}

