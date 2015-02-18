#ifndef __I2C_H__
#define __I2C_H__

#include <stdint.h>

void i2c_init(void);
uint32_t i2c_read(uint32_t address, uint32_t command,
	uint8_t command_length, uint8_t data_length);
void i2c_write_byte(uint32_t address, uint8_t command, uint8_t data);

uint32_t i2c_read_voltage(uint32_t address);
uint32_t i2c_read_rtc_temperature(uint32_t address);
void i2c_print_voltage(uint32_t data);
void i2c_print_rtc_temperature(uint32_t data);

#endif