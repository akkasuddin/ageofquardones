#ifndef QUADROTOR_H
#define QUADROTOR_H
 
 
#include<GL/glu.h>
class Quadrotor
{
protected:
 
	float axisLength;
	unsigned int rotationSpeed;
 
 
	GLUquadric *quadricObj;
	void drawAxes();
 
public:
 
	float rotationAngleX;
	float rotationAngleY;
	float rotationAngleZ;
	Quadrotor(void);

 
	void rotateDisplay(int value);
	~Quadrotor(void);
};
#endif
