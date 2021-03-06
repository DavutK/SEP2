/*
 * Mutex.h
 *
 *  Created on: 16.04.2013
 *      Author: Carlos
 */

#ifndef MUTEX_H_
#define MUTEX_H_

#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"

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
