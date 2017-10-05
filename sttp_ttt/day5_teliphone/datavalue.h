/*
        datavalue.h
        application specific data value declaration
*/
#define SIZE 10
typedef struct datavalue {
        char *name[3];
	char *address;
        int  phone;
	char type;
	char **ph;
} value_t;

value_t NULLVALUE = {"HeadTail", "haed1" , "head2", NULL , 99999 , 'r' , NULL};

void display_value(value_t *p){
	
	char* i;
	int j = p->phone;
	if( p->phone == 99999 )
	{}
	else
	{
	printf("\n\n\tNAME::%s%s%s\n\tAddress::%s\n", 
				p->name[0] , 
				p->name[1] , 
				p->name[2] ,
				p->address);
		
		i = p->ph[0];
		j = p->phone;
		for( j = 0 ; j < p->phone; j++ )
		{
			printf("\tPhone No::%s\n", p->ph[j] );
		}
	}
}

value_t * get_val()
{
	char temp1,temp2;
	int i,ph1;
	value_t *vp;
	vp = (value_t *) malloc(sizeof(value_t));
	vp->name[0]='\0';
	vp->name[1]='\0';
	vp->name[2]='\0';
	vp->address='\0';
	vp->type='\0';
	vp->phone=0;
	
	printf("\n\n\tEnter the phone no.(s) you want to search\n");
	do
        {
	        vp->phone++;
                vp->ph = (char **) malloc(sizeof(char *)*1);
                vp->ph[i] = (char *) malloc(sizeof(char) * SIZE);
                printf("\n\n\tEnter Phone no %d::",i+1);
                scanf("%s%c", vp->ph[i] , &temp1 );
                i++;
                printf("\n\n\tDo u want to add more?? (-999 to exit)");
                scanf("%d%c" , &ph1 , &temp2);
        }while( ph1 != -999 );
	printf("returned");
	return vp;
}

value_t * get_value(){
        value_t *vp;
	int i;
	char temp,temp1,temp2,temp3,temp4,temp5,temp6;
	int ph1;
        vp = (value_t *) malloc(sizeof(value_t));
	
	printf("\n\n\tEnter First Name::");
	vp->name[0] = (char *) malloc(sizeof(char)*SIZE);
	scanf("%s%c", vp->name[0],&temp);
	
	printf("\n\n\tEnter Middle Name::");
	vp->name[1] = (char *) malloc(sizeof(char)*SIZE);
	scanf("%s%c", vp->name[1],&temp1);

	printf("\n\n\tEnter Last Name::");
	vp->name[2] = (char *) malloc(sizeof(char)*SIZE);
	scanf("%s%c", vp->name[2],&temp2);
	
	printf("\n\n\tEnter the Address::");
	vp->address = (char *) malloc(sizeof(char)*SIZE);
	scanf("%s%c", vp->address , &temp3);
	
	
	printf("\n\n\tEnter Phone type::(o/r)::");
	scanf("%c%c", &(vp->type) , &temp5);
	
	i=0;
	vp->phone = 0;
	do
	{
		vp->phone++;
		vp->ph = (char **) malloc(sizeof(char *)*1);
		*(vp->ph)+i = (char *) malloc(sizeof(char) * SIZE);
		printf("\n\n\tEnter Phone no %d::",i+1);
		scanf("%s%c", *vp->ph[i] , &temp4 );
		i++;
		printf("\n\n\tDo u want to add more?? (-999 to exit)");
		scanf("%d%c" , &ph1 , &temp6);
	}while( ph1 != -999 );

        return vp;
}
