#include "view.h"

void initWind()
{
	ACL_Sound pSound;
	
	initWindow("CharRain", 0, 0, WIN_WIDTH, WIN_HEIGHT);
	srand((unsigned int)time(NULL));
	
	loadSound("D:\\Project\\ACLLib-Learn\\examples\\CharRain\\Flower Dance.mp3", &pSound);
	playSound(pSound, 1);
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
	char aux[2];  // 用来装要显示的字符, 数组里还要加一个'\0'字符才算字符串 
//	char *aux=NULL;  // 不知道为何不能用字符串指针 
	beginPaint();
	
	for (int i = 0; i < COL_NUM; i++ ) {  // 遍历每列 
//		printf("%d\n", i);
		// strInfo[i][0]存储的是初始位置，strInfo[i][1]存储的是雨列长度
		// 两者相减而不是相加，表示该雨列实际上是从初始位置开始往前找长度个字符，而非往后找
		// 假设字符串长度 CharNum=64，雨列初始位置：30，长度：10，
		//那么该雨列就是字符串 20~30 这一段，而非 30~40 
		// add 实际上就是该雨列的头，strInfo[i][1]为尾 
		add = strInfo[i][0] - strInfo[i][1]; 
		for ( int j = 0; j < strInfo[i][1]; j++, add++ ) {  // 遍历该雨列，遍历次数：strInfo[i][1] 
			// 雨列的头大于0，小于CharNum，屏幕上才有元素，才需要绘制
			// 否则整个雨列火车往下移动，直到火车头达到屏幕顶端，开始绘制，直到绘制完该雨列长度 
			if ( add < 0 || add >= CharNum ) {
				continue;
			}
			// add: 雨列头，charSet[i] + add：将 charSet[i]的字符串指针移到雨列头部
			// 首次是移到头部，随着 add++，以后每次就是依次从头部往后移动一位
			// 1：将指针所指的这 1个字符拷贝给 aux		
			strncpy(aux, charSet[i] + add, 1);
			aux[1] = '\0';
			
			// 开始是绘制从 add~add+strInfo[i][1] 的字符，
			// 直到内for循环到雨列最后一个字符时（j==strInfo[i][1] - 1），
			// 最后绘制的字符，y坐标最大，即位于雨列最下方
			// 最下面的字符用白色显示 
			if ( j == strInfo[i][1] - 1 ) {
				setTextColor(RGB(255, 255, 255));
			} else {
				// 其他位置字符，一开始接近黑色，看不清（因为背景也是黑色）
				// 越后绘制的，位置越靠屏幕下方，颜色越接近（0，255，0） 
				setTextColor(RGB(0, (j+1) * (255 / strInfo[i][1]), 0));
			}
			
//			paintText(i*TEXTSIZE, add*TEXTSIZE, aux.c_str()); // c++
			// i*TEXTSIZE：不同列的雨列 x 轴不同 
			// add*TEXTSIZE：随着 add++, 同一雨列的不同位置字符 y 轴不同 
			paintText(i*TEXTSIZE, add*TEXTSIZE, aux);

		}
	}
	endPaint();
}




