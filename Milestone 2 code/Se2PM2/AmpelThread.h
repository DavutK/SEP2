/*
 * MyThread.h
 *
 *  Created on: 10.10.2012
 *      Author: Peter
 */

#ifndef MYTHREAD_H_
#define MYTHREAD_H_

#include "HAWThread.h"

namespace thread {

class AmpelThread: public thread::HAWThread {
public:
	AmpelThread();
	virtual ~AmpelThread();

protected:
	virtual void execute(void* arg);
	virtual void shutdown();

public:
};

}

#endif /* MYTHREAD_H_ */
