#include <stdio.h>
#include <graphics.h>
#include <time.h>

struct Ball
{
	int x,y;//����
	int radius;//�뾶
	COLORREF color;//��ɫ
};
//����ṹ��
struct FX{
	int x,y;
	int radius;
	COLORREF 

};

COLORREF colors[5]={BLACK,BLUE,GREEN,RED,MAGENTA};
Ball myBall;

//�̶���С��

Ball enemyBalls[20];
//��ʼ����Ϸ ׼������
void initGame()
{
	//1.1����  GUI  ����Щwin32 MFC QT openGL openCV
	initgraph(500,600);//F12//���߹��߲���
	//1.2׼����

	//1.2.1�Լ���
	myBall.x=600;
	myBall.y=0;
	myBall.radius=10;
	myBall.color=GREEN;


	//������������� ����λ������ʱ��仯
	srand(time);//�����


	//1.2.2������
	for (int i=0;i<20;i++)
	{
	      
		  enemyBalls[i].x=20;
		  enemyBalls[i].y=500-20;

		  //��ɫ
		  enemyBalls[i].color=colors[rand()%7];//��������ӹ̶��б���
		  //��С
		  enemyBalls[i].color=colors[rand()%50+1];
	      //����
		  //enemyBalls[i].x=colors[rand()%50+1];
		  //enemyBalls[i].y=colors[rand()%50+1];
	}
}
//��Ϸ����Ļ���
void drawGame()
{
	//�����˸//��ʼǰ���
	BeginBatchDraw();
	//2.0�Ȳ�����Ļ�ϵĻ���
	cleardevice();
	//2.1������

	//2.2����

	//2.2.1���Լ���
	//����Բ����ɫ ���� ��ˢ

	setfillcolor(myBall.color);
	//��Բ
	solidcircle(myBall.x,myBall.y,myBall.radius);
	//2.2.2��������
	for (int i=0;i<20;i++)
	{
	      setfillcolor();
		
	
	}
	//2.3����

	EndBatchDraw();//������ӣ���ֹ��˸�������Ƕ�������
}

//������Ϸ
void controlGame()
{
	MOUSEMSG msg;
     //������
	while (1){
	
	msg = GetMouseMsg();
	myBall.x=msg.x;
	myBall.y=msg.y;
	
	}
	//3.1�õ������Ϣ
	//3.2���������Ϣ��������

}
//�������ƶ�
void move(){
	//һֱ�ڲ�ͣ�ػ��Ƶ�����
	//ÿ��һ��ʱ�����һ��move�������ı�ÿһ���������λ�ã�
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