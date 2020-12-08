#include "common_headers.h"

#include "HJW.h"
#include "timer.h"

//*******************************************//
// checklist if not working:
//
// at java class file
//   static {system.LoadLibrary("FPGA-lib")}
// at device:
//   insmod /sdcard/<name>.ko
//   chmod 666 /dev/<name>
//   setenforce 0
//******************************************//