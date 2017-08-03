#include "PizzaHeader.h"

// Main Menu:
// Decides which pizza to make (vegan or standard)
// then prints the result to the screen.
void menu() {
	// Here we dynamically allocate memory for a Pizza* struct.
	Pizza* myPizza = (Pizza*)malloc(sizeof(Pizza));
	// If we wanted more than one Pizza*, we would do this: malloc(size * sizeof(Pizza))

	// We must initialize the arrays of myPlants and myMeats after malloc().
	for (int i = 0; i < 8; i++, myPizza->myPlants[i] = NULLM);
	for (int j = 0; j < 7; j++, myPizza->myMeats[j] = NULLP);
	// malloc() does NOT initialize the indirect values of pointers.

	// Here we ask the user if they want a vegan or regular pizza,
	// and set the 'isVegan' field accordingly:
	printf("Do you want a vegan pizza? Enter Yes or No:\n");
	char choice[10] = { 0 };
	scanf("%s", choice);
	if (choice[0] == 'Y' || choice[0] == 'y')
		myPizza->isVegan = TrueVeg;
	else
		myPizza->isVegan = FalseVeg;
	system("cls");

	// We then pass myPizza* into vegPizza() or stdPizza(),
	// which allow the user to set up their pizza:
	if (myPizza->isVegan)
		vegPizza(myPizza);
	else
		stdPizza(myPizza);

	printPizza(myPizza);

	// After calling printPizza(), we free() the memory of Pizza* struct,
	// which we allocated earlier.
	if (myPizza) {
		free(myPizza);
		// It is good practice to set your pointers equal to NULL after freeing them.
		myPizza = NULL;
	}
	// Every pointer that is mallocated must be freed.
}

// Vegan Pizza Menu:
// Sets sauce to marinara, cheese to false,
// and lets the user choose the size, crust, and plants.
void vegPizza(Pizza* veganPizza) {

	veganPizza->thisSauce = marinara;
	veganPizza->hasCheese = False;
	int plantAmount = 0;

	// Lets the user set the size and crust of their Pizza* struct.
	setSize(veganPizza);
	setCrust(veganPizza);

	// Since this is a vegan pizza, we can set myMeats to NULLM.
	veganPizza->myMeats[0] = NULLM;

	// Here we determine how many vegetables the user wants on their pizza:
	do {
		printf("How many plants would you like on your pizza?\n");
		scanf("%d", &plantAmount);
	} while (plantAmount < 0 || plantAmount > 8);

	// This loops stores each plant in the Plants[] field.
	for (int index = 0; index < plantAmount; index++) {
		Plants newPlant;
		setPlants(&newPlant);
		veganPizza->myPlants[index] = newPlant;
	}

	// This allows us to pinpoint the last element of Plants[].
	veganPizza->myPlants[plantAmount] = NULLP;
}

// Regular Pizza Menu:
// Lets the user choose cheese, size, crust, vegetables, and meats.
void stdPizza(Pizza* realPizza) {

	// To cheese or not to cheese:
	char choice[10] = { 0 };
	printf("Would you like cheese on your pizza?\n");
	scanf("%s", choice);
	if (choice[0] == 'Y' || choice[0] == 'y')
		realPizza->hasCheese = True;
	else
		realPizza->hasCheese = False;

	// Sets the size, crust, and sause of the Pizza* struct we passed in.
	setSize(realPizza);
	setCrust(realPizza);
	setSauce(realPizza);

	int plantAmount = 0;
	int meatAmount = 0;

	// Plants

	// Determines how many and what kind of vegetables the user wants:
	do {
		printf("How many plants would you like on your pizza?\n");
		scanf("%d", &plantAmount);
	} while (plantAmount < 0 || plantAmount > 8);

	for (int index = 0; index < plantAmount; index++) {
		Plants newPlant;
		setPlants(&newPlant);
		realPizza->myPlants[index] = newPlant;
	}

	// Must set the last element of myPlants to NULLP!
	realPizza->myPlants[plantAmount] = NULLP;

	// Meats

	// Determines how many and what kind of meats the user wants.
	do {
		printf("How many meats would you like on your pizza?\n");
		scanf("%d", &meatAmount);
	} while (meatAmount < 0 || meatAmount > 7);

	for (int index = 0; index < meatAmount; index++) {
		Meats newMeats;
		setMeats(&newMeats);
		realPizza->myMeats[index] = newMeats;
	}

	// Must set the last element of myMeats to NULLM!
	realPizza->myMeats[meatAmount] = NULLM;
}

