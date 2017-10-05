	#include<stdio.h>
	#include<conio.h>

	int main()
	{
		int iEncKey;
		char chArPlain[80],chTemp;
		FILE * fpPlain , * fpCipher;

		clrscr();
		printf("\n\n\t :::CEASER CIPHER ENCRYPTION DECRYPTION:::");

		printf("\n\n\t Enter a string to Encrypt:");
		gets(chArPlain);
		fpPlain = fopen("d:\\ANKIT\\CNS\\PRGS\\plain.txt","w");
		fprintf(fpPlain,"%s",chArPlain);

		printf("\n\n\t Enter a key for Encrypting the plainText:");
		scanf("%d",&iEncKey);

		fclose(fpPlain);

		fpCipher = fopen("d:\\ANKIT\\CNS\\PRGS\\cipher.txt","w");
		fpPlain = fopen("d:\\ANKIT\\CNS\\PRGS\\plain.txt","r");
		while( (chTemp = getc(fpPlain)) != EOF )
		{
			chTemp = chTemp + iEncKey;
			if( chTemp != putc( chTemp , fpCipher ) )
			{
				printf("\n\n\t can not write to cipher.txt");
				exit(0);
			}

		}
		printf("\n\n\t Your Contents are Enctrypting.");
		delay(700);
		printf(".");
		delay(700);
		printf(".");
		printf("\n\n\t Enctypted Successfully.");

		fclose(fpPlain);
		fclose(fpCipher);


		return 0;
	}