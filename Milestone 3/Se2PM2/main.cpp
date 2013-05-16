/*
 * main.cpp
 *
 *  Created on: 15.04.2013
 *      Author: Davut
 */
#include <cstdlib>
#include <string>
#include <iostream>
#include <unistd.h>

#include <HWaccess.h>
#include <HAWThread.h>
#include <HAL.h>
#include <Sensorik.h>


using namespace std;
using namespace hal;


int main(int argc, char *argv[]) {

#ifdef SIMULATION
    cout << "=========================================================" << endl;
    cout << "SIMULATION" << endl;
    cout << "=========================================================" << endl;
    IOaccess_open();
#endif


    cout << "Sensorik Intro" << endl;
    cout << "=========================================================" << endl;
    cout << endl;

    Sensorik* sens = Sensorik::getInstance();
    sens->start(NULL);

    string quit;
    do {
        cin >> quit;
    } while (quit != "q");

    cout << "Quitting...";

    sens->stop();
    sens->join();

	out8(DIO_BASE + DIO_OFFS_A, DIO_OFFS_A);

    cout << " done." << endl;

#ifdef SIMULATION
    IOaccess_close();
#endif
	return EXIT_SUCCESS;
}

















//int main(int argc, char *argv[]) {
//#ifdef SIMULATION
//	cout << "Simulation aktiv" << endl;
//	cout << "Zum Aufbau der Verbindung muss Die Festo Simulation schon laufen."
//			<< endl;
//	IOaccess_open(); // Baue die Verbindung zur Simulation auf
//#endif
//
//	thread::AmpelThread ampelThread;
//	ampelThread.start(NULL);
//
//	string str("");
//
//	do {
//		cout << "Enter 'q' to exit." << endl;
//		cin >> str;
//	} while (str != "q");
//
//	ampelThread.stop();
//	ampelThread.join();
//
////	Seriell ser;
////
////
////	while(true){
////		ser.sendMsg('h');
//////		ser.sendMsg('a');
//////		ser.sendMsg('l');
//////		ser.sendMsg('l');
//////		ser.sendMsg('o');
////
////	}


//#ifdef SIMULATION
//	IOaccess_close(); // Schliesse die Verbindung zur Simulation
//#endif
//	return EXIT_SUCCESS;
//}

