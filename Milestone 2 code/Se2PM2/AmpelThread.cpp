/*
 * MyThread.cpp
 *
 *  Created on: 10.10.2012
 *      Author: Peter
 */

#include "MegaHeader.h"

using namespace std;

namespace thread {

Hal* hal = NULL;

AmpelThread::AmpelThread() {

	hal = Hal::getInstance();

}

AmpelThread::~AmpelThread() {
	// TODO Auto-generated destructor stub
}

void AmpelThread::shutdown() {

	hal->~Hal();
	cout << "Shutting down...1" << endl;

}

void AmpelThread::execute(void *arg) {

	//	hal->weicheZu();
	//	hal->weicheAuf();


	while (!isStopped()) {
		hal->laufbandVor();
		hal->ampelGruenAn();
	}

}

}
