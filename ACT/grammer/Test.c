#include<stdio.h>
struct Node
{
int No,Type,Block;
}N[100];
int main()
{
FILE *f;
int B,T,i,k=0,loop=0;
f=fopen("graph.txt","r");
for(i=0;fscanf(f,"%d %d %d",&(N+i)->No,&(N+i)->Type,&(N+i)->Block)!=EOF;i++)
{
k++;
printf("%d %d %d\n",N[i].No,N[i].Type,N[i].Block);
}
B=N[0].Block;
T=N[0].Type;
printf("%-4d\n|\n",N[0].No);

i=1;
while(i<k)
{
	while(N[i].Block==B && i<k && N[i].Type==T && B!=0)
	{
	printf("%-4d ",N[i].No);
	i++;
	}
	printf("\n|\n%-4d     ",N[i].No);
	B=N[i].Block;
	T=N[i].Type;
	i++;

}
printf("\n");
fclose(f);
}
