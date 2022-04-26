// 存放各类数据的地方
// 更新数据不要在这里操作，应该在 controller 中更新数据 


#include "model.h" 

// 全局变量
//存放所有需要的数据，供 controller、view 使用 

char charSet[COL_NUM][CharNum];  // 盛放所有字符串 
int strInfo[COL_NUM][2];  		// 盛放所有雨列的 初始位置、长度 

/*
 *以上两个数组可以用自己构建的结构体代替
 * typedef struct { 
 *    char charSet[COL_NUM][CharNum];
 *    int pos;
 *	  int len;
 *} String;
 *
 */

// 生成单个字符串，由 A-Z 组成 
char * createString(char * s)
{
	// 需要确定创建多长的字符串，所以在 .h 文件中先定义下
	int c; 
	
	for ( int i = 0; i < CharNum; i++ ) {
		// 随机产生 A-Z 的字符，其中 A:64, Z:90  ACS11码
		// 每次 for 循环必须要产生一个，所以必须要产生一个在 64-91间的值，不然没完
		// 那么我们就又要使用循环了，第一次就要执行，所以采用 do-while 循环
		do {
			// 先确保 随机数 < 91 
			c = rand() % (ASC_Z + 1);
		} while ( c < ASC_A ); // c<65 继续去 while，直到生成一个 65<= c < 91 的数为止 
		*(s+i) = c; 
	}
	// 还要给 s 末尾添加一个'\0'字符，才能表示 s 是一个字符串
	*(s+CharNum) = '\0';
	
	return s; 	
}


// 构造出所有字符串，存入 charSet 字符串数组中 
void createAllChar()
{
	// 要确定显示多少列的字符串，在 .h 文件中定义出来
	
//	char s[CharNum+1];  // 多一个用来存放 '\0'
	
	// 生成所有字符
	for ( int i = 0; i < COL_NUM; i++ ) {
//		strncat(charSet, createString(s), CharNum+1); // 采用 strncat, 保证安全 
		createString(charSet[i]);
	} 
 } 
 

// 从所有字符中随机取出用于显示的一列字符
// 确定了该列字符的初始位置和长度就确定了该雨列 
// 初始位置、长度两个变量需要一个数组来存储 
int * createOneSliding(int * arry)
{
	// 随机确定起始位置
	//想象一支笔从屏幕顶端竖直向下运动，直到从屏幕低端消失
	//一开始笔头在 y=0 处，而笔尾在 y=0-CharNum 处，即初始位置为 -CharNum ~ 0 
	// arry[0] 表示雨列的初始位置 
	arry[0] = rand() % CharNum - CharNum;
	// 确定随机长度，但是要保证在规定范围内
	// 方法类同于确保字符在 A-Z 之间
	do {
		arry[1] = rand() % (MaxCharNum + 1);
	} while( arry[1] < MinCharNum); 
	
	return arry;
}


// 创建所有字符列
void createAllSliding() 
{	
	for ( int i = 0; i < COL_NUM; i++ ) {
		createOneSliding(strInfo[i]); 
		
		// 首次显示时直接将所有雨列初始位置放到屏幕上，而非等着雨列从屏幕顶端慢慢出来 
		// 所以将 -CharNum~0 + CharNum ==> 0~CharNum
		// 但是注意雨列从屏幕低端跑出后，下一次生成的新雨列就不用修改初始位置了
		// 概括来说，就是第一次直接显示，后面从顶端慢慢出来，要的就是这种效果
		// 不加下面这句也行，每次都是从顶端慢慢出来 
		strInfo[i][0] += CharNum;  
	}
}


// 初始化 Model，生成所有数据 
void initModel()
{
	createAllChar();
	createAllSliding();
} 




















 


