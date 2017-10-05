#include<stdio.h>
struct Node
{
int No,Type,Block;
}N[100];
int main()
{
FILE *f;
int B,T,i,k=0,loop=0,count=0,currentblock,elseblockno,temp;
f=fopen("graph.txt","r");
for(i=0;fscanf(f,"%d %d %d",&(N+i)->No,&(N+i)->Type,&(N+i)->Block)!=EOF;i++)
{
k++;
printf("%d %d %d\n",N[i].No,N[i].Type,N[i].Block);
}
B=N[0].Block;
T=N[0].Type;
printf("%-4d\n|\n",N[0].No);
count=1;
i=1;
loop=1;
while(i<k)
{
	if(N[i].Type > 1 ){
		loop = N[i-1].No;
	}
	count=1;
	while(N[i].Block==B && i<k && N[i].Type==T && B!=0)
	{
		count++;
		printf("=====>%d ",N[i].No);
		B=N[i].Block;
		T=N[i].Type;
		i++;
	}
	if(count>1)
		printf("-->%-4d \n",loop);
	loop = N[i-1].No;
	printf("\n|\n%-4d     ",N[i].No);
	
	B=N[i].Block;
	T=N[i].Type;
	i++;
}
printf("\n");
fclose(f);
}
