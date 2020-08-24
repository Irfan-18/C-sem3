
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
char name[];
float charges
float fare;
char name[50];
int source,dest;
int num_of_seats;
int a[][3]={{1,1,0},{1,2,5},{1,3,5},{1,4,5},{1,5,5},{1,6,5},{1,7,5},{1,8,5},{1,9,10},
            {2,1,0},{2,2,0},{2,3,5},{2,4,5},{2,5,5},{2,6,5},{2,7,5},{2,8,5},{2,9,5},
            {3,1,0},{3,2,5},{3,3,0},{3,4,5},{3,5,5},{3,6,5},{3,7,5},{3,8,5},{3,9,5},
            {4,1,0},{4,2,5},{4,3,5},{4,4,0},{4,5,5},{4,6,5},{4,7,5},{4,8,5},{4,9,5},
            {5,1,0},{5,2,5},{5,3,5},{5,4,5},{5,5,0},{5,6,5},{5,7,5},{5,8,5},{5,9,5},
            {6,1,0},{6,2,5},{6,3,5},{6,4,5},{6,5,5},{6,6,0},{6,7,5},{6,8,5},{6,9,5},
            {7,1,0},{7,2,5},{7,3,5},{7,4,5},{7,5,5},{7,6,5},{7,7,0},{7,8,5},{7,9,5},
            {8,1,0},{8,2,5},{8,3,5},{8,4,5},{8,5,5},{8,6,5},{8,7,5},{8,8,0},{8,9,5},
            {9,1,10},{9,2,5},{9,3,5},{9,4,5},{9,5,5},{9,6,5},{9,7,5},{9,8,5},{9,9,0}};
void reservation();
void viewroute();
void printticket();	
int charge();
void login();

int main()

{
	int menu_choice,choice_return;
	login();

	start:
       	system("cls");
	printf("\n=================================\n");
	printf("    TRAIN RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1>> Reserve A Ticket");
	printf("\n------------------------");
	printf("\n2>> View All Available Routes");
	printf("\n------------------------");
	printf("\n3>> Print Your Ticket");
	printf("\n------------------------");
	printf("\n4>> Exit");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();		//Fucntion still not added
			break;
		case 2:
			viewroute();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3: 
                        printticket();
			break;
   
		case 4:
			break;
		default:
			printf("\nInvalid choice");
	}
	goto start;
   return 0;
}

void viewroute()
{
    	system("cls");
	printf("-----------------------------------------------------------------------------");
	printf("\nSR.NO.\tSOURCE\t\t\t\tSR.NO.\tDESTINATION\t\t\t\t");
	printf("-----------------------------------------------------------------------------");
	printf("\n1\tDadar\t\t\t\t1.\tDadar\t\t\t\t");
	printf("\n2\tPrabhadevi\t\t\t\t2.\tPrabhadevi\t\t\t\t");
	printf("\n3\tLower Parel\t\t\t\t3.\tLower Parel\t\t\t\t");
	printf("\n4\tMahalaxmi\t\t\t\t4.\tMahalaxmi\t\t\t\t");
	printf("\n5\tMumbai Central\t\t\t\t5.\tMumbai Central\t\t\t\t");
	printf("\n6\tGrant Road\t\t\t\t6.\tGrant Road\t\t\t\t");
	printf("\n7\tCharni Road\t\t\t\t7.\tCharni Road\t\t\t\t");
	printf("\n8\tMarine Lines\t\t\t\t8.\tMarine Lines\t\t\t\t");
	printf("\n9\tChurchgate\t\t\t\t9.\tChurchgate\t\t\t\t");
}

void reservation()
{
	char confirm;
	float charges;

	printf("\nEnter Your Name:> ");
	gets(name);
	printf("\nEnter Number of seats:> ");
	scanf("%d",&num_of_seats);
       	system("cls");
	viewroute();
        start1:
	printf("\n\nEnter source code: ");
	scanf("%d",&source);
	printf("\n\nEnter destination code: ");
        scanf("%d",&dest);
	if(source>=1 && dest<=9)
	charges=charge();
	else
	{printf("\nInvalid Code! Enter again--> ");
	 goto start1;}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		printf("%s\t\t%d\t\t%d\t\t%.2f\n",name,num_of_seats,source,dest,charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	getch();
}



float charge()
{   int i,fares;
    for(i=0;i<9;i++)
    {
        if (a[i][0]=source&&a[i][1]=dest)
            fares=a[i][2];
    }    
	  return fares;
}


void printticket()
{
       	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nSource:\t\t%d",source);
	printf("\nDestination:\t\t%d",dest);

	printf("\nCharges:\t\t%.2f",charges);
}


void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
  do
    {
    printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
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
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
	if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	  printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	  printf("\n\n\n\t\t\t\tPress any key to continue...");
	  getch();//holds the screen
	  break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen
	 	system("cls");
	}
    }while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
	       	exit(1);
		getch();

        }
	  	system("cls");
}



