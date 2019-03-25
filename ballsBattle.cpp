#include <stdio.h>
#include <graphics.h>
#include <time.h>

struct Ball
{
	int x,y;//坐标
	int radius;//半径
	COLORREF color;//颜色
};
//方向结构体
struct FX{
	int x,y;
	int radius;
	COLORREF 

};

COLORREF colors[5]={BLACK,BLUE,GREEN,RED,MAGENTA};
Ball myBall;

//固定大小的

Ball enemyBalls[20];
//初始化游戏 准备工作
void initGame()
{
	//1.1窗口  GUI  有这些win32 MFC QT openGL openCV
	initgraph(500,600);//F12//或者工具查找
	//1.2准备球

	//1.2.1自己球
	myBall.x=600;
	myBall.y=0;
	myBall.radius=10;
	myBall.color=GREEN;


	//设置随机数种子 拿数位置随着时间变化
	srand(time);//真随机


	//1.2.2敌人球
	for (int i=0;i<20;i++)
	{
	      
		  enemyBalls[i].x=20;
		  enemyBalls[i].y=500-20;

		  //颜色
		  enemyBalls[i].color=colors[rand()%7];//假随机，从固定列表拿
		  //大小
		  enemyBalls[i].color=colors[rand()%50+1];
	      //方向
		  //enemyBalls[i].x=colors[rand()%50+1];
		  //enemyBalls[i].y=colors[rand()%50+1];
	}
}
//游戏界面的绘制
void drawGame()
{
	//解决闪烁//开始前添加
	BeginBatchDraw();
	//2.0先擦除屏幕上的画面
	cleardevice();
	//2.1画背景

	//2.2画球

	//2.2.1画自己球
	//设置圆的颜色 画笔 画刷

	setfillcolor(myBall.color);
	//画圆
	solidcircle(myBall.x,myBall.y,myBall.radius);
	//2.2.2画敌人球
	for (int i=0;i<20;i++)
	{
	      setfillcolor();
		
	
	}
	//2.3分数

	EndBatchDraw();//结束后加，防止闪烁，本质是二级缓存
}

//控制游戏
void controlGame()
{
	MOUSEMSG msg;
     //鼠标控制
	while (1){
	
	msg = GetMouseMsg();
	myBall.x=msg.x;
	myBall.y=msg.y;
	
	}
	//3.1拿到鼠标信息
	//3.2根据鼠标信息来控制球

}
//敌人球移动
void move(){
	//一直在不停地绘制敌人球；
	//每隔一段时间调用一次move函数，改变每一个敌人球的位置；
	for(int i=0;i<20;i++){
	
	}
}
int main()
{

	CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)controlGame,NULL,NULL,NULL);
	while(1)
	{
	drawGame();
	};
	return 0;
}