#include "../function.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include "../unity/unity.h"
#include "../unity/unity_internals.h"
int check;
void logg(){
	TEST_ASSERT_EQUAL(1,check);
}
void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="pass";
    char pass[10]="pass";
	
	do
	{
		printf("\n  =======================  LOGIN FORM  =======================\n  ");
		printf(" \n                       ENTER USERNAME:-");
		scanf("%s", &uname); 
		printf(" \n                       ENTER PASSWORD:-");
		while(i<10)
		{
			pword[i]=getch();
			c=pword[i];
			if(c==13) break;
			else printf("*");
			i++;
		}
		pword[i]='\0';
		i=0;
		if(strcmp(uname,"pass")==0 && strcmp(pword,"pass")==0)
		{
		printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL\n");
		check=1;
		UNITY_BEGIN();
		RUN_TEST(logg);
		UNITY_END();
		printf("\n\n\n\t\t\t\tPress any key to continue...");
		getch();//holds the screen
		break;
		}
		else
		{
			printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL\n");
			check=0;
			a++;
			UNITY_BEGIN();
			RUN_TEST(logg);
			UNITY_END();
			getch();
			system("cls");
		}
	}while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		getch();
	}
	system("cls");	
}
