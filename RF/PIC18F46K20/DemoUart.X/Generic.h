/* 
 * File:   Generic.h
 * Author: Chu
 *
 * Created on June 10, 2014, 11:04 PM
 */

#ifndef GENERIC_H
#define	GENERIC_H

/**********define *********/
typedef unsigned char BYTE;
#define TRUE 1
#define FALSE 0

/*********Define Clock***************/

struct RF_Flag{
    unsigned char RF315_Flag:1;
};
struct Wsan_data{
    unsigned char buffer[];
    BYTE length;
    unsigned char count:4;
    unsigned char *data;
};

#endif	/* GENERIC_H */

