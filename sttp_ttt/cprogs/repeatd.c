/*
	repeatd.c
	
	Gries p. 259 problem no. 9
	The fractional part of the decimal value of 1/n, where n is a +ve
	integer is known to have repeated sub-sequence as follows :
	0.[ S0 ][ S1 ][ S1 ] ...
	S0 may have possibly 0 length.
	Write a program to find lenths of S0 and S1.
*/

int r, q, n, len, s0;
int used[11];

int findj(int n){
		int i;
		
		for(i=0;i<10;i++) used[i] = 0;

		r = 1; len = 0;
		q = 10*r /n; printf("\n step %d: r = %d, q = %d\n", len, r, q);		
		do{
			
			len++;
			used[q] = len;
			r = (10*r) % n;
			q =(10*r) / n;
			printf("\n step %d: r = %d, q = %d\n", len, r, q);
		} while(!used[q] && len < 10);
		s0 = used[q]-1;
		return len - s0;
}

main(int argc, char *argv[]){
	int j;
	
	if(argc != 2){ printf("\nUsage  : %s <n value>\n", argv[0]); exit(0);}
	
	n = atoi(argv[1]);
	printf("\n For n = %d :\n", n);
	j = findj(n);
	printf("\n  initial string is %d digit long, length is %d\n", s0, j);
}
	
		
	
