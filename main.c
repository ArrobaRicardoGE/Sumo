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



int main(void)
{
    config_wheels(); 
    while (1) 
    {
		_delay_ms(1000); 
		w_set_speed(128); 
		w_forwards(); 
		_delay_ms(1000); 
		w_set_speed(255);
		w_backwards(); 
		_delay_ms(1000);
		w_set_speed(128); 
		w_right(); 
		_delay_ms(1000); 
		w_set_speed(255);
		w_left(); 
    }
}

