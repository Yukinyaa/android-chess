//
// Created by jihyuk on 2020-12-09.
//

#ifndef ANDROID_CHESS_LED_CHECK_H
#define ANDROID_CHESS_LED_CHECK_H

#include "common_headers.h"
#include <stdio.h>
#define LCD_MAGIC 0xBD
#define LCD_SET_CURSOR_POS _IOW(LCD_MAGIC, 0, int)

extern "C" JNIEXPORT jint JNICALL Java_jwtc_android_chess_ChessView_check( JNIEnv* env, jobject thiz, jint data)
{
    int input_num = (int)data;
    int fd = open("/dev/lcd",  O_RDWR);

    if(fd <0){fprintf(stderr, "error opening device \n"); return 1;}

    int pos = 0; // writing upper lcd line

    char temp[5]={'c','h','e','c','k'};
    char empty[5] = {' ', ' ', ' ', ' ', ' '};
    if (input_num == 2 ){
        ioctl(fd, LCD_SET_CURSOR_POS, &pos, _IOC_SIZE(LCD_SET_CURSOR_POS));
        write(fd,temp, sizeof(char) * 5);
    }//check
    else {
        ioctl(fd, LCD_SET_CURSOR_POS, &pos, _IOC_SIZE(LCD_SET_CURSOR_POS));
        write(fd,empty, sizeof(char) * 5);
    }



    pos = 16; //writing lower lcd line

    close (fd);

    return 0;

}










#endif //ANDROID_CHESS_LED_CHECK_H
