/*
 * Weiche.cpp
 *
 *  Created on: 15.04.2013
 *      Author: Carlos
 */

#include "MegaHeader.h"

void Hal::weicheAuf() {

	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val | BIT_4);

}

void Hal::weicheZu() {

	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val & ~BIT_4);

}
