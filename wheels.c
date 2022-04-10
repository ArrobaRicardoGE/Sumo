#include "wheels.h"

void config_wheels() {
	DDRW = (1 << RW_IN1)|(1 << RW_IN2)|(1 << LW_IN1)|(1 << LW_IN2);
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
