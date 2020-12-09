//
// Created by jihyuk on 2020-12-01.
//

#ifndef ANDROID_CHESS_LED_TURN_H
#define ANDROID_CHESS_LED_TURN_H

#include "common_headers.h"



extern "C" JNIEXPORT jint JNICALL Java_jwtc_chess_GameControl_showTurn( JNIEnv* env, jobject thiz, jint data)
{
    int input = (int)data;
    int turnfd = open("/dev/led", O_RDWR);
    int err = errno;
    /*
    if(turnfd < 0 ){
        __android_log_print(ANDROID_LOG_ERROR, "SSegmentWrite", "err opening led device, errno: %d\n", err);
        return 1;
    }*/
    int inputOdd [1] = {204};
    int inputEven[1] = {51};
    if(input %2 == 0){write(turnfd, &inputOdd,1);}
    else               {write(turnfd, &inputEven, 1);}

    close (turnfd);

    return 0;

}


#endif //ANDROID_CHESS_LED_TURN_H
