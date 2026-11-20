#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
	FILE *file;
	file = fopen(argv[1], "w");	
	int *input = malloc(50 * sizeof(char));
	int iteration = 1; 
	do {
		scanf("%c", &input[iteration]);
		fputc(input[iteration], file);
		printf("%c", input[iteration]);
		if (input[iteration] == 't') {
			break;
		}
		iteration++;
	} while (1);
	fclose(file);
}
