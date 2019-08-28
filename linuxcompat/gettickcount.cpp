#ifndef _WIN32
#include "linuxcompat/linuxcompat.h"

#include <sys/time.h>
#include <cstddef>

unsigned long GetTickCount()
{
  struct timeval time_now;
  gettimeofday(&time_now, NULL);
  return time_now.tv_sec;
}

#endif
