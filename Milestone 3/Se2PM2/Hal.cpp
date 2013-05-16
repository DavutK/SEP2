/*
 * Ampeln.cpp
 *
 *  Created on: 15.04.2013
 *      Author: Davut
 */

#include "Hal.h"

Mutex* Hal::halMutex = new Mutex();
Hal* Hal::instance = NULL;

Hal::Hal() {

	halMutex->lock();
	// Initialisierung der Digitalen IO Karte
	out8(DIO_BASE + DIO_OFFS_CTRL, 0x8A);
	out8(DIO_BASE + DIO_OFFS_A, 0x00);
	out8(DIO_BASE + DIO_OFFS_B, 0x00);
	out8(DIO_BASE + DIO_OFFS_C, 0x00);
	halMutex->unlock();
}

Hal::~Hal() {
	halMutex->unlock();
	out8(DIO_BASE + DIO_OFFS_A, 0x00);
	out8(DIO_BASE + DIO_OFFS_B, 0x00);
	out8(DIO_BASE + DIO_OFFS_C, 0x00);
	instance = NULL;
	halMutex->~Mutex();

}

//Hal* Hal::getInstance() {
//	// Zugriffsrechte fuer den Zugriff auf die HW holen
//	if (-1 == ThreadCtl(_NTO_TCTL_IO, 0)) {
//		perror("ThreadCtl access failed\n");
//		return NULL;
//	}
//
//	if (instance == NULL) {
//		instance = new Hal();
//	}
//	return instance;
//
//}

Hal* Hal::getInstance() {
	// Zugriffsrechte fuer den Zugriff auf die HW holen
	if (-1 == ThreadCtl(_NTO_TCTL_IO, 0)) {
		perror("ThreadCtl access failed\n");
		return NULL;
	}
	if (instance == NULL) {
		halMutex->lock();
		if (instance == NULL)
			instance = new Hal();
		halMutex->unlock();

	}
	return instance;
}

void Hal::ampelRotAus() {

	halMutex->lock();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);

	out8(DIO_BASE + DIO_OFFS_A, val & ~BIT_7);
	halMutex->unlock();

}

void Hal::ampelRotAn() {
	halMutex->lock();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val | BIT_7);
	halMutex->unlock();
}

void Hal::ampelGelbAus() {
	halMutex->lock();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val & ~BIT_6);
	halMutex->unlock();
}

void Hal::ampelGelbAn() {

	halMutex->lock();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val | BIT_6);
	halMutex->unlock();

}

void Hal::ampelGruenAus() {

	halMutex->lock();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val & ~BIT_5);
	halMutex->unlock();

}
void Hal::ampelGruenAn() {

	halMutex->lock();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val | BIT_5);
	halMutex->unlock();

}

//Laufband neu


void Hal::laufbandVor() {

	halMutex->lock();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val & ~BIT_1);

	val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val & ~BIT_3);

	val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val | BIT_0);

	halMutex->unlock();
}

void Hal::laufbandZurueck() {
	halMutex->lock();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val & ~BIT_3);

	val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val & ~BIT_0);

	val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val | BIT_1);
	halMutex->unlock();
}

void Hal::laufbandStop() {
	halMutex->lock();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val & ~BIT_0);

	val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val & ~BIT_1);

	val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val | BIT_3);
	halMutex->unlock();
}

void Hal::weicheAuf() {
	halMutex->lock();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val | BIT_4);
	halMutex->unlock();
}

void Hal::weicheZu() {
	halMutex->lock();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	out8(DIO_BASE + DIO_OFFS_A, val & ~BIT_4);
	halMutex->unlock();
}

