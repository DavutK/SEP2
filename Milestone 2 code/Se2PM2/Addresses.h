/*
 * Adresses.h
 *
 *  Created on: 10.10.2012
 *      Author: Peter
 */

#ifndef ADDRESSES_H_
#define ADDRESSES_H_

#define DIO_BASE 0x300           // Base address
#define DIO_OFFS_A 0x00         // Port A offset
#define DIO_OFFS_B 0x01         // Port B offset
#define DIO_OFFS_C 0x02         // Port C offset
#define DIO_OFFS_CTRL 0x03      // Control register offset

// BIT_X is set to one

#define BIT_0 0x01		//Motor Rechtslauf
#define BIT_1 0x02		//Motor Linkslauf
#define BIT_2 0x04		//Motor Langsam (nicht benoetigt)
#define BIT_3 0x08		//Motor stopp
#define BIT_4 0x10		//Weiche Auf
#define BIT_5 0x20		//Gruen
#define BIT_6 0x40		//Gelb
#define BIT_7 0x80		//Rot

#endif /* ADDRESSES_H_ */
