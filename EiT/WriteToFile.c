#include <stdio.h>
#include <stdlib.h>  /* For exit() function */

void writeToFile(const char *filepath, const char *data){
	FILE *fp = fopen(filepath, "a");		// Opens filepath in append mode

	if(fp==NULL){							// Checks that there is a filepath
      printf("Error!");
      exit(1);
    }

	fprintf(fp, "%s \n", data);				// Adds data to file followed by a new line
	fclose(fp);								// Closes filepointer
}