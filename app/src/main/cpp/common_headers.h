//
// Created by woong on 2020-12-01.
//

#ifndef ANDROID_CHESS_COMMON_HEADERS_H
#define ANDROID_CHESS_COMMON_HEADERS_H

#include <jni.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <android/log.h>
#include <errno.h>


static const int PAWN = 0;
static const int KNIGHT = 1;
static const int BISHOP = 2;
static const int ROOK = 3;
static const int QUEEN = 4;
static const int KING = 5;

#endif //ANDROID_CHESS_COMMON_HEADERS_H
