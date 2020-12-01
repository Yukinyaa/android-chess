//
// Created by woong on 2020-12-01.
//

#ifndef ANDROID_CHESS_HJW_H
#define ANDROID_CHESS_HJW_H
#include "common_headers.h"

#define DOTM_MAGIC 0xBC
#define PBTN_MAGIC 0x25

const char king[10] =
{
        0b0001000,
        0b0001000,
        0b0111110,
        0b0001000,
        0b0001000,
        0b0111110,
        0b0011100,
        0b0011100,
        0b0111110,
        0b1111111
};


extern "C" JNIEXPORT jint JNICALL
Java_jwtc_android_chess_ChessView_writeDmtrix( JNIEnv* env, jobject thiz , jint piece, jint bw)
{
    int dotmfd = open("/dev/dotmatrix", O_RDWR);
    int err = errno;
    if (dotmfd < 0){
        __android_log_print(ANDROID_LOG_ERROR, "SSegmentWrite", "err opening dotm device, errno: %d\n", err);
        return 1;
    }
    unsigned char piecechar = (unsigned char)piece;
    write(dotmfd, &piecechar, 1); //testing write to device
    close(dotmfd);

    return 0;
}

#endif //ANDROID_CHESS_HJW_H
