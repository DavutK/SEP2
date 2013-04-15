/*
 * Ampeln.cpp
 *
 *  Created on: 15.04.2013
 *      Author: Davut
 */

#include "MegaHeader.h"


void Hal::ampelRotAus() {

	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val & ~BIT_7);

}

void Hal::ampelRotAn() {
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val | BIT_7);
}

void Hal::ampelGelbAus() {
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val & ~BIT_6);
}

void Hal::ampelGelbAn() {

	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val | BIT_6);

}

void Hal::ampelGruenAus() {

	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val & ~BIT_5);

}
void Hal::ampelGruenAn() {

	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val | BIT_5);

}

