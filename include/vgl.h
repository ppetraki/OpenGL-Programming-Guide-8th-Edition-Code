#ifndef __VGL_H__
#define __VGL_H__

#define GLEW_STATIC

#include <GL/glew.h>


#define FREEGLUT_STATIC

#include <GL/freeglut.h>

// Ugly I know but this is just example code and it frankly
// should have built correctly the first time.
#include <unistd.h>
#define Sleep(A) usleep(A)

//#  ifdef _DEBUG
//#     pragma comment (lib, "freeglut_staticd.lib")
//#  else
//#     pragma comment (lib, "freeglut_static.lib")
//#  endif

#define BUFFER_OFFSET(x)  ((const void*) (x))
#endif /* __VGL_H__ */
