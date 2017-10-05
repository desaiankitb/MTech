
#include <stdio.h>
#include <string.h>

#define SIZE	200
#define NARG	50

char prompt[] = "Hello>";
char cmd[SIZE];
char cmd1[SIZE];
char *myarg[NARG];

void strparse();

int main(int argc, char *argv[])
{
	int pid;
	int i;

	while(1) {
		write(1, prompt, strlen(prompt));
		fgets(cmd1, SIZE, stdin);
		if (strncmp(cmd1, "exit", strlen("exit")) == 0) {
			exit(0);
		}
		strparse();	
		pid = fork();
		if (pid == 0) { //child
			/*strcpy(cmd,"");
			strcat(cmd, "/bin/");
			strcat(cmd, myarg[0]);*/
			file:///media/ZALPARI/myshell.c
			execvp(myarg[0], myarg);
			//execl(cmd, cmd1, NULL);
			//execl("/bin/ls", "ls","-l", NULL);
		}
		else { //parent
			waitpid(pid, NULL, 0);
		}
		printf("%s",myarg[0]);
		printf("%s",myarg);
		printf("\n");
	}
}
void strparse()
{
	char tmp[100];
	int i=0; // for tmp
	int j=0; // for arg
	int k=0; // for str

	while(1) {
		for(i=0; ; ) {
			if (cmd1[k] == '\0' || cmd1[k] == '\n' || 
			    cmd1[k] == ' '  || cmd1[k] == '\t') 
			{
				tmp[i++] = '\0';
				while(cmd1[k] == ' ' || cmd1[k] == '\t')
					k++;
				break;
			}
			else
				tmp[i++] = cmd1[k++];
		}
		
		myarg[j] = (char *) malloc((strlen(tmp)+1) * sizeof(char));
		strcpy(myarg[j], tmp);
		write(1, myarg[j], strlen(myarg[j]));
		printf("\n");
		
		j++;

		if (cmd1[k] == '\0' || cmd1[k] == '\n')
			break;
	}	
	myarg[j] = NULL;
	printf("%s",myarg);
}
