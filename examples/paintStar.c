#include "acllib.h"
#include <stdio.h>
#include <math.h>
//#inlcude <time.h>

#define M_PI		3.14159265358979323846

// 绘制星星
// (x,y): 五角星外围圆的圆心坐标；r: 外围圆半径； 
// 顶点坐标计算可参考：https://blog.csdn.net/djh123456021/article/details/78306250 
void paintStar(int x, int y, double r)
{
	double rad = M_PI / 180; // 弧度转换 
	double SR1 = r * sin(72 * rad), CR1 = r * cos(72 * rad);
	double SR2 = r * sin(54 * rad), CR2 = r * cos(54 * rad);
	
	int xA = x, yA = y - r; // 最上面的顶点
	int xB = x + SR1, yB = y - CR1;
	int xC = x + CR2, yC = y + SR2;
	int xD = x - CR2, yD = y + SR2;
	int xE = x - SR1, yE = y - CR1;

//	double SR1 =  s * sin(72), SR2 = s * sin(54),
//		CR1 = s * cos(72), CR2 = s * cos(54);
//	int xA = x, yA = y - s;
//	int xB = x + CR1, yB = y - SR1;
//	int xC = x + SR2, yC = y - CR2;
//	int xD = x - SR2, yD = y - CR2;
//	int xE = x - CR1, yE = y - SR1;

	line(xA, yA, xC, yC);
	line(xC, yC, xE, yE);
	line(xE, yE, xB, yB);
	line(xB, yB, xD, yD);
	line(xD, yD, xA, yA);

//	line(xA, yA, xC, yC);
//	line(xC, yC, xE, yE);
//	line(xE, yE, xB, yB);
//	line(xB, yB, xD, yD);
//	line(xD, yD, xA, yA);
	 
}

void timerListener(int id)
{
	beginPaint();
	setPenWidth(1);
	setPenStyle(PEN_STYLE_SOLID);
	setBrushColor(BLACK);
	rectangle(0, 0, 800, 700); 

	for (int i = 0; i < 80; i++ ) {
		int x = rand() % 800;
		int y = rand() % 700;
		double r = rand() % 30;
		int R = rand() % 255;
		int G = rand() % 255;
		int B = rand() % 255;
		setPenColor(RGB(R, G, B));
	
		paintStar(x, y, r);
	} 
	endPaint();		
}

int Setup()
{	
	initWindow("星空", DEFAULT, DEFAULT, 600, 700); 
	
	registerTimerEvent(timerListener); 
	startTimer(0, 1000);
	
	return 0; 
}
