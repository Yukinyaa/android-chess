//
// Created by jihyuk on 2020-12-09.
//

#ifndef ANDROID_CHESS_LED_POSITION_H
#define ANDROID_CHESS_LED_POSITION_H

#include "common_headers.h"
#include <stdio.h>
#define LCD_MAGIC 0xBD
#define LCD_SET_CURSOR_POS _IOW(LCD_MAGIC, 0, int)



extern "C" JNIEXPORT jint JNICALL Java_jwtc_android_chess_ChessView_position( JNIEnv* env, jobject thiz, jint data)
{
    int input_num = (int)data;
    int fd = open("/dev/lcd",  O_RDWR);

    if(fd <0){fprintf(stderr, "error opening device \n"); return 1;}

    int pos = 16; // writing upper lcd line

    char temp[2] = {'-','-'};

    if(input_num == 0){temp[0] = 'a'; temp[1] = '8';}
    if(input_num == 1){temp[0] = 'b'; temp[1] = '8';}
    if(input_num == 2){temp[0] = 'c'; temp[1] = '8';}
    if(input_num == 3){temp[0] = 'd'; temp[1] = '8';}
    if(input_num == 4){temp[0] = 'e'; temp[1] = '8';}
    if(input_num == 5){temp[0] = 'f'; temp[1] = '8';}
    if(input_num == 6){temp[0] = 'g'; temp[1] = '8';}
    if(input_num == 7){temp[0] = 'h'; temp[1] = '8';}
    if(input_num == 8){temp[0] = 'a'; temp[1] = '7';}
    if(input_num == 9){temp[0] = 'b'; temp[1] = '7';}
    if(input_num == 10){temp[0] = 'c'; temp[1] = '7';}
    if(input_num == 11){temp[0] = 'd'; temp[1] = '7';}
    if(input_num == 12){temp[0] = 'e'; temp[1] = '7';}
    if(input_num == 13){temp[0] = 'f'; temp[1] = '7';}
    if(input_num == 14){temp[0] = 'g'; temp[1] = '7';}
    if(input_num == 15){temp[0] = 'h'; temp[1] = '7';}
    if(input_num == 16){temp[0] = 'a'; temp[1] = '6';}
    if(input_num == 17){temp[0] = 'b'; temp[1] = '6';}
    if(input_num == 18){temp[0] = 'c'; temp[1] = '6';}
    if(input_num == 19){temp[0] = 'd'; temp[1] = '6';}
    if(input_num == 20){temp[0] = 'e'; temp[1] = '6';}
    if(input_num == 21){temp[0] = 'f'; temp[1] = '6';}
    if(input_num == 22){temp[0] = 'g'; temp[1] = '6';}
    if(input_num == 23){temp[0] = 'h'; temp[1] = '6';}
    if(input_num == 24){temp[0] = 'a'; temp[1] = '5';}
    if(input_num == 25){temp[0] = 'b'; temp[1] = '5';}
    if(input_num == 26){temp[0] = 'c'; temp[1] = '5';}
    if(input_num == 27){temp[0] = 'd'; temp[1] = '5';}
    if(input_num == 28){temp[0] = 'e'; temp[1] = '5';}
    if(input_num == 29){temp[0] = 'f'; temp[1] = '5';}
    if(input_num == 30){temp[0] = 'g'; temp[1] = '5';}
    if(input_num == 31){temp[0] = 'h'; temp[1] = '5';}
    if(input_num == 32){temp[0] = 'a'; temp[1] = '4';}
    if(input_num == 33){temp[0] = 'b'; temp[1] = '4';}
    if(input_num == 34){temp[0] = 'c'; temp[1] = '4';}
    if(input_num == 35){temp[0] = 'd'; temp[1] = '4';}
    if(input_num == 36){temp[0] = 'e'; temp[1] = '4';}
    if(input_num == 37){temp[0] = 'f'; temp[1] = '4';}
    if(input_num == 38){temp[0] = 'g'; temp[1] = '4';}
    if(input_num == 39){temp[0] = 'h'; temp[1] = '4';}
    if(input_num == 40){temp[0] = 'a'; temp[1] = '3';}
    if(input_num == 41){temp[0] = 'b'; temp[1] = '3';}
    if(input_num == 42){temp[0] = 'c'; temp[1] = '3';}
    if(input_num == 43){temp[0] = 'd'; temp[1] = '3';}
    if(input_num == 44){temp[0] = 'e'; temp[1] = '3';}
    if(input_num == 45){temp[0] = 'f'; temp[1] = '3';}
    if(input_num == 46){temp[0] = 'g'; temp[1] = '3';}
    if(input_num == 47){temp[0] = 'h'; temp[1] = '3';}
    if(input_num == 48){temp[0] = 'a'; temp[1] = '2';}
    if(input_num == 49){temp[0] = 'b'; temp[1] = '2';}
    if(input_num == 50){temp[0] = 'c'; temp[1] = '2';}
    if(input_num == 51){temp[0] = 'd'; temp[1] = '2';}
    if(input_num == 52){temp[0] = 'e'; temp[1] = '2';}
    if(input_num == 53){temp[0] = 'f'; temp[1] = '2';}
    if(input_num == 54){temp[0] = 'g'; temp[1] = '2';}
    if(input_num == 55){temp[0] = 'h'; temp[1] = '2';}
    if(input_num == 56){temp[0] = 'a'; temp[1] = '1';}
    if(input_num == 57){temp[0] = 'b'; temp[1] = '1';}
    if(input_num == 58){temp[0] = 'c'; temp[1] = '1';}
    if(input_num == 59){temp[0] = 'd'; temp[1] = '1';}
    if(input_num == 60){temp[0] = 'e'; temp[1] = '1';}
    if(input_num == 61){temp[0] = 'f'; temp[1] = '1';}
    if(input_num == 62){temp[0] = 'g'; temp[1] = '1';}
    if(input_num == 63){temp[0] = 'h'; temp[1] = '1';}

    ioctl(fd, LCD_SET_CURSOR_POS, &pos, _IOC_SIZE(LCD_SET_CURSOR_POS));
    write(fd,&temp, sizeof(char) * 2);


    close (fd);

    return 0;

}




#endif //ANDROID_CHESS_LED_POSITION_H
