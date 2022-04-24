#include "acllib.h"
#include <stdio.h>

// 鼠标回调函数 
void mouseListener(int x, int y, int button, int event)
{
	static int ox = 0;
	static int oy = 0;
	 
	printf("x=%d, y=%d, button=%d, event=%d\n", x, y, button, event);
	
	beginPaint();
	// 左键按下标志，按下为 1，松开为 0 
	static int lflag = 0; 
	if ( button == LEFT_BUTTTON && event == BUTTON_DOWN ) {
			printf("左键按下\n");
			lflag = 1;
	} 
	if ( button == LEFT_BUTTTON && event == BUTTON_UP ) {
		lflag = 0;
		printf("左键松开\n"); 
	}
	// 左键按下时才画线 
	if ( lflag == 1) {
		line(ox, oy, x, y);
	}
	endPaint();
	
	ox = x;
	oy = y;
}

// 键盘回调函数 
void keyboardListener(int key, int event)
{
	printf("key=%d, event=%d\n", key, event);
}

// 定时器回调函数 
void timerListener(int id)
{
	static int cnt = 0;
	
	printf("id=%d\n", id);
	if ( id == 0 ) {
		cnt++;
		if ( cnt == 5 ) {
			cancelTimer(0);
		}
	}
}


int Setup()
{	
	// 设置窗口 
	initWindow("test", 900, 100, 1000, 1000);
	// 打开 console
	initConsole();
	
	// 向 ACLLib 注册监听事件 
	registerMouseEvent(mouseListener);
	registerKeyboardEvent(keyboardListener);
	registerTimerEvent(timerListener);
	startTimer(0, 1000);
	startTimer(1, 1000);
	 
//	// 开始绘图
//	beginPaint();
//	
//	
//	// 结束绘图 
//	endPaint();
	
	return 0; 
}
