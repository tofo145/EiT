#include <stdio.h>
#include <stdlib.h>  /* For exit() function */
#include "WriteToFile.h"
#include "CSVConverter.h"

//const char *sensorData getAllSensorData();

int main()
{
	/*
	Runs every second (or however often we set it to, use some variable). Maybe use a while-loop which checks if any input command has been received
	Retrieves all data from sensors - getAllSensorData(). Get some error value if a sensor cannot be communicated with
	Processes received values (checks for unnatural values, sets status -> StatusUpdate.c) and converts to CSV format
	Writes converted data to file
	*/
	//sensorData = getAllSensorData();
	//writeToFile("program.txt", "testing1");
	float testing[12] = {0, 2.2, 1, 1, 32.2, 1, 2, 0.0, 0, 3, 1.7, 1};
	convertToCSV(21, testing);
	/*FILE *fp = fopen("program.txt", "a");
	if(fp==NULL){
      printf("Error!");
      exit(1);
    }
	fputs ("testing\n", fp);
	fclose(fp);*/
}

/*
const char *sensorData getAllSensorData(){
	ans[0] = readTempSensor1();
	ans[1] = readTempSensor2();
	ans[2] = readTempSensor3();
}*/