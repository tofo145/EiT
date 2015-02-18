#include <stdio.h>
#include <stdlib.h>

void csv_converter(long int id, float values[], int size) {
	int i=0;
	printf("%ld, ", id);
	for(i = 0; i < size-1; ++i) {
		printf("%.2f, ", values[i]);
	}
	printf("%.2f\n", values[size-1]);
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