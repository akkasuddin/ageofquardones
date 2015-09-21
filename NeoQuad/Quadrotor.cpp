#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include"Quadrotor.h"


Quadrotor::Quadrotor()
	{
	  axisLength = 20;
	  rotationSpeed = 5;
	  
	  rotationAngleX = 0;
	  rotationAngleY = 0;
	  rotationAngleZ = 0;
		quadricObj = gluNewQuadric();
	}
void Quadrotor::drawAxes()
{
	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);	glVertex3f(axisLength, 0.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);	glVertex3f(0.0f, axisLength, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);	glVertex3f(0.0f, 0.0f, axisLength);
	glEnd();
	glPopMatrix();
}

void Quadrotor::rotateDisplay(int value)
{
	rotationAngleY += (rotationAngleY > 360) ? -358 : 2;
	//glutTimerFunc(rotationSpeed, &Quadrotor::rotateDisplay, 0);
	glutPostRedisplay();
	
 
}

Quadrotor::~Quadrotor()
	{
		gluDeleteQuadric(quadricObj);
	}