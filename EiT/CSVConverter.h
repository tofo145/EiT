/*
	Converts input data to CSV format (comma separated values)
*/

char** str_split(char* a_str, const char a_delim);
int countLines(FILE* file);
int countChars( char* s, char c );
void writeCSVFile(long int id, float values[], int size);
float** readCSVFile(FILE* file);
char* getLastLineInFile(FILE* file);
float getNextSampleNumber(FILE* file);
