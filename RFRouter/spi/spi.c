#include "spi.h"
uint8_t SPI_SendByte(uint8_t data)
{
    uint8_t ret_val;
    SPDR = data;
    while(!(SPSR & (1<<SPIF)));
    ret_val=SPDR;
    return ret_val;
}