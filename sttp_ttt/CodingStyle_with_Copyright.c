/******************************************************************************
 * Copyright (c) 2004 eInfochips - All rights reserved.
 *
 * This software is authored by eInfochips and is eInfochips' intellectual
 * property, including the copyrights in all countries in the world.
 * This software is provided under a license to use only with all other rights,
 * including ownership rights, being retained by eInfochips. 
 *
 * This file may not be distributed, copied, or reproduced in any manner,
 * electronic or otherwise, without the written consent of eInfochips. 
 *****************************************************************************/


/******************************************************************************
 *
 * File Name:  	CodingStyle.c
 *
 * Description:	This file is a template file to depict how to do commenting in 
 *		source code file. Please note comment length/line should not
 *		exceed beyond column 80.
 * History:		
 * 	AUG/21/2004, MGP,	Some Changes done to the file.Date and Initials
 *				are seperated by one space while name and 
 *				history details	are seperated by one 
 *				tab/sychronized as shown here.History details 
 *				start with latest first.
 *	AUG/18/2004, MGP,	Created file for Coding standard guidelines.		
 *
 ******************************************************************************/


/****************
 * Include Files
 ****************/
#include <stdio.h>	    /* Observe one space in between include and '<'*/
#include "mydir/myfile.h"   /* Try to indent comment with one tab at the start*/
 	
 	
 				
 				
/*********************************
 * Defines and Macros and globals
 *********************************/
Int32	giNumberOfTries;   /* To keep track of number of tries upon failure*/
		
		
		
/*********************
 * Typedefs and Enums
 *********************/
typedef bool	STATUS;
	
	
	
/************************
 * Function declarations
 ************************/								
void	SomeFunc(int, void *);	/* Try to explain in single line, what is the
 				   purpose of this function. */
char *	GetString(short);
 									
/* This variable will store number of active channels. (I.e. try to give idea 
   about what this global variable will be used for) 
*/

int	iNumberOfChannels;	
    
/* Use following for as prefix in variable name declaration:
	'i' for int
	'ch' for char
	'bt' for byte
	'sh' for short
	'b' for boolean
	'ptr' for pointer
	'v' for void
	'd' for double
	'l' for long
	'w' for WORD
	'dw' for DWORD
	'ref' for reference variable in C++ 
*/				    				   
int	iCounter;		
 				   
/* As a note: Try to use BYTE, WORD, DWORD instead of char, int, long, 
   signed,unsigned, etc. This will help while porting from one 
   platform to another 
*/
   
void *	vpToAnything;  /* 	Look at the variable name declarations,now*/

/*******************************************************************************
 * 
 * Function:	SomeFunction  
 *
 * Description:	Function description would be mentioned here.
 *
 * Parameters:	int iCount - Explain what this parameter is meant for function
 *		void * pIndex- Explain what this pointer is meant for function
 *
 * Return Value:	int - Explain what will be the value on this integer.
 *			If the return value is bool then true/false condition
 *			Do not mention return value as bool or int but indicate
 *			its value like no.of active connections or status.
 ******************************************************************************/
int SomeFunc(int iCount, void * vpOK)
{
	int	iLocalVar;	/* Indent variable names */
	int	iIndex;		/* Used as a counter in loop. */
	char 	chIsOK;		/* Also make sure that your comments for local 
				   variable are also indented like this. */
	
	/*
	Explain logic if the following block of code is going to do some heavy
	work. Also, pls. make sure that this comment goes in SYNCHRONIZATION
	with whatever is written in 'Description' in function header. Also,
	pls. note the commenting style used.
	*/
	
	for ( int iIndex = 0; iIndex < iCount; iIndex ++ )
	{
		if( iIndex == 5 )
		{
			...
		}
	}

	/*
	Look at the indentation. Open / close braces ('{' / '}') are indented
	at the same column where 'f' of 'for' starts and 'i' of 'if' starts.
	This is TRUE for all block structures. This improves readability.
	Look at below:
	*/
	
	do
	{
	}
	while ();
	
	while ()
	{
	}
	
	switch(x)
	{
		case
		{
		}
		break;
		case
		{
		}
		break;
		default:
		{
		}
		break;
	}
	
	/*
	Now is the turn of spacing...
	Look at following...
	*/
	for ( iIndex = 0; iIndex < iTotal; iIndex ++ )
	...
	if (	bIsOK == TRUE 	&&
		iIndex < iTotal &&
		you > me )
	{
		...
	}
	while ( *ipYear < 2005 )
	{
		...
	}
	/*
	Carefully notice the spaces used in 'for', 'if' and 'while' statements.
	also, pls. note that multiple conditions in 'if' statement are indented
	*/
}

/*******************************************************************************
 * 
 * Function:		OtherFunction  
 *
 * Description:		Function description ...
 *
 * Parameters:		None
 *
 * Return Value:	None
 ******************************************************************************/
void OtherFunction(void)
{
  
/*
	When function doesn't take any paramter or doesn't return any value, mention
	so in the comment. Don't leave it blank.
	Source code should start AND end with copyright notice.
*/
	
}

/******************************************************************************
 * Copyright (c) 2004 eInfochips - All rights reserved.
 *
 * This software is authored by eInfochips and is eInfochips' intellectual
 * property, including the copyrights in all countries in the world.
 * This software is provided under a license to use only with all other rights,
 * including ownership rights, being retained by eInfochips. 
 *
 * This file may not be distributed, copied, or reproduced in any manner,
 * electronic or otherwise, without the written consent of eInfochips. 
 *****************************************************************************/
