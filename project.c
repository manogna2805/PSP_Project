#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int changeprize(int);
void booking(int *,int,int );
int choice1(void);
void cancel(int *);       
void ticket1(int choice,char name[10],int id1,int price);
void ticket2(int choice,char name[10],int id1,int price);
void ticket3(int choice,char name[10],int id1,int price);
int cmovie(void);
int movie(void);
void details(void);
struct moviedetails
{
	char name[25];
	char phone[15];
	int seat;
	int id;
};
struct moviedetails person[300];
int count=0;
int id1=100;
int main()
{
	int **seat,choice,price=250,selection,i;
	seat=(int **)calloc(101,sizeof(int *));
	for (i=0;i<3;i++)
		*(seat+i)=(int *)calloc(101,sizeof(int ));
	int x;
	while(x!=5)
	{
		choice=choice1();
		switch(choice)
		{
			case 1:
				price=changeprize(price);
				break;
			case 2:
				details();
				break;	
			case 3:	
				selection=movie();
				booking(seat[selection-1],price,selection);	
				count++;
				break;
			case 4:
				selection=cmovie();	
				cancel(seat[selection-1]);
				break;
			case 5:
				x=5;
				break;
			default: 
				printf("Choice not available\n");
				break;	
		}
	}
}
int changeprize(int prize)
{
	char pass[10],pak[10]="pass";
	printf("Enter the admin password: ");
	scanf("%s",&pass);
	if (strcmp(pass,pak)==0)
	{
		printf("Please enter new price:");
		scanf("%d",&prize);
		printf("New ticket prize is %d\n",prize);
	}
	else 
		printf("The entered password is wrong!");
	return prize;
}
void booking(int *array,int price,int selection)
{          
		FILE *f1;
		int i,j;
		printf("\n                                SCREEN\n\n\n");
		for (i=1;i<=100;i++)
		{
			if (array[i]==0)
				printf("%d\t",i);
			else 
				printf("\t",i);	
			if(i%10==0)
				printf("\n\n");
		}
		f1=fopen("file1.txt","w");
		printf("Please enter your name:");
		while(fscanf(stdin,"%s",&person[count].name)!=EOF)
			fprintf(f1,"%s",person[count].name);
		printf("Which seat number you want?:");
		while(fscanf(stdin,"%d",&j)!=EOF)
			fprintf(f1,"%d",j);
		fclose(f1);
		if(j>100||j<1)
		{
			printf("The seat you have selected is unavailable in this theater\n");
			printf("Please re-enter seat number: ");
			scanf("%d",&j);
		}
		if(array[j]==1)
		{
			printf("Sorry, this ticket is already booked! Please choose another seat.\n");
			scanf("%d",&j);
		}
		else			
			array[j]=1;
		person[count].seat=j;
		if(selection==1)
			ticket1(j,person[count].name,id1,price);
		else if(selection==2) 	
			ticket2(j,person[count].name,id1,price);
		else 
			ticket3(j,person[count].name,id1,price);			
		id1++;	
}
int choice1(void)
{
	int choice;
	printf("                 Simple Movie Ticket Booking System\n");
	printf("====================================================================\n");
	printf("||             1- To edit  ticket price:                          ||\n");
	printf("||             2- To view booked tickets:                         ||\n");
	printf("||             3- To book ticket:                                 ||\n");
	printf("||             4- To cancel ticket:                               ||\n");
	printf("||             5- Exit system:                                    ||\n");
	printf("||================================================================||\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	return choice;
}
void cancel(int *array)
{
      int Cseat,i,temp=0;
	  printf("Please enter ID number of ticket: ");
	  scanf("%d",&Cseat);
	  for(i=0;i<300;i++)
	  {
	  		if(Cseat==person[i].id)
	  		{
					 temp=2;
					 printf("%s your seat is %d cancelled\n",person[i].name,person[i].seat);
					 array[person[i].seat]=0;
					 i=300;
	  		}
	  }
	  if(temp!=2)	
	  		printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
}
void ticket1(int choice,char name[10],int id1,int price)
{
		FILE *f1;
		printf("\n\n");
       	printf("\n-------------------THEATER BOOKING TICKET-------------------\n");
       	printf("\t============================================================\n");
       	printf("\tBooking ID : %d \t\t\tMovie Name : Dasara\n",id1);
       	f1=fopen("file1.txt","r");
       	while(fscanf(f1,"%s%d",name,choice)!=EOF)
    	   	fprintf(stdout,"\tCustomer  : %s\n",name);
        printf("\t\t\t                              Date      : Thu,03-06-2023\n");
       	printf("\t                                              Time      : 06:00pm\n");
       	printf("\tTelugu,2D                                     Screen    : 01\n");
        	fprintf(stdout,"\tAsian Sridevi Multiplex,                      Seat No   : GOLD,%d  \n",choice);
        fclose(f1);
		printf("\tHanumakonda                                   Price     : %d  \n\n",price);
		person[count].id=id1;
       	printf("\t============================================================\n");
        return;
}
void details(void)
{
	int i;
	char pass[10],pak[10]="pass";
	printf("Enter the admin password to see details: ");
	scanf("%s",&pass);
	if(strcmp(pass,pak)==0)
	{
		for(i=0;i<count;i++)
		{
			printf("seat no: %d is booked by %s booking id is %d\n",person[i].seat,person[i].name,person[i].id);
		}
	}
	else                                                 
		printf("Entered password is wrong \n");
	
}             
int movie(void)
{
	int i;
	printf("\t\t\twhich movie you want to see?\n");
	printf("\t\t\t----------------------------\n\n");
	printf("\t\t\tpress 1 for Dasara\n\n");
	printf("\t\t\tpress 2 for Balagam\n\n");
	printf("\t\t\tpress 3 for Virupaksha\n");
	scanf("%d",&i);
	return i;
}
void ticket2(int choice,char name[10],int id1,int price)
{
	FILE *f1;
		printf("\n\n");
        printf("\t-------------------THEATER BOOKING TICKET-------------------\n");
        printf("\t============================================================\n");
        printf("\tBooking ID : %d \t\t\tMovie Name : Balagam\n",id1);
        f1=fopen("file1.txt","r");
       	while(fscanf(f1,"%s%d",name,choice)!=EOF)
    	   	fprintf(stdout,"\tCustomer  : %s\n",name);
        printf("\t\t\t                              Date      : Thu,04-05-2023\n");
        printf("\t                                              Time      : 06:00pm\n");
        printf("\tTelugu,2D                                     Screen    : 02\n");
        	fprintf(stdout,"\tAsian Sridevi Multiplex,                      Seat No   : GOLD,%d  \n",choice);
        fclose(f1);
        printf("\tHanumakonda                                   Price     : %d  \n\n",price);
        person[count].id=id1;
        printf("\t============================================================\n");
        return;
}
int cmovie(void)
{
	int i;
	printf("\t\t\twhich movie ticket you want to cancel\n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\tpress 1 DASARA\n\n");
	printf("\t\t\tpress 2 BALAGAM\n\n");
	printf("\t\t\tpress 3 VIRUPAKSHA\n");
	scanf("%d",&i);
	return i;		
}
void ticket3(int choice,char name[10],int id1,int price)
{
		FILE *f1;
		printf("\n\n");
        printf("\t-------------------THEATER BOOKING TICKET-------------------\n");
        printf("\t============================================================\n");
        printf("\tBooking ID : %d \t\t\tMovie Name : Virupaksha \n",id1);
        f1=fopen("file1.txt","w");
       	while(fscanf(f1,"%s%d",name,choice)!=EOF)
    	   	fprintf(stdout,"\tCustomer  : %s\n",name);
        printf("\t\t\t                              Date      : Thu,04-05-2023\n");
        printf("\t                                              Time      : 06:00pm\n");
        printf("\tTelugu,2D                                     Screen    : 03\n");
        	fprintf(stdout,"\tAsian Sridevi Multiplex,                      Seat No   : GOLD,%d  \n",choice);
        fclose(f1);
        printf("\tHanumakonda                                   Price     : %d  \n\n",price);
        person[count].id=id1;
        printf("\t============================================================\n");
        return;
}