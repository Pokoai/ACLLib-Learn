#include "controller.h"

// 不做任何显示的事情，显示的交给 view.c 去做
// 数据的事情交给 model.c 去做
 
void timerListener(int id);
void charMove();
void newString();
 
int Setup()
{
	initWind();  	// 初始化窗口 
	clearWindow();	// 清空窗口 
	initModel();	// 数据生成加载完毕 
	
	registerTimerEvent(timerListener);
	startTimer(0, 200);
	
	printf("%s\n", charSet[0]);
	printf("%d\n", strInfo[0][0]);
	printf("%d\n", strInfo[1][1]);
	
	return 0;	
} 



// 这里的控制就只有 timer 
// 每次唤醒后更新数据，所以 timer 放在 contreler.c 中

void timerListener(int id)
{
	// 虽然 timer 放在controller 中，但是涉及到显示的事情需要在 view 中做，
	// 所以在其中去调用显示类的函数就行，该函数具体实现要放在 view 中
	// 更新数据的事情是 controller 做的，应该放在该文件下 
	
	
	// 1.每次唤醒后第一件事就是更新数据
	charMove();
	newString();
	// 2. 然后清空画面 
	clearWindow();
	// 3.最后重新显示
	printChar();
	 
} 


// 更新数据

// 1.每次移动字符串起始位
void charMove()
{
	for ( int i = 0; i < COL_NUM; i++ ) {
		strInfo[i][0]++;	
	}
} 

// 2.雨丝落地，重新创建一个 
void newString()
{
	int s;
	for ( int i = 0; i < COL_NUM; i++ ) {
		s = ( strInfo[i][0] - strInfo[i][1] ) * TEXTSIZE; // 这里为什么相减，可参考 printChar() 注释 
		if ( s >= WIN_HEIGHT ) {
			// 重新生成第i个字符串
			createString(charSet[i]);
			// 重新生成第 i个雨丝 
			createOneSliding(strInfo[i]);
		}
	} 
}

