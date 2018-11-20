#include <string.h>
#include <stdio.h>
#define SIZE 10
#define LENGTH 20

char names[SIZE][LENGTH];
int party_size[SIZE];
int reservations=0;
void schedule(void);
void seat(void);
void list(void);

int
main(void)
{
	int k;
        for(k=0;k<SIZE;k++)
        {
            names[k][0]='\0';
        }
  while(1)        //this makes sure that we return to the interface after each iteration
        {
               int  command=0;      //this just resets the command value so that the user doesn't send the program into an infinite loop
 printf("What would you like to do?\n (1) Make a reservation\n (2) Seat someone\n (3) List today's reservations\n or literally ANYTHING ELSE TO QUIT\n");
                scanf("%d", &command);

                switch(command)
                {
                        case 1://this is the "shedule" function
                        {
                                schedule();
                                break;
                        }
 			case 2://this is the cancel function
                        {
                               seat();
                               break;
                        }
                        case 3://this is the list function
                        {
                                list();
                                break;
                        }
                        default:
                                printf("Good bye and good day sir and/or madame.\n");
                                return 1;
                }
        }
}

void
schedule(void)//this function allows the user to schedule an appointment
{

        if(reservations==SIZE)
        {
                printf("There's nothing open at this time. Try again later.\n");
                return;
        }

        char temp[LENGTH];
        int j=0;
        printf("What is your name?\n");
        scanf("%s", temp);
        for(j=0;j<SIZE;j++)//this is how we check against all of the existing names
        {
                if(strcmp(names[j],temp)==0)
                {
                        printf("That name is already input, please try again\n");
                        return;
                }
        }
        strcpy(names[reservations],temp);
	printf("How many are we expecting?\n");
	scanf("%d", &party_size[reservations]);
        printf("%s, your reservation %d is set!\n", names[reservations], party_size[reservations]);
        reservations++;
        return;
}
void
seat(void) //this is the code for the cancel function
{
	int i=0;
	int tablesize;
	int j=0;
	int closest;
        printf("Enter number of seats at the open table please\n");
        scanf("%d", &tablesize);
	int diff=tablesize;
        for(i=0;i<SIZE;i++)
        {
		if(tablesize - party_size[i]>0 && tablesize - party_size[i]<diff)//this checks the entered size against all of the existing parties to find the closest match
                {
			closest=i;
			diff= tablesize - party_size[i];
		}
		if(tablesize-party_size[i]==0)//this says that if there is a party whose exactly matches the table size, then they will be put at the table.
		{		
			closest=i;
			diff=0;
			break;
		}
	}
	if(i==SIZE && diff==tablesize)
	{
		printf("That's not a big enough table.\n");
		return;
	}
	else
	{
		printf("The %s party for %d should be seated now\n", names[closest], party_size[closest]);
		for(j=closest+1;j<SIZE;j++)//this is how the names shift up
		{
        	       	strncpy(names[j-1],names[j],LENGTH);
			party_size[j-1]=party_size[j];
       		} 		
        	if(j==SIZE)
        	{
        	        names[reservations-1][0]='\0';
                	reservations--;
        	}
	}
   return;
}



void
list(void) //this is the code for the list function
{
	int i;
	if(reservations==0)
	{
		printf("everthing is free\n");
	}
	for(i=0;i<SIZE;i++)
	{
		if(names[i][0]!='\0')
		{
			printf("The %s party for %d.\n",names[i], party_size[i]);
		}
	}
	printf("Number of reservations remaining: %d\n",SIZE-reservations);
	return;
}
