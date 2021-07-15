#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

void triangle(int x, int y)
{
    glColor3f(1,0,0);
    glBegin(GL_POLYGON); // drawing a Triangle
        glVertex2f(x,y);
        glVertex2f(x+400,y);
        glVertex2f(x+0,y+0);
    glEnd();
}
