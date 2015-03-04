/*
	Converts input data to CSV format (comma separated values)
*/

int countLines(FILE* file);
int countChars( char* s, char c );
void freeCSVFileValues();
int getFirstSampleNumber(FILE* file);
int getLastSampleNumber(FILE* file);
void writeCSVFile(int id, float values[], int size);
void readCSVFile(FILE* file, int sampleIdStart, int sampleIdEnd);