// Sets the size of the pizza based on user input.
void setSize(Pizza* myPizza) {
	int valid = 1;

	do {
		valid = 1;
		printf("What size would you like your pizza to be? Enter Small, Medium, or Large\n");
		char size[15] = { 0 };
		scanf("%s", size);
		if (size[0] == 'S' || size[0] == 's')
			myPizza->thisSize = small;
		else if (size[0] == 'M' || size[0] == 'm')
			myPizza->thisSize = medium;
		else if (size[0] == 'L' || size[0] == 'l')
			myPizza->thisSize = large;
		else {
			valid = 0;
			system("cls");
		}
	} while (valid == 0);
	system("cls");
}

// Sets the crust of the pizza based on user input.
void setCrust(Pizza* myPizza) {
	int valid = 1;

	do {
		valid = 1;
		printf("What crust would you like on your pizza? Enter Hand, Pan, Thin, Deep\n");
		char crust[15] = { 0 };
		scanf("%s", crust);
		if (crust[0] == 'H' || crust[0] == 'h')
			myPizza->thisCrust = hand;
		else if (crust[0] == 'P' || crust[0] == 'p')
			myPizza->thisCrust = pan;
		else if (crust[0] == 'T' || crust[0] == 't')
			myPizza->thisCrust = thin;
		else if (crust[0] == 'D' || crust[0] == 'd')
			myPizza->thisCrust = deep;
		else {
			valid = 0;
			system("cls");
		}
	} while (valid == 0);
	system("cls");
}

// Sets the vegetables of the pizza based on user input.
void setPlants(Plants* myPlant) {
	int valid = 1;

	do {
		valid = 1;
		printf("Which plants would you like on your pizza?\nEnter Jalepenos, Pineapple, Tomato, Peppers, Onions, Shrooms, Olives.\nThis is case-sensitive:\n");
		char plant[25] = { 0 };
		scanf("%s", plant);
		if (plant[0] == 'J' || plant[0] == 'j')
			*myPlant = jalepenos;
		else if (plant[0] == 'P' && plant[1] == 'i')
			*myPlant = pineapple;
		else if (plant[0] == 'T' || plant[0] == 't')
			*myPlant = tomato;
		else if (plant[0] == 'P' || plant[0] == 'p')
			*myPlant = peppers;
		else if (plant[0] == 'O' && plant[1] == 'n')
			*myPlant = onions;
		else if (plant[0] == 'S' || plant[0] == 's')
			*myPlant = shrooms;
		else if (plant[0] == 'O' || plant[0] == 'o')
			*myPlant = olives;
		else {
			valid = 0;
			system("cls");
		}
	} while (valid == 0);
	system("cls");
}

// Sets the sauce of the pizza based on user input.
void setSauce(Pizza* myPizza) {
	int valid = 1;
	do {
		valid = 1;
		char sauce[25] = { 0 };
		printf("Which sauce would you like on your pizza?\nEnter Marinara, Alfredo, Parmesan, Buffalo\n");
		scanf("%s", sauce);
		if (sauce[0] == 'M' || sauce[0] == 'm')
			myPizza->thisSauce = marinara;
		else if (sauce[0] == 'A' || sauce[0] == 'a')
			myPizza->thisSauce = alfredo;
		else if (sauce[0] == 'P' || sauce[0] == 'p')
			myPizza->thisSauce = parmesan;
		else if (sauce[0] == 'B' || sauce[0] == 'b')
			myPizza->thisSauce = buffalo;
		else {
			valid = 0;
			system("cls");
		}
	} while (valid == 0);
	system("cls");
}

