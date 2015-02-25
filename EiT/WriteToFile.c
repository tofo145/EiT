#include <stdio.h>
#include <stdlib.h>  /* For exit() function */
#include "Logger.h"

void writeToFile(const char *filepath, const char *data){
	FILE *fp = fopen(filepath, "a");		// Opens filepath in append mode

	if(fp==NULL){							// Checks that there is a filepath
      printf("Error!");
      exit(1);
    }

	fprintf(fp, "%s \n", data);				// Adds data to file followed by a new line
	fclose(fp);								// Closes filepointer
}

void writeFloatToFile(const char *filepath, float data[NUMBER_OF_SENSORS * 3 + 1]){
	FILE *fp = fopen(filepath, "a");		// Opens filepath in append mode
	int i;
	if(fp==NULL){							// Checks that there is a filepath
      printf("Error!");
      exit(1);
    }
	
	fprintf(fp, "%.0f, ", data[0]);												// Prints the samplenumber
	for (i = 1; i < NUMBER_OF_SENSORS * 3 + 1; i = i + 3) {
		 fprintf(fp, "%.0f, %.0f, %.2f, ", data[i], data[i+1], data[i+2]);		// Prints all information belonging to a sensor (sensor id, status, value)
    }
	fprintf(fp, "\n");						// Adds a new line
	fclose(fp);								// Closes filepointer
}