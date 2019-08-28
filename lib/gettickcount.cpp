#ifndef _WIN32
#include "gettickcount.h"

unsigned long GetTickCount()
{
  struct timeval time_now;
  gettimeofday(&time_now, NULL);
  return time_now.tv_sec;
}

#endif
