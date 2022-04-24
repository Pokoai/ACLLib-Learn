#include "acllib.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

#define VK_0 0x30
#define VK_1 0x31
#define VK_2 0x32
#define VK_3 0x33
#define VK_4 0x34
#define VK_5 0x35
#define VK_6 0x36
#define VK_7 0x37
#define VK_8 0x38
#define VK_9 0x39

#define VK_A 0x41
#define VK_B 0x42
#define VK_C 0x43
#define VK_D 0x44
#define VK_E 0x45
#define VK_F 0x46
#define VK_G 0x47
#define VK_H 0x48
#define VK_I 0x49
#define VK_J 0x4A
#define VK_K 0x4B
#define VK_L 0x4C
#define VK_M 0x4D
#define VK_N 0x4E
#define VK_O 0x4F
#define VK_P 0x50
#define VK_Q 0x51
#define VK_R 0x52
#define VK_S 0x53
#define VK_T 0x54
#define VK_U 0x55
#define VK_V 0x56
#define VK_W 0x57
#define VK_X 0x58
#define VK_Y 0x59
#define VK_Z 0x5A 
// other key define in WinSer.h

#define DX 320
#define DY 250

void clearArray(char * arry) 
{
//	for ( int i = 0; i < 1000; i++ ) {
//		arry[i] = '\0';
//	}
	memset(arry, 0, strlen(arry));
}