// Sets the meats of the pizza based on user input.
void setMeats(Meats* myMeat) {
	int valid = 1;

	do {
		valid = 1;
		char meat[25] = { 0 };
		printf("Which meats would you like on your pizza?\nEnter: Pepperoni, Bacon, Beef, Chicken, Ham, Sausage\nThis is case-sensitive:\n");
		scanf("%s", meat);
		if (meat[0] == 'P' || meat[0] == 'p')
			*myMeat = pepperoni;
		else if (meat[0] == 'B' && meat[1] == 'a')
			*myMeat = bacon;
		else if (meat[0] == 'B' || meat[0] == 'b')
			*myMeat = beef;
		else if (meat[0] == 'C' || meat[0] == 'c')
			*myMeat = chicken;
		else if (meat[0] == 'H' || meat[0] == 'h')
			*myMeat = ham;
		else if (meat[0] == 'S' || meat[0] == 's')
			*myMeat = sausage;
		else {
			valid = 0;
			system("cls");
		}
	} while (valid == 0);

	system("cls");
}

// These arrays of string allow us to print the value of each field in our Pizza* struct:

const char* sauceNames[4] = { "Marinara", "Alfredo", "Parmesan", "Buffalo" };

const char* sizeNames[3] = { "Small", "Medium", "Large" };

const char* plantNames[7] = { "Jalepenos", "Pineapple", "Tomato", "Peppers", "Onions", "Shrooms", "Olives" };

const char* meatNames[6] = { "Pepperoni", "Bacon", "Beef", "Chicken", "Ham", "Sausage" };

const char* crustNames[4] = { "Hand", "Pan", "Thin", "Deep" };

const char* boolNames[2] = { "No", "Yes" };

// This function prints the contents of a Pizza* struct.
void printPizza(Pizza* myPizza) {
	// Prints isVegan, Sauce, Size, Crust, and HasCheese of the user's pizza:
	printf("IsVegan: %s\n", boolNames[myPizza->isVegan]);
	printf("Sauce: %s\n", sauceNames[myPizza->thisSauce]);
	printf("Size: %s\n", sizeNames[myPizza->thisSize]);
	printf("Crust: %s\n", crustNames[myPizza->thisCrust]);
	printf("HasCheese: %s\n", boolNames[myPizza->hasCheese]);

	// Prints the meats of the pizza:
	printf("Meats: ");
	int meatIndex = 0;
	if (myPizza->myMeats) {
		// Notice the condition of this loop (run until we find NULLM).
		for (; myPizza->myMeats[meatIndex] != NULLM; meatIndex++)
			printf("%s ", meatNames[myPizza->myMeats[meatIndex]]);
	}
	printf("\n");

	// Prints the vegetables of the pizza:
	printf("Plants: ");
	int plantIndex = 0;
	if (myPizza->myPlants) {
		for (; myPizza->myPlants[plantIndex] != NULLP; plantIndex++)
			printf("%s ", plantNames[myPizza->myPlants[plantIndex]]);
	}
	printf("\n");
}

// Extra Credit (3 pts.)
// This function dynamically allocates memory for an 'array' of
// Pizza* structs (i.e. **myPizza), and performs the same operations
// found in menu() for each Pizza* in the array.
// You MUST free each element in the array and the array itself at the very end.
// Turn in a .txt file with this function only, along with appropriate indentation.
// WARNING: You must initialize each myPlants[] and myMeats[] to NULLP and NULLM respectively.
//			Make this into a helper function?
void multipleMenus(const int size)
{
	// This is good practice for the lab final!
}