#include "test.h"

void lampenTest(int color) {

	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	switch (color) {
	case 0:
		val ^= BIT_7;
		break;
	case 1:
		val ^= BIT_6;
		break;
	case 2:
		val ^= BIT_5;
		break;
	}

	out8(DIO_BASE + DIO_OFFS_A, val);
}

void ampelTest() {

	int n = 0;
	int var;
	for (n = 0; n < 3; ++n) {
		for (var = 0; var < 10; var++) {
			lampenTest(n);
			usleep(500000);
		}
		lampenTest(n);
		sleep(3);
		lampenTest(n);
		sleep(1);
	}
}

void ampelTest2(){

	int n = 0;
	for(n = 0; n < 2; ++n){
		lampenTest(n);
		lampenTest(++n);
		sleep(2);

		lampenTest(n);
		cout<< n << endl;
		lampenTest(--n);
		sleep(2);
	}

	lampenTest(2);
	lampenTest(0);
	sleep(2);

	lampenTest(2);
	lampenTest(0);
	sleep(2);

}

void startTest() {
	ampelTest();
	ampelTest2();

}

