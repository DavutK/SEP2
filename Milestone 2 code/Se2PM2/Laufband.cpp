/*
 * Laufband.cpp
 *
 *  Created on: 15.04.2013
 *      Author: Davut
 */

#include "Hal.h"
#include "Addresses.h"
#include "HWaccess.h"

#include "stdint.h"

void Hal::laufbandVor() {

	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val | BIT_0);

}

void Hal::laufbandZurueck() {

	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val & ~BIT_1);

}

void Hal::laufbandStop() {

	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val | BIT_3);

}
