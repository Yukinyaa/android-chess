//
// Created by User on 2020-12-01.
//

#ifndef ANDROID_CHESS_MASTER_TIMER_H
#define ANDROID_CHESS_MASTER_TIMER_H

#endif //ANDROID_CHESS_MASTER_TIMER_H


#include "common_headers.h"

pthread_t timer_thread = NULL;
int abort_timer;

time_t startTime = 0;
time_t pausedTime = 0;
time_t totalPausedTime = 0;


void WriteToDisplay(int value)
{
    unsigned char bytevalues[4];
    int fd, ret;

    __android_log_print(ANDROID_LOG_DEBUG, "cpptimer", "Writing : %d, tp : %d", value, totalPausedTime);

    bytevalues[0] = value / 1000;
    value = value % 1000;
    bytevalues[1] = value / 100;
    value = value % 100;
    bytevalues[2] = value / 10;
    value = value % 10;
    bytevalues[3] = value;

    fd = open("/dev/7segment", O_RDWR);
    if (fd < 0) {

        __android_log_print(ANDROID_LOG_ERROR, "cpptimer", "Device open error : /dev/7segment");
    }

    ret = write(fd, bytevalues, 4);
    if (ret < 0) {
        __android_log_print(ANDROID_LOG_ERROR, "cpptimer", "Write error : /dev/7segment");
    }

    close(fd);
}

void *TimerThread(void *data)
{
    __android_log_print(ANDROID_LOG_DEBUG, "cpptimer", "Timer Thread Started");
    startTime = time(NULL);
    totalPausedTime = 0;
    int timeOnDisplay = -1;
    while(abort_timer == false)
    {
        usleep(1000);
        int nowPausedTime = pausedTime == 0 ? 0  : time(NULL) - pausedTime;
        int nowTimer = time(NULL) - startTime - totalPausedTime - nowPausedTime;
        if(nowTimer == timeOnDisplay){}
        else {
            WriteToDisplay(nowTimer);
            timeOnDisplay = nowTimer;
        }
    }
    pthread_exit(0);
}

extern "C" JNIEXPORT jint JNICALL
Java_jwtc_android_chess_ChessView_startTimer(JNIEnv *env, jobject thiz) {
    __android_log_print(ANDROID_LOG_DEBUG, "cpptimer", "Timer Start Called");
    abort_timer = false;
    if(timer_thread != NULL)
    {
        abort_timer = true;
        pthread_join(timer_thread, NULL);
        abort_timer = false;

    }
    pthread_create(&timer_thread, NULL, TimerThread, (void*)NULL);


    return 0;
}


extern "C" JNIEXPORT jint JNICALL
Java_jwtc_android_chess_ChessView_pauseTimer(JNIEnv *env, jobject thiz) {
    __android_log_print(ANDROID_LOG_DEBUG, "cpptimer", "Pause");
    pausedTime = time(NULL);
    return 0;
}

extern "C" JNIEXPORT jint JNICALL
Java_jwtc_android_chess_ChessView_resumeTimer(JNIEnv *env, jobject thiz) {
    __android_log_print(ANDROID_LOG_DEBUG, "cpptimer", "Resume");
    if(pausedTime != 0)
    {
        totalPausedTime +=  time(NULL) -  pausedTime;
        pausedTime = 0;
    }
    return 0;
}