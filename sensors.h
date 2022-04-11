#ifndef SENSORS_H_INCLUDED
#define SENSORS_H_INCLUDED

#define F_CPU 1000000

#define PORTS PORTA
#define PINS PINA
#define DS1 0
#define DS2 1
#define RBW 2
#define LBW 3

#include <avr/io.h>
#include <stdint.h>
#include "util.h"

void config_sensors(); 
uint8_t read_bw(uint8_t idx); 
uint16_t read_ds(uint8_t idx); 


#endif