/*
 * test.h
 *
 *  Created on: 09.04.2013
 *      Author: aau792
 */

#ifndef TEST_H_
#define TEST_H_

#include "MyThread.h"
#include "Addresses.h"

#include "HWaccess.h"

#include <stdint.h> // uint8_t etc.
#include <unistd.h> // sleep

void lampenTest(int color);
void startTest();
void ampelTest();
void ampelTest2();
void KnightRider();

#endif /* TEST_H_ */
