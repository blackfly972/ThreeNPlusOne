/*
 ============================================================================
 Name        : ThreeNPlusOne.c
 Author      : Me
 Version     :
 Copyright   : Your copyright notice
 Description : The Collatz conjecture program in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int computeMaxSequenceLength(int first, int second); // variable that will hold the compute max sequence length values
int computeSequenceLength(int value); // variable that will hold the compute sequence length values
int computeNextValue(int value); // variable that will hold the compute next values

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0); // Turn off output buffering. Required for automated testing.

	int first;
	int second;
	char buffer[1000]; // buffer containing 1000 bytes
	char outputFile[100];

	printf("Enter the output filename: \n"); // prompt
	fgets(outputFile, 99, stdin);
	FILE *output;
	outputFile[strlen(outputFile) - 1] = '\0';
	output = fopen(outputFile, "w"); // write into a file

	if (output == NULL) {
		return 0;
	}
	// do while function that will loop until a blank line is entered
	do {
		first = atoi(fgets(buffer, 1000, stdin));
		if (buffer[0] != '\n') {
			second = atoi(fgets(buffer, 1000, stdin));
			if (second == 0) {
				break;
			}

			int max = computeMaxSequenceLength(first, second);
			fprintf(output, "%d\t%d\t%d\n", first, second, max);
		}
	} while (buffer[0] != '\n');

	fclose(output);
	printf("Complete\n");
	return 0;
}
//compute max sequence length function takes an integer and return the maximum length
int computeMaxSequenceLength(int first, int second) {
	int i = 0;
	int length = 0;
	int maxLength = 0;
	for (i = first; i <= second; i++) {
		length = computeSequenceLength(i);
		maxLength = (maxLength <= length) ? length : maxLength;
	}
	return maxLength;
}
// compute sequence length function takes an integer and return the sequence length
int computeSequenceLength(int value) {
	int length = 0;
	for (length = 1; value != 1; length++)
		value = computeNextValue(value);
	return length;
}
// compute next value function takes an integer and return the next value
int computeNextValue(int value) {
	return (value % 2 == 0) ? (value / 2) : (3 * value + 1);
}
