/*
 * Seriell.cpp
 *
 *  Created on: 17.04.2013
 *      Author: Asmatullah Noor
 */

#include "Seriell.h"

Seriell::Seriell() {
	cout << "vor OPEN()" << endl;
	fd = (open(SCHNITTSTELLE1, O_RDWR));
	cout << fd << endl;
}

Seriell::~Seriell() {

	close(fd);
}

int Seriell::sendMsg(char msg){

	write(fd,&msg,sizeof(msg));
	return 0;
}

int Seriell::readMsg(char* buff){

	readcond(fd,buff, sizeof(buff),1,0,10);
	return 0;
}
