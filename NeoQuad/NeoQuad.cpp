#include "NeoQuad.h"
#include <GL/glut.h>
#include <cmath>

#include <ctime>
using namespace std;

#ifndef Pi

#define Pi 3.1415926535897932384626433832795
#endif
NeoQuad::NeoQuad()
	{
	      
	    propAngle = 0.0;
	    propSpeed = 2;
	    animate = true;
	    startTime = clock();
	}
void NeoQuad::drawEllipsoid(unsigned int uiStacks, unsigned int uiSlices, float fA, float fB, float fC)
{
	float tStep = (Pi) / (float)uiSlices;
	float sStep = (Pi) / (float)uiStacks;
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	for (float t = -Pi / 2; t <= (Pi / 2) + .0001; t += tStep)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (float s = -Pi; s <= Pi + .0001; s += sStep)
		{
		  
			glNormal3f(fA * cos(t) * cos(s), fB * cos(t) * sin(s), fC * sin(t));
			glVertex3f(fA * cos(t) * cos(s), fB * cos(t) * sin(s), fC * sin(t));
			glNormal3f(fA * cos(t + tStep) * cos(s), fB * cos(t + tStep) * sin(s), fC * sin(t + tStep));
			glVertex3f(fA * cos(t + tStep) * cos(s), fB * cos(t + tStep) * sin(s), fC * sin(t + tStep));
		}
		glEnd();
	}
}
 
void NeoQuad::drawBlade()
{
	//Draw blade
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 10.0f, 0.0f);
	glVertex3f(0.0f, 10.0f, 0.0f);
	glVertex3f(0.5f, 10.0f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.0f);
	glEnd();
}
 
void NeoQuad::drawPropellers(int rotorDirection)
{
	glPushMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 0.25f);
	gluCylinder(quadricObj, 0.25f, 0.25f, 3.0f, 7.0f, 2.0f);
	glTranslatef(0.0f, 0.0f, 3.0f);
	glutSolidTorus(.5f, 10.0f,5.0f, 20.0f);
	
	if (rotorDirection)
		glRotatef(propAngle, 0.0f, 0.0f, 1.0f);
	else
		glRotatef(-propAngle, 0.0f, 0.0f, 1.0f);
 
	drawBlade();
	glRotatef(120.0f, 0.0f, 0.0f, 1.0f);
	drawBlade();
	glRotatef(120.0f, 0.0f, 0.0f, 1.0f);
	drawBlade();
 
	glPopMatrix();
 
}
 
void NeoQuad::drawQuadcopter()
{
	rotateProps();
	glPushMatrix();//push current matrix to stack
	glRotatef(rotationAngleY, 0.0f, 1.0f, 0.0f);
	glRotatef(rotationAngleX, 1.0f, 0.0f, 0.0f);
	glRotatef(rotationAngleZ, 0.0f, 0.0f, 1.0f);
 
 
	//Draw Axes
	drawAxes();
 
	glColor4f(.75f, .75f, .75f, 0.25f);
	
	//draw body
	drawEllipsoid(10, 5, 15, 5, 5);
	glTranslatef(15.0f, 0.0f, 0.0f);
	gluSphere(quadricObj, 5.0f, 10, 10); //draw head
	glTranslatef(-15.0f, 0.0f, 0.0f);
	
	//draw Arms
	glPushMatrix();    
	glTranslatef(20.0f, 5.0f, 20.0f);
	glRotatef(-135.0f, 0.0f, 1.0f, 0.0f);
	gluCylinder(quadricObj, 0.25f, 0.25f, 40.0f*sqrtf(2), 5.0f, 2.0f);
	
	//Draw 
	glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
	//drawAxes();
	drawPropellers(1);

	glTranslatef(20.0f*sqrt(2), -20.0f*sqrt(2), 0.0f);
	glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
	//drawAxes();
	drawPropellers(0);


	glTranslatef(20.0f*sqrt(2), -20.0f*sqrt(2), 0.0f);
	glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
	//drawAxes();
	drawPropellers(1);

	glTranslatef(20.0f*sqrt(2), -20.0f*sqrt(2), 0.0f);
	glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
	//drawAxes();
	drawPropellers(0);


	//glRotatef(-135.0f, 1.0f, 0.0f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(20.0f, 5.0f, -20.0f);
	glRotatef(-45.0f, 0.0f, 1.0f, 0.0f);
	gluCylinder(quadricObj, 0.25f, 0.25f, 40.0f*sqrtf(2), 5.0f, 2.0f);
	glPopMatrix();

	glPopMatrix();
}
 
void NeoQuad::rotateProps()
{
	if (animate)
	{
		double timeInSec = (clock()-startTime)/(double) CLOCKS_PER_SEC;
		
		propAngle += 10000*timeInSec;
		
	}
	startTime = clock();
 
}
 
void NeoQuad::toggleAnimate()
{
	animate = !animate;
}
 