#include "sensors.h"

void config_sensors() {
	// ADC
	ADMUX = 0b01000000;
	SFIOR = 0; 
	ADCSRA = 0b10010111;
	
	// Other sensors
	// PORTS |= (1 << RBW)|(1 << LBW); 
}

uint16_t read_ds(uint8_t idx) {
	ADMUX &= 0b11100000;
	ADMUX |= idx;
	saca_uno(&ADCSRA, 6);
	while(uno_en_bit(&ADCSRA, 6));
	return ADC;
}

uint8_t read_bw(uint8_t idx) {
	return PINS & (1 << idx);
}

