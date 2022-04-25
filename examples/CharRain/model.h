#include <stdio.h>
//#include <string.h>
//#include <math.h>
#include <stdlib.h> 

// 所有文件共同使用，变量字母全部大写 
#define WIN_WIDTH 	1490  					// 窗口宽度
#define WIN_HEIGHT 	860 					// 窗口高度
#define TEXTSIZE  	23						// 字体大小 
#define COL_NUM  (WIN_WIDTH/TEXTSIZE)		// 字符列数 


// 仅本文件使用，未全大写，便于区分变量作用域 
#define CharNum (WIN_HEIGHT/TEXTSIZE) 	 	// 一列雨丝字符个数 
#define MinCharNum  6  						// 最少雨丝字符个数  
#define MaxCharNum  16  					// 最多雨丝字符个数 

char * createString(char *);				// 产生一个字符串 
//void createAllChar();						// 产生全屏幕的字符串
int * createOneSliding(int *);				// 产生一列雨丝起始位置和终止位置
//void createAllSliding();					// 产生每列雨丝的起始位置和终止位置
//void pulsRain();							// 如果这列雨丝落地，产生一个新的
void initModel();							// 初始化内存变量

extern char charSet[COL_NUM][CharNum];		// 盛放所有字符 
extern int strInfo[COL_NUM][2];            	// 盛放所有列的起始位置和长度  
  
