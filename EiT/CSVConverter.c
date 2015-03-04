#include <stdio.h>
#include <conio.h>  /* for clrscr */
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <dos.h>  /* for delay */
#include <conio.h>

int countLines(FILE* file) {
	int ch=0;
	int lines=0;

	// Count number of lines
	while(!feof(file)) {
		ch = fgetc(file);
		if(ch == '\n') {
			lines++;
		}
	}
	lines++;
	return lines;
}

int countChars( char* s, char c ) {
	return *s == '\0' ? 0 : countChars( s + 1, c ) + (*s == c);
}

float getNextSampleNumber(FILE* file) {
	static const long max_len = 50;  			// define the max length of the line to read
	char buff[max_len + 1];             		// define the buffer and allocate the length

	fseek(file, -max_len, SEEK_END);            // set pointer to the end of file minus the length you need. Presumably there can be more than one new line caracter
	fread(buff, max_len-1, 1, file);            // read the contents of the file starting from where fseek() positioned us

	buff[max_len-1] = '\0';                   	// close the string
	char* last_newline = strrchr(buff, '\n'); 	// find last occurrence of newlinw

	char* lastSampleNumber = strtok(last_newline, ",");
	float nextSampleNumber = strtof(lastSampleNumber, NULL) + 1;

	rewind(file); // reset file position indicator to start of the file.
	return nextSampleNumber;
}

void writeCSVFile(long int id, float values[], int size) {

	int i=0;
	printf("%ld, ", id);
	for(i = 0; i < size-1; ++i) {
		printf("%.2f, ", values[i]);
	}
	printf("%.2f\n", values[size-1]);
}

float** readCSVFile(FILE* file) {
	const int maxLineLength = 1024;

	int lines = countLines(file);

	char tmpLine[maxLineLength];
	fgets(tmpLine, maxLineLength, file);
	int numOfLineValues = countChars( tmpLine, ',' ) + 1;
	float values[lines][numOfLineValues];

	rewind(file); // reset file position indicator to start of the file.

	char line[maxLineLength];
	int i=0;
	while (fgets(line, maxLineLength, file)) {
		const char* tok;
		int j = 0;
		for (tok = strtok(line, ","); tok && *tok; tok = strtok(NULL, ",\n")) {
			float value = strtof(tok, NULL); // cast value to float
			values[i][j] = value;
			printf("Field %i = %.2f\n", j, value);
			j++;
		}
		printf("\n");
		i++;

		free(tok);
	}
	rewind(file); // reset file position indicator to start of the file.

	printf("test: values[10][2] = %.2f", values[10][2]);
	return values;
}


int main(void) {
	FILE* file = fopen("test.csv", "r");

	// Test code for converting float to CSV:
	/*int size = 3;
	float sensorValues[3] = {10.423245, 24.3242, 7.9};
	long int id;
	for (id=1; id<100; id++) {
		sensorValues[0]++;
		sensorValues[1]++;
		sensorValues[2]++;
		writeCSVFile(id, sensorValues, size);
	}*/

	// Test code for reading file and converting CSV to float:
	//float** valuesFromCSV = readCSVFile(file);


	// Test code for getting the last line in the file:
	/*float nextSampleNumber = getNextSampleNumber(file);
	printf("next sample number: %f", nextSampleNumber);*/

	fclose(file);
	return EXIT_SUCCESS;
}
