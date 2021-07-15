#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#define PI 3.14159
int radius, xcord, ycord;

void display(void)
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    /*
    //x axis
    glColor3ub(254,0,0);
    glBegin(GL_LINES);
        glVertex2f(-100,0);
        glVertex2f(100,0);
    glEnd();

    //y axis
    glColor3ub(31,255,0);
    glBegin(GL_LINES);
        glVertex2f(0,-100);
        glVertex2f(0,100);
    glEnd();

    */



    //circle, cos = xaxis, sin = yaxis

    radius = 30;
    xcord = 150, ycord = 100; //x and y coordinates of circle
    float thetha;

    glColor3ub(84, 109, 229);
    glBegin(GL_POLYGON);
        for(int i=0; i<360; i++)
        {
            thetha = i*PI/180; //convert to radian
            glVertex2f(xcord+radius*cos(thetha),ycord+radius*sin(thetha));
        }

    glEnd();

    /*glutPostOverlayRedisplay();  // call display function again and again
    glutSwapBuffers();      // show the output
    */
}
void key(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		xcord--;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		xcord++;
		glutPostRedisplay();
		break;


	}



}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("TEST");
    gluOrtho2D(0,500,0,500);
    //glutInitWindowSize(500,500);

    glutDisplayFunc(display);
    glutSpecialFunc(key);
    glutMainLoop();
    return 0;
}