void keyBoardListener(int key, int event)
{
	char c;
	static char charSet[1000];
	static char charSet2[1000];
	static char charSet3[1000];
	static int cnt = 0;
	static int cnt2 = 0;
	static int cnt3 = 0;
	
	static char charSet4[1000];
	static char charSet5[1000];
	static char charSet6[1000];
	static int cnt4 = 0;
	static int cnt5 = 0;
	static int cnt6 = 0;
	
	beginPaint();
	setTextSize(15);
	setTextColor(RED);
	setTextBkColor(EMPTY); 
//	paintText(0, 5, "注意：只能按A-Z键，请勿按其他键。若出错请重新运行程序。");
	
	setBrushColor(BLACK);
	rectangle(0, 0, 800, 400);
	setTextColor(BLUE);
	setTextBkColor(EMPTY);
	setTextSize(70);
	
	switch( key )
	{
		case VK_ESCAPE: 
//			paintText(DX, DY, "ESC键");
			cnt = cnt2 = cnt3 = cnt4 = cnt5 = cnt6 = 0;
			clearArray(charSet), clearArray(charSet2), clearArray(charSet3), 
				clearArray(charSet4), clearArray(charSet5), clearArray(charSet6);
			break;
//		case VK_RETURN:
//			paintText(DX, DY, "回车键");
//			break;
//		case VK_TAB:
//			paintText(DX, DY, "TAB键");
//			break;
//		case VK_CAPITAL:
//			paintText(DX, DY, "Caps Lock键");
//			break;
//		case VK_SHIFT:
//			paintText(DX, DY, "Shift键");
//			break;
//		case VK_CONTROL:
//			paintText(DX, DY, "Ctrl键");
//			break;
//		case VK_MENU:
//			paintText(DX, DY, "Alt键");
//			break;
//		case VK_SPACE:
//			paintText(DX, DY, "空格键");
//			break;
//		case VK_BACK:
//			paintText(DX, DY, "退格键");
//			break;
//		case VK_LWIN:
//			paintText(DX, DY, "左徽标键");
//			break;
//		case VK_RWIN:
//			paintText(DX, DY, "右徽标键");
//			break;
//		case VK_APPS:
//			paintText(DX, DY, "鼠标右键快捷键");
//			break;
//		case VK_INSERT:
//			paintText(DX, DY, "Insert键");
//			break;		
//		case VK_HOME:
//			paintText(DX, DY, "Home键");
//			break;
//		case VK_PRIOR:
//			paintText(DX, DY, "Page Up");
//			break;
//		case VK_NEXT:
//			paintText(DX, DY, "PageDown");
//			break;
//		case VK_END:
//			paintText(DX, DY, "End键");
//			break;
//		case VK_DELETE:
//			paintText(DX, DY, "Delete键");
//			break;
//		case VK_LEFT:
//			paintText(DX, DY, "方向键(←)");
//			break;
//		case VK_UP:
//			paintText(DX, DY, "方向键(↑)");
//			break;
//		case VK_RIGHT:
//			paintText(DX, DY, "方向键(→)");
//			break;
//		case VK_DOWN:
//			paintText(DX, DY, "方向键(↓)");
//			break;
//		case VK_F1:
//			paintText(DX, DY, "F1键");
//			break;
//		case VK_F2:
//			paintText(DX, DY, "F2键");
//			break;
//		case VK_F3:
//			paintText(DX, DY, "F3键");
//			break;
//		case VK_F4:
//			paintText(DX, DY, "F4键");
//			break;
//		case VK_F5:
//			paintText(DX, DY, "F5键");
//			break;
//		case VK_F6:
//			paintText(DX, DY, "F6键");
//			break;
//		case VK_F7:
//			paintText(DX, DY, "F7键");
//			break;
//		case VK_F8:
//			paintText(DX, DY, "F8键");
//			break;
//		case VK_F9:
//			paintText(DX, DY, "F9键");
//			break;
//		case VK_F10:
//			paintText(DX, DY, "F10键");
//			break;
//		case VK_F11:
//			paintText(DX, DY, "F11键");
//			break;
//		case VK_F12:
//			paintText(DX, DY, "F12键");
//			break;
//		case VK_NUMLOCK:
//			paintText(DX, DY, "Num Lock键");
//			break;
//		case VK_NUMPAD0:
//			paintText(DX, DY, "小键盘0");
//			break;			
//		case VK_NUMPAD1:
//			paintText(DX, DY, "小键盘1");
//			break;
//		case VK_NUMPAD2:
//			paintText(DX, DY, "小键盘2");
//			break;
//		case VK_NUMPAD3:
//			paintText(DX, DY, "小键盘3");
//			break;
//		case VK_NUMPAD4:
//			paintText(DX, DY, "小键盘4");
//			break;
//		case VK_NUMPAD5:
//			paintText(DX, DY, "小键盘5");
//			break;
//		case VK_NUMPAD6:
//			paintText(DX, DY, "小键盘6");
//			break;
//		case VK_NUMPAD7:
//			paintText(DX, DY, "小键盘7");
//			break;
//		case VK_NUMPAD8:
//			paintText(DX, DY, "小键盘8");
//			break;
//		case VK_NUMPAD9:
//			paintText(DX, DY, "小键盘9");
//			break;
//		case VK_DECIMAL:
//			paintText(DX, DY, "小键盘.");
//			break;
//		case VK_MULTIPLY:
//			paintText(DX, DY, "小键盘*");
//			break;
//		case VK_ADD:
//			paintText(DX, DY, "小键盘 +");
//			break;
//		case VK_SUBTRACT:
//			paintText(DX, DY, "小键盘 - ");
//			break;
//		case VK_DIVIDE:
//			paintText(DX, DY, "小键盘 /  ");
//			break;	
//		case VK_PAUSE:
//			paintText(DX, DY, "Pause Break键");
//			break;
//		case VK_SCROLL:
//			paintText(DX, DY, "Scroll Lock键");
//			break;
//		case VK_0 :
//			paintText(DX, DY, "0键");
//			break;
//		case VK_1:
//			paintText(DX, DY, "1键");
//			break;
//		case VK_2:
//			paintText(DX, DY, "2键");
//			break;
//		case VK_3:
//			paintText(DX, DY, "3键");
//			break;
//		case VK_4:
//			paintText(DX, DY, "4键");
//			break;
//		case VK_5:
//			paintText(DX, DY, "5键");
//			break;
//		case VK_6:
//			paintText(DX, DY, "6键");
//			break;
//		case VK_7:
//			paintText(DX, DY, "7键");
//			break;
//		case VK_8:
//			paintText(DX, DY, "8键");
//			break;
//		case VK_9:
//			paintText(DX, DY, "9键");
//			break;

		case VK_A:
			paintText(DX, DY, "A键");
			c = 'A';
			break;
		case VK_B:
			paintText(DX, DY, "B键");
			c = 'B';
			break;
		case VK_C:
			paintText(DX, DY, "C键");
			c = 'C';
			break;
		case VK_D:
			paintText(DX, DY, "D键");
			c = 'D';
			break;
		case VK_E:
			paintText(DX, DY, "E键");
			c = 'E';
			break;
		case VK_F:
			paintText(DX, DY, "F键");
			c = 'F';
			break;
		case VK_G:
			paintText(DX, DY, "G键");
			c = 'G';
			break;
		case VK_H:
			paintText(DX, DY, "H键");
			c = 'H';
			break;
		case VK_I:
			paintText(DX, DY, "I键");
			c = 'I';
			break;
		case VK_J:
			paintText(DX, DY, "J键");
			c = 'J';
			break;
		case VK_K:
			paintText(DX, DY, "K键");
			c = 'K';
			break;
		case VK_L:
			paintText(DX, DY, "L键");
			c = 'L';
			break;
		case VK_M:
			paintText(DX, DY, "M键");
			c = 'M';
			break;
		case VK_N:
			paintText(DX, DY, "N键");
			c = 'N';
			break;
		case VK_O:
			paintText(DX, DY, "O键");
			c = 'O';
			break;
		case VK_P:
			paintText(DX, DY, "P键");
			c = 'P';
			break;
		case VK_Q:
			paintText(DX, DY, "Q键");
			c = 'Q';
			break;
		case VK_R:
			paintText(DX, DY, "R键");
			c = 'R';
			break;
		case VK_S:
			paintText(DX, DY, "S键");
			c = 'S';
			break;
		case VK_T:
			paintText(DX, DY, "T键");
			c = 'T';
			break;
		case VK_U:
			paintText(DX, DY, "U键");
			c = 'U';
			break;
		case VK_V:
			paintText(DX, DY, "V键");
			c = 'V';
			break;
		case VK_W:
			paintText(DX, DY, "W键");
			c = 'W';
			break;
		case VK_X:
			paintText(DX, DY, "X键");
			c = 'X';
			break;
		case VK_Y:
			paintText(DX, DY, "Y键");
			c = 'Y';
			break;
		case VK_Z:
			paintText(DX, DY, "Z键");
			c = 'Z';
			break;
	}
	if ( c >= 'A' && c <= 'Z') {
		if ( event == KEY_DOWN) {
			if ( cnt < 72 ) {
				charSet[cnt++] = c;
				charSet[cnt++] = ' ';
			} else if ( cnt2 < 72 ){
				charSet2[cnt2++] = c;
				charSet2[cnt2++] = ' ';
			} else if ( cnt3 < 72 ){
				charSet3[cnt3++] = c;
				charSet3[cnt3++] = ' ';
			} else if ( cnt4 < 72 ){
				charSet4[cnt4++] = c;
				charSet4[cnt4++] = ' ';
			} else if ( cnt5 < 72 ){
				charSet5[cnt5++] = c;
				charSet5[cnt5++] = ' ';
			} else if ( cnt6 < 72 ){
				charSet6[cnt6++] = c;
				charSet6[cnt6++] = ' ';
			}
		
		}	
	} 
	
//	const int charOfLine = 31;
//	char s1[1000], s2[1000];
//	strncpy(s1, charSet, charOfLine);
//	for (int i = charOfLine; i < strlen(charSet); i++ ) {
//		s2[i] = charSet[i];
//	}

//	initConsole();
//	printf("s->%s\n", charSet);
//	printf("s2->%s\n", charSet2);
	
	setTextSize(15);
	setTextColor(RED);
	setTextBkColor(EMPTY); 
//	paintText(0, 5, "注意：只能按A-Z键，请勿按其他键。若出错请重新运行程序。");
	
	setTextSize(20);
	setTextColor(CYAN);
	paintText(DX-15, 5, "小宝打字练习GO!");
	
	setTextColor(WHITE);
	paintText(0, 35, charSet);
	paintText(0, 55, charSet2);
	paintText(0, 75, charSet3);
	
	paintText(0, 95, charSet4);
	paintText(0, 115, charSet5);
	paintText(0, 135, charSet6);
	
	if ( cnt6 > 71 ) {
		setTextSize(35);
		setTextColor(RED);
		paintText(DX-190, 180, "输入框已满，请按ESC键重新开始！");
	}
	
//	if ( event == KEY_DOWN ) {
//		paintText(DX, 220, "按下"); 
//	} else {
//		paintText(DX, 220, "松开");
//	}
	
	endPaint();
}



int Setup()
{
    initWindow("打字练习", DEFAULT, DEFAULT, 800, 400);
    
    beginPaint();
	setBrushColor(BLACK);
	rectangle(0, 0, 800,400);
//	setTextSize(15);
//	setTextColor(RED);
//	setTextBkColor(EMPTY); 
//	paintText(0, 5, "注意：只能按A-Z键，请勿按其他键。若出错请重新运行程序。");
	setTextSize(20);
	setTextColor(CYAN);
	setTextBkColor(EMPTY);
	paintText(DX-15, 5, "小宝打字练习GO!");
	endPaint();
	
    registerKeyboardEvent(keyBoardListener);

    return 0; 
}
