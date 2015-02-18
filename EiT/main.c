#include <stdio.h>
#include <stdlib.h>  /* For exit() function */
#include "WriteToFile.h"

//const char *sensorData getAllSensorData();

int main()
{
	//sensorData = getAllSensorData();
	writeToFile("program.txt", "testing1");
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