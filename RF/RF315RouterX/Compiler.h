/* 
 * File:   Complier.h
 * Author: Chu
 *
 * Created on June 5, 2014, 4:45 PM
 */

#ifndef COMPILER_H
#define	COMPILER_H

#if defined(MCHP_C18)
    #include <p18cxxx.h>    // p18cxxx.h must have current processor
                            // defined.
    #include <stdlib.h>

#elif defined(__PIC24F__)	// Microchip C30 compiler
	// PIC24F processor
	#include <p24Fxxxx.h>
#elif defined(__PIC24H__)	// Microchip C30 compiler
	// PIC24H processor
	#include <p24Hxxxx.h>
#elif defined(__dsPIC33F__)	// Microchip C30 compiler
	// dsPIC33F processor
	#include <p33Fxxxx.h>
#else
#endif

#endif	/* COMPLIER_H */

