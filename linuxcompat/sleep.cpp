#include "linuxcompat/linuxcompat.h"

#include <unistd.h>

int Sleep(unsigned int usec) { return usleep(usec); }
