/*
 * Test2.cpp
 *
 *  Created on: 18.04.2013
 *      Author: aau792
 */

#include "Test2.h"

Hal* hal = NULL;

using namespace std;

Test2::Test2() {

	hal = Hal::getInstance();
}

Test2::~Test2() {
	// TODO Auto-generated destructor stub
}

void Test2::ampelTest() {

	int var = 0;

	for (var = 0; var < 5; var++) {

		hal->ampelRotAn();
		sleep(1);
		hal ->ampelRotAus();
		sleep(1);

	}

	for (var = 0; var < 5; var++) {
		hal->ampelGelbAn();
		usleep(500000);
		hal ->ampelGelbAus();
		usleep(500000);

	}

	for (var = 0; var < 5; var++) {
		hal->ampelGruenAn();
		usleep(500000);
		hal ->ampelGruenAus();
		usleep(500000);

	}

}

void Test2::laufBandTest() {

	hal->laufbandVor();

	sleep(5);

	hal->laufbandStop();

	sleep(2);

	hal->laufbandZurueck();

	sleep(5);

	hal->laufbandStop();
}

void Test2::weicheTest() {

	hal->weicheAuf();
	sleep(2);
	hal->weicheZu();

}

void Test2::tastenTest() {

//	hal->tasteStart();

}

void Test2::ledTest() {

//	hal->q2LED();

}

void Test2::sensorikTest() {

	uint8_t val = in8(DIO_BASE + DIO_OFFS_B);

	while (true) {

		if ((val & BIT_0) == BIT_0) {

			cout << "Einlauf Lichtschranke unterbrochen" << endl;

			hal->ampelGruenAn();
			hal->laufbandVor();
			sleep(1);
			hal->ampelGruenAus();

		}

		if ((~val & BIT_1) == BIT_1) {

			cout << "Werkstück in Höhenmessung" << endl;

		}

		if ((val & BIT_2) == BIT_2) {

			cout << "Werkstück in Höhenmessung Analog" << endl;

		}

		if ((~val & BIT_3) == BIT_3) {

			cout << "Werkstück in Weiche" << endl;

		}

		if ((val & BIT_4) == BIT_4) {

			cout << "Werkstück mit Metalbohrung" << endl;

			hal->weicheAuf();
			sleep(5);
			hal->weicheZu();

		}

		if ((val & BIT_5) == BIT_5) {

			cout << "weiche ist offen" << endl;

		}

		if ((~val & BIT_6) == BIT_6) {

			cout << "Werkstück ging durch die rutsche" << endl;

		}

		if ((~val & BIT_7) == BIT_7) {

			cout << "Auslauf Lichtschranke unterbrochen" << endl;

			hal->laufbandStop();

		}
		val = in8(DIO_BASE + DIO_OFFS_B);
	}

}

void Test2::startTest() {

	Test2::sensorikTest();
	//	Test2::ampelTest();
	//	Test2::laufBandTest();
	//	Test2::weicheTest();

}

