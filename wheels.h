#ifndef WHEELS_H_INCLUDED
#define WHEELS_H_INCLUDED

#define F_CPU 1000000
#include <avr/io.h>

#define PORTW PORTD
#define DDRW DDRD
#define RW_IN1 0
#define RW_IN2 1
#define LW_IN1 2
#define LW_IN2 3

void config_wheels();

void w_forwards();

void w_backwards();

void w_right();

void w_left();

 void w_stop();

#endif