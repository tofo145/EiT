#include <stdio.h>
#include <stdlib.h>
#include "Logger.h"
#include "WriteToFile.h"

void csv_converter(long int id, float values[], int size) {
	int i=0;
	printf("%ld, ", id);
	for(i = 0; i < size-1; ++i) {
		printf("%.2f, ", values[i]);
	}
	printf("%.2f\n", values[size-1]);
}

/*
	Takes an id and a float array of sensor data and converts it  to CSV format
	long int id: samplenumber
	float values[]: sensor data - format {sensor1_id, sensor1_status, sensor1_value, sensor2_id, sensor2_status, sensor2_value,...}
*/
void convertToCSV(long int id, float values[]) {
	int i;
	float csv_list[NUMBER_OF_SENSORS * 3 + 1];

	csv_list[0] = id;
	for(i = 1; i < NUMBER_OF_SENSORS * 3 + 1; i++) {
		csv_list[i] = values[i - 1];
	}
	// Calls a function that writes csv_list to file
	writeFloatToFile(LOG_PATH, csv_list);
}

/*int main(void) {
	int size = 3;
	float sensorValues[3] = {10.423245, 24.3242, 7.9};
	long int id;
	for (id=1; id<100; id++) {
		sensorValues[0]++;
		sensorValues[1]++;
		sensorValues[2]++;
		csv_converter(id, sensorValues, size);
	}
	return EXIT_SUCCESS;
}*/