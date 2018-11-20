/*This file plays a game with the user that asks them ten multiplication questions, and then returns to them the
 *percentage of correct answers they attained.
 *It generates the numbers by using the built in rand funciton.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int
main(void)
{
		//Just initializing variables
	int counter=0;

	int answer; 
	int correct=0;

		//Seeding random numbers
	srand ((int) time (NULL));
		//Traversal loop, but really the core of the program
	for(counter=0;counter<10;counter++)
	{
		int rand1 = rand()%13;
		int rand2 = rand()%13;
		printf("Multiply %d and %d.\n", rand1,rand2);
		scanf("%d", &answer);
			//this if-else loop allows determines the responeses andgives the program the ability to keep track of the answers provided by the user
		if(rand1*rand2==answer)
		{
			correct++;
			printf("nice job!!!\n");
		}
		else
		{
		printf("Nope! The correct answer is %d\n", rand1*rand2);
		}	
	}	
	printf("Cool! You got %d percent of questions correct!!\n", correct*10);
	return 0;

}
