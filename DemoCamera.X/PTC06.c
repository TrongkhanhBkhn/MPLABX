#include "PTC06.h"
BYTE length_photo[2];
DWORD photo_len;

BYTE reset_cmd[] =
{
	0x56,
	0x00,
	0x26,
	0x00,
        0x00
};
BYTE reset_rcv [] =
{
	0x76,
	0x00,
	0x26,
	0x00
};
BYTE start_photo_cmd [] =
{
	0x56,
	0x00,
	0x36,
	0x01,
	0x00
};
BYTE start_photo_rcv [] =
{
	0x76,
	0x00,
	0x36,
	0x00,
	0x00
};
BYTE read_len_cmd [] =
{
	0x56,
	0x00,
	0x34,
	0x01,
	0x00
};
BYTE read_len_rcv [] =
{
	0x76,
	0x00,
	0x34,
	0x00,
	0x04,
	0x00,
	0x00
};
BYTE get_photo_cmd [] =
{
	0x56,
	0x00,
	0x32,
	0x0C,
	0x00,
	0x0A,

	0x00,
	0x00,
	0x00,
	0x00,

	0x00,
	0x00,
	0x00,
	0x00,

	0x00,
	0xFF

};
BYTE get_photo_rcv [] =
{
	0x76,
	0x00,
	0x32,
	0x00,
	0x00
};

BYTE set_compress_cmd [] =
{
	0x56,
	0x00,
	0x31,
	0x05,
	0x01,
	0x01,
	0x12,
	0x04,
	0x80
};

BYTE compress_rate_rcv [] =
{
	0x76,
	0x00,
	0x31,
	0x00,
	0x00
};
void sendByte(BYTE byte){
    ConsolePut(byte);
}
void sendComand(BYTE rxbuffer[], WORD len){
    WORD i = 0;
    for(i = 0; i<len; i++){
        sendByte(rxbuffer[i]);
    }
}
BYTE getCommand( BYTE rxbuffer[], WORD len){
    BYTE i=0;
    for(i=0; i<len; i++){
         rxbuffer[i] = ConsoleGet();
         UART1Put(rxbuffer[i]);
    }
    if(rxbuffer[0] == CMD_CMR)
        return 1;
    else
        return 0;
}
BYTE sendReset(void){
    BYTE rxbuffer[10];
    BYTE i = 0;
    sendComand(reset_cmd, 5);
    if(!getCommand(rxbuffer, 4)) return 0;
    for( i =0; i<4; i++)
        if(rxbuffer[i]!= reset_rcv[i]) return 0;
    return 1;
}
BYTE sendGetLength(void){
    BYTE rxbuffer[10];
    BYTE i = 0;
    sendComand(read_len_cmd, 5);
    if(!getCommand(rxbuffer, 9)) return 0;
    for(i = 0; i<9; i++)
        if(rxbuffer[i]!=read_len_rcv[i]) return 0;
    length_photo[0] = rxbuffer[7];
    length_photo[1] = rxbuffer[8];
    setPhotoLen(length_photo[0], length_photo[1]);
    return 1;
}
void setPhotoLen(BYTE len1, BYTE len2){
    photo_len = len1*0x100 +len2;
}
BYTE sendStartPhoto(void){
    BYTE rxbuffer[5];
    BYTE i = 0;
    sendComand(start_photo_cmd, 5);
    if(!getCommand(rxbuffer, 5)) return 0;
    for(i = 0; i<9; i++)
        if(rxbuffer[i]!= start_photo_rcv[i]) return 0;
    return 1;
}

DWORD sendGetPhoto(BYTE rxbuffer[]){
    DWORD i = 0;
    if(photo_len >8000) return 0;
    sendComand(get_photo_cmd, 16);
    if(!getCommand(rxbuffer, 10 + photo_len)) return 0;
    for(i = 0; i<5; i++)
        if(rxbuffer[i]!=get_photo_rcv[i]) return 0;
    for(i = 0; i<5; i++)
        if(rxbuffer[i+5]!=get_photo_cmd[i]) return 0;
    if (*(rxbuffer +5) != 0xFF ||*(rxbuffer +6) != 0xD8 ||
		*(rxbuffer +3 + photo_len) != 0xFF ||*(rxbuffer +4 +photo_len)!= 0xD9)
		return 0;
    for (i = 0; i < photo_len; i++)
		*(rxbuffer +i) = *(rxbuffer +i+5);
    return photo_len;
}
DWORD takePhoto(BYTE rxbuffer[]){
    DWORD len;
    if(!sendStartPhoto()) goto error_exit;
    if(!sendGetLength()) goto error_exit;
    len = sendGetPhoto(rxbuffer);
    if(len = 0) goto error_exit;
    return len;
    error_exit:
    return 0;
}