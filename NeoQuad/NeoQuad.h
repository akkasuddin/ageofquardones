#ifndef NEOQUAD_H
#define NEOQUAD_H

#include <ctime>

#include "Quadrotor.h"

using namespace std;

class NeoQuad:public Quadrotor
{
private:
 
	clock_t startTime;
	float propAngle;
	unsigned int propSpeed;
	bool animate;
 
	void drawEllipsoid(unsigned int uiStacks, unsigned int uiSlices, float fA, float fB, float fC);
	void drawBlade();
	void drawPropellers(int rotorDirection);
 
public:
	NeoQuad();
	void toggleAnimate();
	void drawQuadcopter();
	void rotateProps();
};

#endif