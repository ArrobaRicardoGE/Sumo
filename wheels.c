#include "wheels.h"

void config_wheels() {
	DDRW |= (1 << RW_IN1)|(1 << RW_IN2)|(1 << LW_IN1)|(1 << LW_IN2);
	
	// Timer0 
	TCCR0 = 0b01101011; // prescaler 64
	OCR0 = 0;
	PORTB |= (1 << 3); 
	
	// Timer2
	TCCR2 |= (1<<WGM20)|(1<<WGM21);
	TCCR2 |= (1<<COM21)|(1<<CS20)|(1<<CS21)|(0<<CS22); // prescaler 64
	OCR2 = 0;
	PORTD |= (1 << 7); 
}

void _enable_all() {
	PORTW |= (1 << RW_IN1)|(1 << LW_IN1)|(1 << RW_IN2)|(1 << LW_IN2);
}

void w_forwards() {
	_enable_all();
	PORTW ^= ((1 << RW_IN2)|(1 << LW_IN2));
}

void w_backwards() {
	_enable_all();
	PORTW ^= ((1 << RW_IN1)|(1 << LW_IN1));
}

void w_right() {
	_enable_all();
	PORTW ^= ((1 << RW_IN1)|(1 << LW_IN2));
}

void w_left() {
	_enable_all();
	PORTW ^= ((1 << RW_IN2)^(1 << LW_IN1));
}

void w_stop() {
	PORTW ^= ((1 << RW_IN1)|(1 << RW_IN2)|(1 << LW_IN1)|(1 << LW_IN2));
}

void w_set_speed(uint8_t speed) {
	OCR0 = speed; 
	OCR2 = speed;
}
