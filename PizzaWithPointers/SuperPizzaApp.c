/*Comment Block*/
/*Name*/
/*Assignment*/
/*Description*/
/*Date*/
/*Contributor(s): Must Include EVERY Classmate You Worked With!!!*/

#include	"Header.h"

// Determines the toppings of the pizza that the customer wants.
// Stores the choice in an integer pointer.
// Notice: the return type is 'Void'.
void choosePizza(int *type) {
	do {
		printf("Welcome to Super Pizza Pickup:\n");
		printf("Choose a pizza below\n");
		printf("(1): Anchovies\n");
		printf("(2): Trash Bin\n");
		printf("(3): Everything But Pineapple\n");
		printf("(4): All Pineapple\n");
		scanf("%d", type);
		system("cls");
	} while (*type < 1 || *type > 4);
}

// Determines the size of the user's pizza.
// Stores the choice in an integer pointer.
void chooseSize(int *type) {
	do {
		printf("Choose a size below:\n");
		printf("(1): Small\n");
		printf("(2): Medium\n");
		printf("(3): Tiny\n");
		scanf("%d", type);
		system("cls");
	} while (*type < 1 || *type > 3);
}

// Determines the price of the pizza based on the previous choices
// for toppings and size, then stores the price in an integer pointer.
// Why are the toppings and size passed as integers and not pointers?
// Would it make a difference otherwise?
void determinePrice(int toppings, int size, int *price) {
	switch (size) {
	case 1:
		*price = 5;
		break;
	case 2:
		*price = 7;
		break;
	case 3:
		*price = 1000000000;
		break;
	}

	switch (toppings) {
	case 1:
		*price += 4;
		break;
	case 2:
		*price -= 10000;
		break;
	case 3:
		*price += 10;
		break;
	case 4:
		*price += 10;
		break;
	}
}