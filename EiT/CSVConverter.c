#include <stdio.h>
#include <conio.h>  /* for clrscr */
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <dos.h>  /* for delay */
#include <conio.h>

typedef int bool;
enum { false, true };

float** csvFileValues;
int* sampleIDs;
int lines;
int valuesPerLine;
const int maxLineLength = 1024;

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

void freeCSVFileValues() {
	int i;
	for (i = 0; i < lines; i++) {
	  free(csvFileValues[i]);
	}
	free(csvFileValues);
}

int getFirstSampleNumber(FILE* file) {
	char line[maxLineLength];
	fgets(line, maxLineLength, file);
	char* firstSampleNumber = strtok(line, ",");
	return atoi(firstSampleNumber);
}

int getLastSampleNumber(FILE* file) {
	static const long max_len = 50;  			// define the max length of the line to read
	char buff[max_len + 1];             		// define the buffer and allocate the length

	fseek(file, -max_len, SEEK_END);            // set pointer to the end of file minus the length you need. Presumably there can be more than one new line caracter
	fread(buff, max_len-1, 1, file);            // read the contents of the file starting from where fseek() positioned us

	buff[max_len-1] = '\0';                   	// close the string
	char* last_newline = strrchr(buff, '\n'); 	// find last occurrence of newlinw

	char* lastSampleNumber = strtok(last_newline, ",");

	rewind(file); // reset file position indicator to start of the file.
	return atoi(lastSampleNumber);
}

void writeCSVFile(int id, float values[], int size) {

	int i=0;
	printf("%ld, ", id);
	for(i = 0; i < size-1; ++i) {
		printf("%.2f, ", values[i]);
	}
	printf("%.2f\n", values[size-1]);
}

void readCSVFile(FILE* file, int sampleIdStart, int sampleIdEnd) {
	if (csvFileValues != NULL && lines != NULL) {
		printf("freeing csvFileValues");
		freeCSVFileValues(); // <---------------- causes crash when run! -----------------------
	}

	int i;

	if (sampleIdStart < 0 && sampleIdEnd < 0) { // Fetch whole file.
		lines = countLines(file);
	} else if (sampleIdStart >= 0 && sampleIdEnd < 0) { // Fetch from sampleIdStart to end of file.
		int lastSampleId = getLastSampleNumber(file);
		lines = lastSampleId - sampleIdStart + 1;
	} else if (sampleIdStart < 0 && sampleIdEnd >= 0) { // Fetch from start of file to sampleIdEnd.
		int firstSampleId = getFirstSampleNumber(file);
		lines = sampleIdEnd - firstSampleId + 1;
	} else { // Fetch from sampleIdStart to sampleIdEnd.
		lines = sampleIdEnd - sampleIdStart + 1;
	}


	rewind(file); // reset file position indicator to start of the file.

	char line[maxLineLength];

	// Counts number of values on first line
	char tmpLine[maxLineLength];
	fgets(tmpLine, maxLineLength, file);
	valuesPerLine = countChars( tmpLine, ',' );

	sampleIDs = malloc(lines * sizeof(int));
	csvFileValues = malloc(lines * sizeof(float*));
	for (i = 0; i < lines; i++) {
		csvFileValues[i] = malloc(valuesPerLine * sizeof(float));
	}

	rewind(file); // reset file position indicator to start of the file.


	i=0;
	int lineIdx = -1;
	while (fgets(line, maxLineLength, file)) {
		const char* tok;
		int j = 0;
		bool fetchThisLine = true;
		for (tok = strtok(line, ","); tok && *tok && fetchThisLine; tok = strtok(NULL, ",\n")) {
			if (j == 0) { // Value is sample ID
				int sampleID = atoi(tok);
				if ((sampleIdStart >= 0 && sampleIdEnd < 0 && sampleID < sampleIdStart) ||
						(sampleIdStart < 0 && sampleIdEnd >= 0 && sampleID > sampleIdEnd) ||
						(sampleIdStart >= 0 && sampleIdEnd >=0 && (sampleID < sampleIdStart || sampleID > sampleIdEnd))) {
					//printf("Skipping sampleID %i. ", sampleID);
					fetchThisLine = false;
				} else {
					lineIdx++;
					sampleIDs[lineIdx] = sampleID;
				}
			}

			if (fetchThisLine) {
				float value = strtof(tok, NULL); // cast value to float
				csvFileValues[lineIdx][j] = value;
				//printf("[%i][%i] = %.2f\n", i+1, j, value);
			}

			j++;
		}
		if (fetchThisLine) {
			//printf("\n");
		}
		i++;

		free(tok);
	}
	rewind(file); // reset file position indicator to start of the file.
}


int main(void) {
	FILE* file = fopen("test.csv", "r");

	// Test code for converting float to CSV:
	/*int size = 3;
	float sensorValues[3] = {10.423245, 24.3242, 7.9};
	int id;
	for (id=1; id<100; id++) {
		sensorValues[0]++;
		sensorValues[1]++;
		sensorValues[2]++;
		writeCSVFile(id, sensorValues, size);
	}*/

	// Test code for reading file and converting CSV to float:
	readCSVFile(file, -1, -1); // -1 means start/end of file
	int i, j;
	for (i=0; i<lines; i++) {
		printf("Sample %i: ", sampleIDs[i]);
		for (j=0; j<valuesPerLine; j++) {
			printf("\n%.2f", csvFileValues[i][j]);
		}
		printf("\n\n");
	}

	// Test code for getting the last line in the file:
	//int nextSampleNumber = getLastSampleNumber(file) + 1;
	//printf("Next sample number: %i", nextSampleNumber);

	fclose(file);
	return EXIT_SUCCESS;
}
