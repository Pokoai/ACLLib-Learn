#include "acllib.h"
#include <stdio.h>
#include <math.h> 

#define M_PI 3.1415926
#define ANGLE 5
#define Pi 180
#define ORX 300
#define ORY 300
#define R 100

void rotLine(int orx, int ory, int r, int angle)
{
    const double rad = M_PI / Pi;

    double x = orx + r * sin(angle * rad);
    double y = ory + r * cos(angle * rad);

    line(orx, ory, x, y);
}

void timerListener(int id)
{
    static int cnt = 0;
    int angle = Pi - cnt * ANGLE;
    beginPaint();
    
    if ( cnt %2 == 0) {
    	setPenColor(RED); 
	} else {
		setPenColor(GREEN);
	}
    rotLine(ORX, ORY, R, angle);
    endPaint();
    cnt++;
}

int Setup()
{
    initWindow("动线生成圆饼图案", DEFAULT, DEFAULT, 800, 700);
    
    beginPaint();
    setBrushColor(BLACK);
    rectangle(0, 0, 800, 700);
    endPaint();

    registerTimerEvent(timerListener);
    startTimer(0, 500);

    return 0; 
}
