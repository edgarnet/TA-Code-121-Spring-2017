//This goes in your header file.
#include	<stdio.h>
#define		CLS		"\033[2J\033[1;1H"

#ifdef _WIN32
#include	<windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
#endif

// Lines 14-20 go in your main function.
int main(void) {
  if (_WIN32) {
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD dwMode = 0;
		GetConsoleMode(hOut, &dwMode);
		dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		SetConsoleMode(hOut, dwMode);
	}
	printf("Enter input: \n");
	getchar();
	printf("%s", CLS);
	printf("Success!");
	return 0;
}
