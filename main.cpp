#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<iostream>
#include<stdio.h>
#include<process.h>
#include<ctime>
#define PI 3.14159

//using namespace std;

float thetha;
int radius = 30;
float xpos = 160;
float ypos = 170;
float speed = 0;
int times = 0;
float triangleX[5] = {250, 500, 700, 150, 450};
float triangleY[5] = {350, 500, 620, 450, 700};

void ball()
{
    glBegin(GL_POLYGON);
    glColor3f(0.33, 0.43, 0.9); //green
        for(int i=0; i<360; i++)
        {
            thetha = i*PI/180; //convert to radian
            glVertex2f(radius*cos(thetha),radius*sin(thetha));
        }
    glEnd();
}
void finish()
{
    glClearColor(0.99,0.99,0.29,1);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.17,0.17,0.17);
    glRasterPos3f(370,490,0);
    char msg1[] = "GAME OVER!";
    for(int i=0; i<strlen(msg1);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg1[i]);
    glutSwapBuffers();
    radius = 30;
    xpos = 200;
    ypos = 200;
    speed = 0;
    times = 0;
}


void check()
{
    for(int i=0; i<2; i++)
    {
        if(xpos>triangleX[i]-30 && xpos<triangleX[i]+140.0 && ypos>triangleY[i]-30.0 && ypos<triangleY[i]+50.0)
        {
            printf("\nYou touched the line ");
            glutDisplayFunc(finish);
            glutPostRedisplay();
        }
    }
}

void triangle(int x, int y)
{
    glColor3f(0.92,0.29,0.4);
    glBegin(GL_POLYGON); // drawing a Triangle
        glVertex2f(x,y);
        glVertex2f(x+50,y+50);
        glVertex2f(x+100,y);
    glEnd();
}

void rectangularBoundry()
{
    glColor3f(0.29,0.81,0.21);//yellow

    glBegin(GL_LINE_LOOP);   //coordinates of the boundry
        glVertex2f(100,100); //bottom left
        glVertex2f(100,900); //top left
        glVertex2f(900,900); //top right
        glVertex2f(900,100); //bottom right
    glEnd();
    glFlush();
}

void display()
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    check();
    //printf("x pos = %f y pos = %f trianglex[0] = %f triangley[0] = %f\n",xpos,ypos,triangleX[0],triangleY[0]);
    rectangularBoundry();

    //-----------------------Moving shapes------------------------
    glPushMatrix();
        glTranslatef(triangleX[0],triangleY[0],0);
        triangle(0,0);
        triangleY[0]-=0.05+speed;
        if(triangleY[0]<100)
        {
            triangleY[0]=500;
            triangleX[0] = rand()%720 +100;
            times ++;
            if(times == 5)
            {
                speed = 0;
                times = 0;
            }
            else
            {
                speed+=0.02;
            }
        }
    glPopMatrix();


    glPushMatrix();
        glTranslatef(triangleX[1],triangleY[1],0);
        triangle(0,0);
        triangleY[1]-=0.05+speed;
        if(triangleY[1]<100)
        {
            triangleY[1]=500;
            triangleX[1] = rand()%720 + 100;
            times ++;
            if(times == 5)
            {
                speed = 0;
                times = 0;
            }
            else
            {
                speed+=0.02;
            }
        }
    glPopMatrix();

    glPushMatrix();
        glTranslatef(triangleX[2],triangleY[2],0);
        triangle(0,0);
        triangleY[2]-=0.05+speed;
        if(triangleY[2]<100)
        {
            triangleY[2]=500;
            triangleX[2] = rand()%720 +100;
            times ++;
            if(times == 5)
            {
                speed = 0;
                times = 0;
            }
            else
            {
                speed+=0.02;
            }
        }
    glPopMatrix();

    glPushMatrix();
        glTranslatef(triangleX[3],triangleY[3],0);
        triangle(0,0);
        triangleY[3]-=0.05+speed;
        if(triangleY[3]<100)
        {
            triangleY[3]=500;
            triangleX[3] = rand()%720 +100;
            times ++;
            if(times == 5)
            {
                speed = 0;
                times = 0;
            }
            else
            {
                speed+=0.02;
            }
        }
    glPopMatrix();

    glPushMatrix();
        glTranslatef(triangleX[4],triangleY[4],0);
        triangle(0,0);
        triangleY[4]-=0.05+speed;
        if(triangleY[4]<100)
        {
            triangleY[4]=500;
            triangleX[4] = rand()%720 +100;
            times ++;
            if(times == 5)
            {
                speed = 0;
                times = 0;
            }
            else
            {
                speed+=0.02;
            }
        }
    glPopMatrix();


    //------------------------Circle-------------------------
    glPushMatrix();
        glTranslatef(xpos,ypos,0);
        ball();
    glPopMatrix();

    glutSwapBuffers();
    glutPostRedisplay();

    //printf("xpos : %f\t y ypos: %f\n",xpos,ypos);
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

        case GLUT_KEY_HOME:
            glutDisplayFunc(display);
            glutPostRedisplay();
            break;
	}
}
void init()// prepare the window for displaying
{
    glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,1000,0,1000);

}
void intro()
{
    glClearColor(0.99,0.99,0.84,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glRasterPos3f(360,900,0);
    char msg1[] = "BALL-DER-DASH!";
    for(int i=0; i<strlen(msg1);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg1[i]);

    glRasterPos3f(460,850,0);
    char msg2[] = "RULES!";
    for(int i=0; i<strlen(msg2);i++)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13,msg2[i]);

    glPushMatrix();
        glTranslatef(150,650,0);
        ball();
    glPopMatrix();
    glRasterPos3f(128,580,0);
        char msg4[] = "Ball";
        for(int i=0; i<strlen(msg4);i++)
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13,msg4[i]);

    glPushMatrix();
        glTranslatef(350,500,0);
        glScalef(0.3,0.3,1);
        rectangularBoundry();
    glPopMatrix();
    glRasterPos3f(460,480,0);
        char msg5[] = "Boundry";
        for(int i=0; i<strlen(msg5);i++)
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13,msg5[i]);

    glPushMatrix();
        glTranslatef(800,600,0);
        triangle(0,0);
    glPopMatrix();
    glRasterPos3f(797,560,0);
        char msg6[] = "Obstacles";
        for(int i=0; i<strlen(msg6);i++)
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13,msg6[i]);

    glColor3f(0.2,0.2,0.2);
    glRasterPos3f(120,310,0);
        char msg7[] = "Move the ball using left and right arrow keys and dodge the obstacles";
        for(int i=0; i<strlen(msg7);i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg7[i]);

    glRasterPos3f(390,260,0);
    char msg8[] = "Press HOME to start";
    for(int i=0; i<strlen(msg8);i++)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13,msg8[i]);

    glRasterPos3f(360,100,0);
    char msg3[] = "SUBMITTED BY";
    for(int i=0; i<strlen(msg3);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg3[i]);

    glRasterPos3f(80,50,0);
    char msg9[] = "1BY18S225 : DEEP RAKESH , 1BY18CS076 : KIRTHAN";
    for(int i=0; i<strlen(msg9);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg9[i]);


    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    srand(time(NULL)); // to use random function
    printf("Use arrow keys to move the circle");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(700, 700); //sets the initial window size
	glutCreateWindow("BALL-DER-DASH"); // creates the window with name line
	init();

	glutDisplayFunc(intro);

    glutSpecialFunc(key);// sets the special keyboard callback for the current window.
                         //The special keyboard callback is triggered when keyboard function or directional keys are pressed.
	glutMainLoop(); // enters the GLUT event processing loop
	return 0;
}
