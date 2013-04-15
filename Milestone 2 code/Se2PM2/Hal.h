/*
 * Hal.h
 *
 *  Created on: 15.04.2013
 *      Author: Davut
 */

#ifndef HAL_H_
#define HAL_H_

class Hal {

private:
	Hal();

	static Hal* instance;

public:
	~Hal();

	static Hal* getInstance();

	//Ampel
	void ampelRotAus();
	void ampelRotAn();

	void ampelGelbAus();
	void ampelGelbAn();

	void ampelGruenAus();
	void ampelGruenAn();

	//Laufband
	void laufbandVor();
	void laufbandZurueck();
	void laufbandStop();

	//Weiche
	void weicheAuf();
	void weicheZu();

};

#endif /* HAL_H_ */
