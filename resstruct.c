//This is effectively the same thing as the reservation system from before, only this time we use structures to see if the party cacn be reasonably seated.

#include <string.h>
#include <stdio.h>
#define SIZE 10
#define LENGTH 20

struct reservation
{
	char names[LENGTH];
	int party_size;
};
struct reservation parties[SIZE];

int reservations=0;
void schedule(void);
void seat(void);
void list(void);
void eligible(void);

int
main(void)
{
	int k;
        for(k=0;k<SIZE;k++)
        {
            parties[k].names[0]='\0';
        }
  while(1)        //this makes sure that we return to the interface after each iteration
        {
               int  command=0;      //this just resets the command value so that the user doesn't send the program into an infinite loop
 printf("What would you like to do?\n (1) Make a reservation\n (2) Seat someone\n (3) List today's reservations\n (4) See who can be seated at the available table\n or literally ANYTHING ELSE TO QUIT\n");
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
			case 4:
			{
				eligible();
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
	struct reservation *p= parties;
	char temp[LENGTH];
        int j=0;
        printf("What is your name?\n");
        scanf("%s", temp);
        for(j=0;j<SIZE;j++, p++)//this is how we check against all of the existing names
        {
                if(strcmp(p->names,temp)==0)
                {
                        printf("That name is already input, please try again\n");
                        return;
                }
        }
	p=&parties[reservations];
        strcpy(p->names,temp);
	printf("How many are we expecting?\n");
	scanf("%d",&p->party_size);
        printf("%s, your reservation %d is set!\n", p->names, p->party_size);
        reservations++;
        return;
}
void
seat(void) //this is the code for the cancel function
{
	struct reservation *p=parties;
	int i=0;
	int tablesize;
	int j=0;
	int closest;
        printf("Enter number of seats at the open table please\n");
        scanf("%d", &tablesize);
	int diff=tablesize;
        for(i=0;i<SIZE;i++, p++)
        {
		if(tablesize - (p-> party_size) >0 && tablesize -(p-> party_size)<diff)//this checks the entered size against all of the existing parties to find the closest match
                {
			closest=i;
			diff= tablesize - (p->party_size);
		}
		if(tablesize-(p->party_size)==0)//this says that if there is a party whose exactly matches the table size, then they will be put at the table.
		{		
			closest=i;
			diff=0;
			break;
		}
	}
	p=&parties[closest];
	if(i==SIZE && diff==tablesize)
	{
		printf("That's not a big enough table.\n");
		return;
	}
	else
	{
		printf("The %s party for %d should be seated now\n", p->names,p->party_size);
		for(j=closest+1;j<SIZE;j++, p++)//this is how the names shift up
		{
        	       	strcpy(p->names,(p+1)->names);
			p->party_size=(p+1)->party_size;
       		} 		
        	if(j==SIZE)
        	{
        	        p->names[0]='\0';
                	reservations--;
        	}
	}
   return;
}



void
list(void) //this is the code for the list function
{
	struct reservation *p=parties;
	int i;
	if(reservations==0)
	{
		printf("everthing is free\n");
	}
	for(i=0;i<SIZE;i++, p++)
	{
		if(p->names[0]!='\0')
		{
			printf("The %s party for %d.\n",p->names,p->party_size);
		}
	}
	printf("Number of reservations remaining: %d\n",SIZE-reservations);
	return;
}

void
eligible(void)//this function is the "size" function.... im not sure why you want this right now, but i'll assume that it's for a later lab.
{
	int avail;
	struct reservation *p= parties;
	int i;
	printf("table size?\n");
	scanf("%d", &avail);
	for(i=0;i<SIZE;i++, p++)
	{
		if(p->party_size==avail)
		{
			printf("The %s party could be seated\n", p->names);
		}
	}
	return;
}	

