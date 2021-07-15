#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include"shapes.h"
void triangle()
{
    int x = 300, y = 400;
    glColor3f(1,0,0);
    glBegin(GL_POLYGON); // drawing a Triangle
        glVertex2f(x,y);
        glVertex2f(x+400,y);
        glVertex2f(x+0,y+0);
    glEnd();
}
