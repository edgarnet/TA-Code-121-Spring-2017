/*Comment Block*/
/*Name*/
/*Assignment*/
/*Description*/
/*Date*/
/*Contributor(s): Must Include EVERY Classmate You Worked With!!!*/

#include	"Header.h"

int main(void) {
	// Excuse any spelling errors :)

	// This is one way initialize a pointer using a variable's address.
	// If a variable's address is not availible, initialize your pointers
	// as NULL!!!
	int choice = 0;
	int *ptr = NULL;
	ptr = &choice;

	// Here we pass in the address of the variable using the 'address of' operator.
	choosePizza(&choice);
	printf("Choice with address: %d\n", choice);

	// In this case, the pointer whose 'direct' value is an address is passed into the function.
	// Is there a difference between how either method operates?
	choosePizza(ptr);
	// This printf() call uses the 'indirect' value of the pointer.
	printf("Choice with pointer: %d\n", *ptr);

	// This portion determines the size of the pizza.
	int size = 0;
	int *sizePtr = NULL;
	sizePtr = &size;
	chooseSize(sizePtr);
	// This printf() call uses the 'direct' value of the 'size' variable.
	printf("Size: %d\n", size);

	// This portion determines the price of the pizza.
	int price = 0;
	int *pricePtr = NULL;
	pricePtr = &price;
	// Notice: the toppings and the size of the pizza do not need to be changed in the function.
	determinePrice(choice, size, pricePtr);

	// Now we print out the price of the pizza.
	printf("This is the price of your pizza: $%d\n", price);

	// Bonus:
	// Create a function which makes pizzas for n number of customers ('n' is a parameter).
	// Hint: Initialize variables and their pointers within the function, and call the other functions.

	return 0;
}