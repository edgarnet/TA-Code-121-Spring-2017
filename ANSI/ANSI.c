/*
 * =====================================================================================
 *
 *       Filename:  ANSI.c
 *
 *    Description:  Allows for cross-platform implementation of ANSI escape sequences.
 *
 *        Version:  1.0
 *        Created:  10/12/2017 08:18:17 PM
 *       Revision:  Many
 *       Compiler:  Visual C, GCC
 *
 *         Author:  Edgar Perez (eap), edgar.a.perez@wsu.edu
 *   Organization:  Washington State University
 *
 * =====================================================================================
 */

// This goes in your header file.
#include	<stdio.h>
#define		CLS		"\033[2J\033[1;1H"

// This stays in main.
#ifdef _WIN32

#include	<windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

#else

#define _WIN32 0
typedef enum handle { NO, YES } HANDLE;
typedef enum dword { ENABLE_VIRTUAL_TERMINAL_PROCESSING, STD_OUTPUT_HANDLE } DWORD;
HANDLE GetStdHandle( DWORD lol ) { return NO; }
void GetConsoleMode( HANDLE yah, DWORD * nah ) { return; }
void SetConsoleMode( HANDLE what, DWORD where ) { return; } 

#endif

int main(void) {

	// Lines 44 - 50 go in your main function.
	if (_WIN32) {
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD dwMode = 0;
		GetConsoleMode(hOut, &dwMode);
		dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		SetConsoleMode(hOut, dwMode);
	}

	printf("Enter input: \n");
	// This is a good substitute for 'system("pause")'.
	getchar();
	// This is where you would print the 'clear screen' escape sequence.
	printf("%s", CLS);
	printf("Is it clear?\n");
	return 0;

}
