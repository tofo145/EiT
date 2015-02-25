/*
Takes a lot of data (sensor_id, sensor_status, sensor_values, array of faulty sensors/sensors with unexpected values)
Generates a samplenumber/"timestamp"
	Read file
	if empty
		samplenumber = 0
	else
		samplenumber++
Sends samplenumber, sensor IDs, sensor statuses and sensor values to CSVConverter, receives data in CSV format
Writes to file (log)
Read error log. If detected error(s) does not exist, send samplenumber and array of faulty sensors/sensors with unexpected values to CSVConverter, receive data in CSV format
Writes to file (error log)
if samplenumber % 3600 = 0		(one hour of logging, can be changed as needed)
	get values for each sensor and calculate the average
	Send samplenumber of the first sample of the hour, each sensor_id and their average values, and one value indicating if anything was wrong with any of the sensors in the last hour
	to CSVConverter, receive data in CSV format
	Writes to file (average log)

*/