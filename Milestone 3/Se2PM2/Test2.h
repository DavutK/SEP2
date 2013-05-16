/*
 * Test2.h
 *
 *  Created on: 18.04.2013
 *      Author: aau792
 */

#ifndef TEST2_H_
#define TEST2_H_

#include "Hal.h"
#include "Addresses.h"

class Test2 {
public:

	Test2();
	virtual ~Test2();

	void startTest();
	void ampelTest();
	void laufBandTest();
	void weicheTest();

	void tastenTest();
	void ledTest();
	void sensorikTest();

};

#endif /* TEST2_H_ */
