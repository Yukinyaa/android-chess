//
// Created by jihyuk on 2020-12-06.
//

#ifndef ANDROID_CHESS_LED_TURN_H
#define ANDROID_CHESS_LED_TURN_H

#include <string.h>
#include "common_headers.h"

#define LCD_MAGIC 0xBD
#define LCD_SET_CURSOR_POS _IOW(LCD_MAGIC, 0, int)

//1 -> illegal move
//2 -> GameOver
extern "C" JNIEXPORT jint JNICALL Java_jwtc_android_chess_ics_ICSClient_showLCD( JNIEnv* env, jobject thiz, jint data)
{
    int input_num = (int)data;
    int fd = open("/dev/lcd", O_WRONLY);

    if(fd <0){fprintf(stderr, "error opening device \n"); return 1;}

    int pos = 0; // writing upper lcd line


    if (input_num == 1 ){
        ioctl(fd, LCD_SET_CURSOR_POS, &pos, _IOC_SIZE(LCD_SET_CURSOR_POS));
        write(fd,"ILLEGAL MOVE", strlen("ILLEGAL MOVE"));
    }//illegal move
    if (input_num == 2 ){}


    pos = 16; //writing lower lcd line

    close (fd);

    return 0;

}


#endif //ANDROID_CHESS_LED_TURN_H
