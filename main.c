/*
 * Sumo.c
 *
 * Created: 10/04/2022 02:33:13 p. m.
 * Author : -
 */ 

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include "wheels.h"
#include "sensors.h"



int main(void)
{
    config_wheels(); 
	config_sensors(); 
    while (1) 
    {
		if(read_ds(DS2) >= 512) w_left(); 
		else w_right(); 
    }
}

