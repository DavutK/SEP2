/*
 * Mutex.h
 *
 *  Created on: 16.04.2013
 *      Author: Carlos
 */

#ifndef MUTEX_H_
#define MUTEX_H_

#include "MegaHeader.h"

class Mutex {
public:
	Mutex();
	virtual ~Mutex();

	void lock();

	void unlock();

private:
	pthread_mutex_t mutex;

};




#endif /* MUTEX_H_ */
