//#include <stdio.h>
//#include "twim.h"
//#include "gpio.h"
//#include "i2c.h"
//
//void i2c_init ()
//{
//	const gpio_map_t twim_gpio_map = {
//		{AVR32_TWIMS0_TWCK_0_0_PIN, AVR32_TWIMS0_TWCK_0_0_FUNCTION},
//		{AVR32_TWIMS0_TWD_0_0_PIN, AVR32_TWIMS0_TWD_0_0_FUNCTION}
//	};
//
//	const twi_options_t twim_options = {
//		.pba_hz = APPLI_PBA_SPEED,
//		.speed = TWI_STD_MODE_SPEED,
//		.chip = 0 x01,
//		.smbus = 0
//	};
//
//	gpio_enable_module(twim_gpio_map,
//		sizeof(twim_gpio_map ) / sizeof(twim_gpio_map[0]));
//	twim_master_init(& AVR32_TWIM0, & twim_options);
//}
//
//uint32_t i2c_read ( uint32_t address, uint32_t command,
//	uint8_t command_length, uint8_t data_length)
//{
//	twi_package_t package;
//	uint8_t buffer[4];
//	uint8_t status;
//	uint8_t i;
//	uint32_t data = 0;
//
//	/* The I2C device we want to target . */
//	package.chip = address;
//	/* The command we want to send to the target I2C device . */
//	package.addr = command;
//	/* The byte length of the previous command . */
//	package.addr_length = command_length;
//	/* The buffer to receive data in. */
//	package.buffer = (void *) buffer;
//	/* The expected length of the data to receive . */
//	package.length = data_length;
//
//	status = twi_master_read (& AVR32_TWIM0, &package);
//
//	if (status == STATUS_OK) {
//		for ( i = 0; i < data_length; i++) {
//			data <<= 8;
//			data |= buffer [i];
//		}
//		return data ;
//	} else {
//		return 0;
//	}
//}
//
//void i2c_write_byte(uint32_t address, uint8_t command, uint8_t data)
//{
//	twi_package.chip = address;
//
//	/* The I2C device we want to target . */
//	package.chip = address;
//	/* The command we want to send to the target I2C device . */
//	package.addr = command;
//	/* The byte length of the previous command . */
//	package.addr_length = 1;
//	/* The buffer of data to write . */
//	package.buffer = (void *)&data;
//	/* The length of the data to write . */
//	package.length = 1;
//
//	twi_master_write(&AVR32_TWIM0, &package );
//}
//
//uint32_t i2c_read_voltage(uint32_t address)
//{
//	return i2c_read(address, 0x01, 1, 2);
//}
//
//uint32_t i2c_read_rtc_temperature(uint32_t address)
//{
//	/* TODO : Do something about negative values ( sign is in bit 10 after
//	* shifting , so we need to extend the sign etc .). */
//	return i2c_read (address, 0x11, 1, 2) >> 6;
//}
//
//void i2c_print_voltage(uint32_t data)
//{
//	double current = data / 4.0;
//	printf ("%.2f mA", current );
//}
//
//void i2c_print_rtc_temperature(uint32_t data)
//{
//	double celsius = data / 4.0;
//	printf ("%.2f deg C", celsius );
//}
//
//Displaying i2c.c.
//Displaying i2c.c.