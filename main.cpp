#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#define PI 3.14159

//using namespace std;

float thetha;
int radius = 30;
int xpos = 200.0;
int ypos = 200.0;
int triangleY = 0;

void triangle(int x, int y)
{
    glColor3f(0.92,0.29,0.4);
    glBegin(GL_POLYGON); // drawing a Triangle
        glVertex2f(x,0);
        glVertex2f(x+50,50);
        glVertex2f(x+100,0);
    glEnd();
}

void rectangularBoundry()
{
    glColor3f(1,0,0);

    glBegin(GL_LINE_LOOP);   //coordinates of the boundry
        glVertex2f(100,100); //bottom left
        glVertex2f(100,900); //top left
        glVertex2f(900,900); //top right
        glVertex2f(900,100); //bottom right
    glEnd();
}
void init()// prepare the window for displaying
{
    glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,1000,0,1000);

}
void draw_moving_circle()
{
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(1,0,0);

    glBegin(GL_LINE_LOOP);   //coordinates of the boundry
        glVertex2f(100,100); //bottom left
        glVertex2f(100,900); //top left
        glVertex2f(900,900); //top right
        glVertex2f(900,100); //bottom right
    glEnd();

    glPushMatrix();
    glTranslatef(300,200,0);
    triangle(0,0);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.33, 0.43, 0.9);
        for(int i=0; i<360; i++)
        {
            thetha = i*PI/180; //convert to radian
            glVertex2f(xpos+radius*cos(thetha),ypos+radius*sin(thetha));
        }


    glEnd();

    //glFlush();
	glutSwapBuffers();

}
void key(int key, int x, int y) // function to make the user able to deal with the system
{
	switch (key)
	{
        case GLUT_KEY_LEFT:
            if(xpos < 100 + radius + 2)
                xpos = xpos + 0;
            else
                xpos = xpos - 5;

            glutPostRedisplay();
            break;

        case GLUT_KEY_RIGHT:
            if(xpos < 900 - radius - 4)
                xpos = xpos + 5;
            else
                xpos = xpos + 0;
            glutPostRedisplay();
            break;

        case GLUT_KEY_UP:
            if(ypos < 900 - radius - 2)
                ypos = ypos + 5;
            else
                ypos = ypos + 0;
            glutPostRedisplay();
            break;

        case GLUT_KEY_DOWN:
            if(ypos < 100 + radius + 2)
                ypos = ypos + 0;
            else
                ypos = ypos - 5;
            glutPostRedisplay();
            break;
	}
}

int main(int argc, char** argv)
{
    printf("Use arrow keys to move the circle");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(700, 700); //sets the initial window size
	glutCreateWindow("TEST Proj"); // creates the window with name line
	init();
	rectangularBoundry();
	glutDisplayFunc(draw_moving_circle);

	glutSpecialFunc(key);// sets the special keyboard callback for the current window.
                         //The special keyboard callback is triggered when keyboard function or directional keys are pressed.
	glutMainLoop(); // enters the GLUT event processing loop
	return 0;
}
