#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>

void enableRawMode() {
	struct termios raw; //copies terminal-io-structure attributes to "raw"

	tcgetattr(STDIN_FILENO, &raw); //fills raw's blank attributes with respective values from STDIN_FILNO
	
	raw.c_lflag &= ~(ECHO); //disables echo

	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw); //passes modified structure
}

int main() {
	enableRawMode();
	char c;
	while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
	return 0;
}
