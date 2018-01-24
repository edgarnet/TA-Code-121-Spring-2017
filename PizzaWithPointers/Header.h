#pragma once

/*Comment Block*/
/*Name*/
/*Assignment*/
/*Description*/
/*Date*/
/*Contributor(s): Must Include EVERY Classmate You Worked With!!!*/

#ifndef  _HEADER_H
#define _HEADER_H

#include	<stdio.h>
#include	<stdlib.h>

// Determines the toppings of the pizza the user wants.
// Stores the choice in an integer pointer.
// Notice: the return type is 'Void'.
void choosePizza(int *type);

// Determines the size of the user's pizza.
// Stores the choice in an integer pointer.
void chooseSize(int *type);

// Determines the price of the pizza based on the previous choices
// for toppings and size, then stores the price in an integer pointer.
// Why are the toppings and size passed as integers and not pointers?
// Would it make a difference otherwise?
void determinePrice(int toppings, int size, int *price);

#endif // ! _HEADER_H
