#include	<stdio.h>
#include	<stdlib.h>

//Pizza App.
int main(void) {
	int userExit = 0;
	int choice = 0;
	int size = 0;
	//Check if user wants to exit the program.
	do {
		//Collects type of pizza.
		//What happens when you enter an invalid option?
		do {
			//Prompts for menu screen:
			//Clears the screen prior to calling. From <stdlib.h>.
			system("cls");
			printf("Welcome to Pizza App:\n");
			printf("Choose a pizza below:\n");
			printf("(1): Pineapple & Ham\n");
			printf("(2): Pepperoni\n");
			printf("(3): WSU Cheese\n");
			printf("(4): Veggie Haters\n");

			//Collect user input:
			scanf("%d", &choice);
		} while (choice < 1 || choice > 4);

		//Collects size of pizza.
		do {
			//Prompts for menu screen:
			system("cls");
			printf("Choose a size below:\n");
			printf("(1) Small\n");
			printf("(2) Medium\n");
			printf("(3) Gigantic\n");
			scanf("%d", &size);
		} while (size < 1 || size > 3);

		//Determines which price to print based on the size the user chose above.
		switch (size) {
		case 1:
			printf("Price: $600\n");
			break;
		case 2:
			printf("Price: $20000000000000000000000000000\n");
			break;
		case 3:
			printf("Price: $0.01\n");
			break;
		default:
			printf("Something went wrong!\n");
			break;
		}

		//Exit prompt (not needed but useful.)
		printf("\nDo you want to leave?\n");
		scanf("%d", &userExit);
		if (userExit == 0) {
			printf("Are you sure??????? No more PIZZA?\n");
			scanf("%d", &userExit);
		}

	} while (userExit != 0);

	exit(0);

	return 0;
}
