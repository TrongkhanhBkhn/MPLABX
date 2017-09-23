#include<p18cxxx.h>

#pragma config OSC = HSPLL
#pragma config FCMEN = OFF
#pragma config IESO = OFF
#pragma config PWRTEN = ON
#pragma config BOREN = ON
#pragma config BORV = 27
#pragma config WDTEN = OFF
#pragma config WINEN = OFF
#pragma config WDPS = 32768
#pragma config T1OSCMX = OFF
#pragma config HPOL = HIGH
#pragma config LPOL = HIGH
#pragma config PWMPIN = ON
#pragma config MCLRE = ON
#pragma config EXCLKMX = RD0
#pragma config PWM4MX = RD5
#pragma config SSPMX = RD1
#pragma config FLTAMX = RD4
#pragma config STVREN = ON
#pragma config LVP = OFF
#pragma config DEBUG = OFF
#pragma config CP0 = OFF
#pragma config CP1 = OFF
#pragma config CP2 = OFF
#pragma config CP3 = OFF
#pragma config CPB = OFF
#pragma config CPD = OFF
#pragma config WRT0 = OFF
#pragma config WRT1 = OFF
#pragma config WRT2 = OFF
#pragma config WRT3 = OFF
#pragma config WRTB = OFF
#pragma config WRTC = OFF
#pragma config WRTD = OFF
#pragma config EBTR0 = OFF
#pragma config EBTR1 = OFF
#pragma config EBTR2 = OFF
#pragma config EBTR3 = OFF
#pragma config EBTRB = OFF

