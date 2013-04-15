/*
 * Ampeln.cpp
 *
 *  Created on: 15.04.2013
 *      Author: Davut
 */

#include "MegaHeader.h"


Hal* Hal::instance = NULL;

Hal::Hal() {
	// Initialisierung der Digitalen IO Karte
	out8(DIO_BASE + DIO_OFFS_CTRL, 0x8A);
	out8(DIO_BASE + DIO_OFFS_A, 0x00);
	out8(DIO_BASE + DIO_OFFS_B, 0x00);
	out8(DIO_BASE + DIO_OFFS_C, 0x00);


}

Hal::~Hal() {

	out8(DIO_BASE + DIO_OFFS_A, 0x00);
	out8(DIO_BASE + DIO_OFFS_B, 0x00);
	out8(DIO_BASE + DIO_OFFS_C, 0x00);

	delete instance;
	instance = NULL;


}

Hal* Hal::getInstance() {
	// Zugriffsrechte fuer den Zugriff auf die HW holen
	if (-1 == ThreadCtl(_NTO_TCTL_IO, 0)) {
		perror("ThreadCtl access failed\n");
		return NULL;
	}

	if (instance == NULL) {
		instance = new Hal();
	}
	return instance;

}
