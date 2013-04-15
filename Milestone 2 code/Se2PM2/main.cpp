/*
 * main.cpp
 *
 *  Created on: 15.04.2013
 *      Author: Davut
 */


#include "MegaHeader.h"

using namespace std;

int main(int argc, char *argv[]) {
#ifdef SIMULATION
	cout << "Simulation aktiv" << endl;
	cout << "Zum Aufbau der Verbindung muss Die Festo Simulation schon laufen." << endl;
	IOaccess_open(); // Baue die Verbindung zur Simulation auf
#endif

	thread::AmpelThread ampelThread;
	ampelThread.start(NULL);
	string str("");

	do {
		cout << "Enter 'q' to exit." << endl;
		cin >> str;
	} while (str != "q");

	ampelThread.stop();
	ampelThread.join();


#ifdef SIMULATION
	IOaccess_close(); // Schliesse die Verbindung zur Simulation
#endif
	return EXIT_SUCCESS;
}

