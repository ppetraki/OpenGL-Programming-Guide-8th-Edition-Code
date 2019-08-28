#ifndef __LINUX_COMPAT_H__
#define __LINUX_COMPAT_H__

#ifndef _WIN32
int Sleep(unsigned int usec);

unsigned long GetTickCount();
#endif //_WIN32

#endif //__LINUX_COMPAT_H__
