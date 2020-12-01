#include <jni.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <android/log.h>
#include <errno.h>


#define DOTM_MAGIC 0xBC
#define PBTN_MAGIC 0x25

const char name1[10] =
		{
				0b0010000,
				0b0111000,
				0b0010000,
				0b0101010,
				0b0010011,
				0b0010010,
				0b0111100,
				0b0001000,
				0b0010100,
				0b0001000
		};

extern "C" JNIEXPORT jint JNICALL
Java_jwtc_android_chess_ChessView_writeDmtrix( JNIEnv* env, jobject thiz , jint data)
{
	int dotmfd = open("/dev/dotmatrix", O_RDWR);
	int err = errno;
	if (dotmfd < 0){
		__android_log_print(ANDROID_LOG_ERROR, "SSegmentWrite", "err opening dotm device, errno: %d\n", err);
		return 1;
	}

    write(dotmfd, name1, 10); //testing write to device
	close(dotmfd);

	return 0;
}