#include<iostream>
#include<cmath>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
 
using namespace std;
 
void animatefunc(int value);
 
void rotateDisplayfunc(int value);

#include "NeoQuad.h"
 
 
void initializeRendering()
{
	glEnable(GL_DEPTH_TEST);
 
}
 
 
 
NeoQuad *neoQuad;
 
 
void drawHandler()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glTranslatef(-0, -0, -50);
	neoQuad->drawQuadcopter();
 
	
	glutSwapBuffers();
}
 
 
void resizeHandler(int w, int h)//Called when the window is resized
{
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);
 
	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
 
	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(80,                  //The camera angle
		(double)w / (double)h, //The width-to-height ratio
		1.0,                   //The near z clipping coordinate
		200.0);                //The far z clipping coordinate
}
 
 
void keypressHandler(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'd':
		neoQuad->rotationAngleY += (neoQuad->rotationAngleY > 360) ? -358 : 2;
		break;
	case 'a':
		neoQuad->rotationAngleY -= (neoQuad->rotationAngleY > 360) ? -358 : 2;
		break;
	case 's':
		neoQuad->rotationAngleX += (neoQuad->rotationAngleX > 360) ? -358 : 2;
		break;
	case 'w':
		neoQuad->rotationAngleX -= (neoQuad->rotationAngleX > 360) ? -358 : 2;
		break;
	case 'm':
		neoQuad->toggleAnimate();
		//neoQuad->rotateProps(0);
		break;
	case 13:
		exit(0);
			
	};
	glutPostRedisplay();
}
 
//void mouseHandler()
 
 
void animatefunc(int value)
{
	//neoQuad->rotateProps(0);
}
 
void rotateDisplayfunc(int value)
{
//	neoQuad->rotateDisplay(0);
 
}
 
int main(int argc, char** argv)
{
	glutInit(&argc, argv); //initialize glut 
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB); //initialize display mode
	glutInitWindowSize(500, 500); //window size
	glutCreateWindow("Zeeshan's 3D QuadCopter Model"); //create window
 
	initializeRendering();
 
	glutDisplayFunc(drawHandler);
	glutKeyboardFunc(keypressHandler);
	glutReshapeFunc(resizeHandler);
	neoQuad = new NeoQuad();
	//glutMouseFunc()
 
	glutTimerFunc(10, animatefunc, 0);
	//glutTimerFunc(rotationSpeed,rotateDisplay,0);
	glutMainLoop();
 
	return 0;
	
 
}

