// 绘制时钟 

#include "acllib.h"
#include <stdio.h>
#include <math.h>
#include <time.h> 

#define PI 3.14159265358979323846
#define ORX 160       // 表针起点坐标 
#define ORY 160
#define UNITANGLE 6  // 表盘有60格，每格6度 
#define HOURANGLE 30 // 12小时，每小时30度   

// 自定义一个时间结构用于测试 
//typedef struct time { 
//	int hour;
//	int min;
//	int sec;
//} Time;

typedef struct tm Time;

ACL_Image Image;

// 角度转弧度
double AngleToArc(const double angle) 
{
    return angle / 180 * PI;
}

// 计算转针终点并绘制直线
void rotLine(int orx, int ory, int r, int angle)
{
	// 极坐标系转直角坐标系
    double x = orx + r * sin(AngleToArc(180 - angle));   
    double y = ory + r * cos(AngleToArc(180 - angle));

    line(orx, ory, x, y);
}

// 根据系统时间计算三根表针的角度 
void timeToAngle(Time * time, double * h, double * m, double * s)
{
	*s = time->tm_sec * UNITANGLE;
	*m = (time->tm_min + time->tm_sec/60.0) * UNITANGLE;
	*h = (time->tm_hour  + time->tm_min/60.0 + time->tm_sec/3600.0) * HOURANGLE; 
}

// 获取系统时间
Time * getTime()
{
	time_t rawtime;
	Time * info;
	
	time( &rawtime );   // 将结果存在 rawtime 中 
	info = localtime( &rawtime );  // 将结果转换为 tm 结构体 
	return info;

} 


void timerListener(int id)
{
	double hha = 0, mma = 0, ssa = 0;  // 时分秒角度变量 
//	static Time time = {5, 30, 0};  // 自定义一个开始时间 
	Time * time = getTime(); 

//	{
//		initConsole();
//		printf("%d:", time->tm_hour);
//		printf("%d:", time->tm_min);
//		printf("%d\n", time->tm_sec);
//		printf("当前的本地时间和日期：%s\n", asctime(time));
//	}

	timeToAngle(time, &hha, &mma, &ssa); 
	
	beginPaint();
	putImageScale(&Image, 0, 0, 320, 320);	// 绘制表盘 
	
	// 绘制三根表针 
	setPenColor(RED);
	setPenWidth(1); 
	rotLine(ORX, ORY, 75, ssa);  // 秒
	
	setPenColor(BLACK);
	setPenWidth(3); 
	rotLine(ORX, ORY, 60, mma);		// 分 
	rotLine(ORX, ORY, 40, hha);		// 时 
	 
	endPaint();
	
	// 手动更新时间 
//	time.sec++;
//	if ( time.sec > 59 ) {
//		time.sec = 0;
//		time.min++;
//		if ( time.min > 59 ) {
//			time.min = 0;
//			time.hh++;
//			if (time.hh > 12) {
//				time.hh = 1;
//			}
//		}
//	}
}

int Setup()
{

    initWindow("ACLLib时钟", DEFAULT, DEFAULT, 320, 320);	
	loadImage("D:\\Project\\ACLLib-Learn\\examples\\sources\\Time.jpg", &Image);

	registerTimerEvent(timerListener);
	startTimer(0, 1000);

	return 0; 
}
