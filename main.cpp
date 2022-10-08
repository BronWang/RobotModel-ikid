#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "robotModel.h"

extern robotLink robotModel[26];
extern double theta;
extern double sx;
extern double sy;
int main(void) {	
	robotStart();
	double com[3];
	Calc_com(com);
	printf("ÖØÐÄ £º%f %f %f", com[0], com[1], com[2]);
	trajPlan();
	anglePlan(PI / 6);
	trajPlan();
	anglePlan(PI / 6);
	trajPlan();
	trajPlan();
	trajPlan();
	trajPlan();
	trajPlan();
}