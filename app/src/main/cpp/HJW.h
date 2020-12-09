//
// Created by woong on 2020-12-01.
//

#ifndef ANDROID_CHESS_HJW_H
#define ANDROID_CHESS_HJW_H
#include "common_headers.h"


#define DOTM_MAGIC 0xBC
#define PBTN_MAGIC 0x25

const char queen_black[10] =
        {
                0b0000000,
                0b0000000,
                0b1001001,
                0b1001001,
                0b1101011,
                0b1111111,
                0b1111111,
                0b1111111,
                0b0111110,
                0b0111110
        };

const char queen_white[10] =
        {
                0b0000000,
                0b0000000,
                0b1001001,
                0b1001001,
                0b1101011,
                0b1010101,
                0b1000001,
                0b1000001,
                0b0100010,
                0b0111110
        };

const char pawn_black[10] =
        {
                0b0001000,
                0b0011100,
                0b0001000,
                0b0001000,
                0b0011100,
                0b0001000,
                0b0001000,
                0b0011100,
                0b0111110,
                0b1111111
        };

const char pawn_white[10] =
        {
                0b0001000,
                0b0010100,
                0b0001000,
                0b0001000,
                0b0010100,
                0b0001000,
                0b0001000,
                0b0010100,
                0b0100010,
                0b1000001
        };

const char knight_black[10] =
        {
                0b0001010,
                0b0111110,
                0b0111110,
                0b0111110,
                0b0001110,
                0b0001110,
                0b0001110,
                0b0011110,
                0b0111110,
                0b0111110
        };
const char knight_white[10] =
        {
                0b0001010,
                0b0111110,
                0b0100010,
                0b0111110,
                0b0001010,
                0b0001010,
                0b0001010,
                0b0010010,
                0b0100010,
                0b0111110
        };

const char rook_black[10] =
        {
                0b0101010,
                0b0111110,
                0b0011100,
                0b0011100,
                0b0011100,
                0b0011100,
                0b0011100,
                0b0111110,
                0b0111110,
                0b1111111
        };
const char rook_white[10] =
        {
                0b0101010,
                0b0111110,
                0b0010100,
                0b0010100,
                0b0010100,
                0b0010100,
                0b0010100,
                0b0100010,
                0b0100010,
                0b1111111
        };

const char bishop_black[10] =
        {
                0b0011100,
                0b0011100,
                0b1111111,
                0b1111111,
                0b1111111,
                0b0011100,
                0b0011100,
                0b0011100,
                0b0011100,
                0b0011100
        };

const char bishop_white[10] =
        {
                0b0011100,
                0b0010100,
                0b1110111,
                0b1000001,
                0b1110111,
                0b0010100,
                0b0010100,
                0b0010100,
                0b0010100,
                0b0011100
        };

const char king_black[10] =
        {
                0b0001000,
                0b0011100,
                0b0001000,
                0b1001001,
                0b1001001,
                0b1101011,
                0b1111111,
                0b1111111,
                0b1111111,
                0b0111110
        };


const char king_white[10] =
        {
                0b0001000,
                0b0011100,
                0b0001000,
                0b1001001,
                0b1001001,
                0b1101011,
                0b1010101,
                0b1000001,
                0b1000001,
                0b0111110
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

//    unsigned char piecechar = (unsigned char)piece;
    if(bw == 0) {
        unsigned char piecechar = (unsigned char)piece;
        write(dotmfd, &piecechar, 1); //testing write to device
    }else{
        int temp = piece + 6;
        unsigned char piecechar = (unsigned char)temp;
        write(dotmfd, &piecechar, 1); //testing write to device
        //  write(dotmfd_w, &piecechar, 1); //testing write to device
    }

    close(dotmfd);
//0 black 1 white
    return 0;
}

#endif //ANDROID_CHESS_HJW_H
