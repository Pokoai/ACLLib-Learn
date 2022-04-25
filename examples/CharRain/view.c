#include "view.h"

void initWind()
{
	ACL_Sound pSound;
	
	initWindow("CharRain", 0, 0, WIN_WIDTH, WIN_HEIGHT);
	srand((unsigned int)time(NULL));
	
	loadSound("Flower Dance.mp3", &pSound);
	playSound(pSound, 1);
//	PlaySound()
//	initConsole();
	
	beginPaint();
	setBrushColor(RGB(0, 0, 0));
	setTextBkColor(RGB(0, 0, 0));
	setTextFont("Kristen ITC");
	setTextSize(TEXTSIZE);
	endPaint();
}

void clearWindow()
{
	beginPaint();
	rectangle(0, 0, WIN_WIDTH, WIN_HEIGHT);
	endPaint();
}

// 只要数据来了，根据数据去绘制出来就行
// 不用考虑数据变化问题 
void printChar()
{
	int add;
	char aux[2];
//	char *aux; 
	beginPaint();
	for (int i = 0; i < COL_NUM; i++ ) {
//		printf("%d\n", i);
		add = strInfo[i][0] - strInfo[i][1];
		for ( int j = 0; j < strInfo[i][1]; j++, add++ ) {
			if ( add < 0 || add >= CharNum ) {
				continue;
			}			
			strncpy(aux, charSet[i] + add, 1);
			aux[1] = '\0';
			
			if ( j == strInfo[i][1] - 1 ) {
				setTextColor(RGB(255, 255, 255));
			} else {
				setTextColor(RGB(0, (j+1) * (255 / strInfo[i][1]), 0));
			}
			
//			paintText(i*TEXTSIZE, add*TEXTSIZE, aux.c_str()); // c++
			paintText(i*TEXTSIZE, add*TEXTSIZE, aux);
//			printf("%d\n", i);
		}
	}
	endPaint();
}