const rom unsigned int sine[800]={
400 , 403 , 406 , 409 , 412 , 415 , 418 , 421 , 425 , 428 , 431 , 434 , 437 , 440 , 443 ,
447 , 450 , 453 , 456 , 459 , 462 , 465 , 468 , 471 , 474 , 478 , 481 , 484 , 487 , 490 ,
493 , 496 , 499 , 502 , 505 , 508 , 511 , 514 , 517 , 520 , 523 , 526 , 529 , 532 , 535 ,
538 , 541 , 544 , 547 , 550 , 553 , 555 , 558 , 561 , 564 , 567 , 570 , 573 , 575 , 578 ,
581 , 584 , 587 , 589 , 592 , 595 , 598 , 600 , 603 , 606 , 608 , 611 , 614 , 616 , 619 ,
622 , 624 , 627 , 630 , 632 , 635 , 637 , 640 , 642 , 645 , 647 , 650 , 652 , 654 , 657 ,
659 , 662 , 664 , 666 , 669 , 671 , 673 , 676 , 678 , 680 , 682 , 685 , 687 , 689 , 691 ,
693 , 695 , 697 , 700 , 702 , 704 , 706 , 708 , 710 , 712 , 714 , 716 , 717 , 719 , 721 ,
723 , 725 , 727 , 729 , 730 , 732 , 734 , 736 , 737 , 739 , 741 , 742 , 744 , 745 , 747 ,
748 , 750 , 752 , 753 , 754 , 756 , 757 , 759 , 760 , 761 , 763 , 764 , 765 , 767 , 768 ,
769 , 770 , 771 , 773 , 774 , 775 , 776 , 777 , 778 , 779 , 780 , 781 , 782 , 783 , 784 ,
784 , 785 , 786 , 787 , 788 , 788 , 789 , 790 , 791 , 791 , 792 , 792 , 793 , 794 , 794 ,
795 , 795 , 796 , 796 , 796 , 797 , 797 , 797 , 798 , 798 , 798 , 799 , 799 , 799 , 799 ,
799 , 799 , 799 , 799 , 799 , 800 , 799 , 799 , 799 , 799 , 799 , 799 , 799 , 799 , 799 ,
798 , 798 , 798 , 797 , 797 , 797 , 796 , 796 , 796 , 795 , 795 , 794 , 794 , 793 , 792 ,
792 , 791 , 791 , 790 , 789 , 788 , 788 , 787 , 786 , 785 , 784 , 784 , 783 , 782 , 781 ,
780 , 779 , 778 , 777 , 776 , 775 , 774 , 773 , 771 , 770 , 769 , 768 , 767 , 765 , 764 ,
763 , 761 , 760 , 759 , 757 , 756 , 754 , 753 , 752 , 750 , 748 , 747 , 745 , 744 , 742 ,
741 , 739 , 737 , 736 , 734 , 732 , 730 , 729 , 727 , 725 , 723 , 721 , 719 , 717 , 716 ,
714 , 712 , 710 , 708 , 706 , 704 , 702 , 700 , 697 , 695 , 693 , 691 , 689 , 687 , 685 ,
682 , 680 , 678 , 676 , 673 , 671 , 669 , 666 , 664 , 662 , 659 , 657 , 654 , 652 , 650 ,
647 , 645 , 642 , 640 , 637 , 635 , 632 , 630 , 627 , 624 , 622 , 619 , 616 , 614 , 611 ,
608 , 606 , 603 , 600 , 598 , 595 , 592 , 589 , 587 , 584 , 581 , 578 , 575 , 573 , 570 ,
567 , 564 , 561 , 558 , 555 , 553 , 550 , 547 , 544 , 541 , 538 , 535 , 532 , 529 , 526 ,
523 , 520 , 517 , 514 , 511 , 508 , 505 , 502 , 499 , 496 , 493 , 490 , 487 , 484 , 481 ,
478 , 474 , 471 , 468 , 465 , 462 , 459 , 456 , 453 , 450 , 447 , 443 , 440 , 437 , 434 ,
431 , 428 , 425 , 421 , 418 , 415 , 412 , 409 , 406 , 403 , 399 , 396 , 393 , 390 , 387 ,
384 , 381 , 378 , 374 , 371 , 368 , 365 , 362 , 359 , 356 , 352 , 349 , 346 , 343 , 340 ,
337 , 334 , 331 , 328 , 325 , 321 , 318 , 315 , 312 , 309 , 306 , 303 , 300 , 297 , 294 ,
291 , 288 , 285 , 282 , 279 , 276 , 273 , 270 , 267 , 264 , 261 , 258 , 255 , 252 , 249 ,
246 , 244 , 241 , 238 , 235 , 232 , 229 , 226 , 224 , 221 , 218 , 215 , 212 , 210 , 207 ,
204 , 201 , 199 , 196 , 193 , 191 , 188 , 185 , 183 , 180 , 177 , 175 , 172 , 169 , 167 ,
164 , 162 , 159 , 157 , 154 , 152 , 149 , 147 , 145 , 142 , 140 , 137 , 135 , 133 , 130 ,
128 , 126 , 123 , 121 , 119 , 117 , 114 , 112 , 110 , 108 , 106 , 104 , 102 , 99 , 97 , 95 ,
93 , 91 , 89 , 87 , 85 , 83 , 82 , 80 , 78 , 76 , 74 , 72 , 70 , 69 , 67 , 65 , 63 , 62 , 60 ,
58 , 57 , 55 , 54 , 52 , 51 , 49 , 47 , 46 , 45 , 43 , 42 , 40 , 39 , 38 , 36 , 35 , 34 , 32 ,
31 , 30 , 29 , 28 , 26 , 25 , 24 , 23 , 22 , 21 , 20 , 19 , 18 , 17 , 16 , 15 , 15 , 14 , 13 ,
12 , 11 , 11 , 10 , 9 , 8 , 8 , 7 , 7 , 6 , 5 , 5 , 4 , 4 , 3 , 3 , 3 , 2 , 2 , 2 , 1 , 1 , 1 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 1 , 1 , 2 , 2 , 2 , 3 , 3 , 3 ,
4 , 4 , 5 , 5 , 6 , 7 , 7 , 8 , 8 , 9 , 10 , 11 , 11 , 12 , 13 , 14 , 15 , 15 , 16 , 17 , 18 ,
19 , 20 , 21 , 22 , 23 , 24 , 25 , 26 , 28 , 29 , 30 , 31 , 32 , 34 , 35 , 36 , 38 , 39 ,
40 , 42 , 43 , 45 , 46 , 47 , 49 , 51 , 52 , 54 , 55 , 57 , 58 , 60 , 62 , 63 , 65 , 67 ,
69 , 70 , 72 , 74 , 76 , 78 , 80 , 82 , 83 , 85 , 87 , 89 , 91 , 93 , 95 , 97 , 99 , 102 ,
104 , 106 , 108 , 110 , 112 , 114 , 117 , 119 , 121 , 123 , 126 , 128 , 130 , 133 ,
135 , 137 , 140 , 142 , 145 , 147 , 149 , 152 , 154 , 157 , 159 , 162 , 164 , 167 ,
169 , 172 , 175 , 177 , 180 , 183 , 185 , 188 , 191 , 193 , 196 , 199 , 201 , 204 ,
207 , 210 , 212 , 215 , 218 , 221 , 224 , 226 , 229 , 232 , 235 , 238 , 241 , 244 ,
246 , 249 , 252 , 255 , 258 , 261 , 264 , 267 , 270 , 273 , 276 , 279 , 282 , 285 ,
288 , 291 , 294 , 297 , 300 , 303 , 306 , 309 , 312 , 315 , 318 , 321 , 325 , 328 ,
331 , 334 , 337 , 340 , 343 , 346 , 349 , 352 , 356 , 359 , 362 , 365 , 368 , 371 ,
374 , 378 , 381 , 384 , 387 , 390 , 393 , 396 };

#define	_PTIF	PIR3bits.PTIF

unsigned int index = 0;
void set_duty0(unsigned int duty);

void setupPWM(void)
{
PTCON0 = 0x00;	//Postscale 1:1, Prescale 1:1, Free Running
PTCON1 = 0x80;	//PWM time base is on, count up!
PWMCON0 = 0x20;	//Enable PWM0-1, Complementary
PWMCON1 = 0x40;
DTCON = 0x00;	//No dead-time

PTMRH=0;
PTMRL=0;

PTPERH=0;
PTPERL=0xC7;	// 20KHz PWM

PDC0H=0x00;
PDC0L=0x00;	//0% duty
/*
PDC1H=0;
PDC1L=0;
PDC2H=0;
PDC2L=0;
PDC3H=0;
PDC3L=0;
*/
OVDCOND = 0xFF;	//Override disabled
OVDCONS = 0;
FLTCONFIG = 0;	//Fault condition disabled
SEVTCMPH = 0;
SEVTCMPL = 0;
}

void set_duty0(unsigned int duty)
{
PDC0H = duty>>8;
PDC0L = duty&0xFF;
}

void main()
{
//	TRISA=0x00;
//	ANSEL0=0x00;
setupPWM();

while (1)
{
if (_PTIF == 1 && PTMRL >= 100)
{
set_duty0(sine[index]);
index++;
_PTIF = 0;
if (index >= 800) index = 0;
}
}
}