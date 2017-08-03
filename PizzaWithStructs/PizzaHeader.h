#pragma once
#ifndef  _Pizza_Header_H
#define  _Pizza_Header_H
#include <stdio.h>
#include <stdlib.h>

// We stored the various components of a pizza into various enums:

typedef enum sauce {
	marinara, alfredo, parmesan, buffalo
}Sauce;

typedef enum size {
	small, medium, large
}Size;

typedef enum plants {
	jalepenos, pineapple, tomato, peppers, onions, shrooms, olives, NULLP
}Plants;

typedef enum meats {
	pepperoni, bacon, beef, chicken, ham, sausage, NULLM
}Meats;

typedef enum crust {
	hand, pan, thin, deep
}Crust;

typedef enum cheese {
	False, True
}Cheese;

typedef enum vegan {
	FalseVeg, TrueVeg
}Vegan;

// Which are all connected in the struct Pizza below:
typedef struct pizza {
	Vegan isVegan;
	Sauce thisSauce;
	Size thisSize;
	Crust thisCrust;
	// It is seemingly impossible to allocate memory for these structs as pointers,
	// and then free it at a later point.
	// They are now arrays:
	Plants myPlants[8];
	Meats myMeats[7];
	// For those who find a way to malloc() and free() myPlants and myMeats as pointers
	// I may compensate such a feat with an extra point for the previous lab.
	Cheese hasCheese;
}Pizza;


void menu();

void vegPizza(Pizza* veganPizza);

void stdPizza(Pizza* realPizza);

void setSize(Pizza* myPizza);

void setCrust(Pizza* myPizza);

void setPlants(Plants* myPlant);

void setSauce(Pizza* myPizza);

void setMeats(Meats* myMeat);

void printPizza(Pizza* myPizza);

// Extra Credit (3pts.)
void multipleMenus(const int size);

#endif // ! _Pizza_Header_H