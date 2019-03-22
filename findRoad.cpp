// findRoad.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
using namespace std;

//Y�� ����
#define ROWS 9
//X�� ����
#define COLS 9

enum direct{p_up,p_down,p_left,p_right,l_up,l_down,r_up,r_down};


struct MyPoint{
	int row;//y
	int col;//x

	int f;//����
	int h;//��ǰ����
	int g;//Ԥ������
};
//������ͼ����
struct pathNode{
 int val;//��ͼ�ϵ�ֵ
 bool isFind;//�Ƿ��߹�
};
//���ڵ�����
struct treeNode{
	MyPoint pos;
	treeNode* pParent;//ָ�򸸽ڵ�
	vector<treeNode*> child;//���� ����ָ�򺺺��ӵ�ָ��
};





int _tmain(int argc, _TCHAR* argv[])
{
	//��ͼ
	int map[ROWS][COLS]={
		{0,0,0,0,1,0,0,0,0},
		{0,0,0,0,1,0,0,0,0},
		{0,0,0,0,1,0,0,0,0},
		{0,0,0,0,1,0,0,0,0},
		{0,0,0,0,1,0,0,0,0},
		{0,0,0,0,1,0,0,0,0},
		{0,0,0,0,1,0,0,0,0},
		{0,0,0,0,1,0,0,0,0},
		{0,0,0,0,1,0,0,0,0},
	};
	//����յ�
	MyPoint begPos ={1,1};
	MyPoint endPos ={3,7};


	//3.׼��������ͼ���
	pathNode pathMap[ROWS][COLS]={0};
	for(int i=0;i< ROWS;i++)
	{
	    for(int j=0;j< COLS; j++)
		{
		   pathMap[i][j].val = map[i][j];
		}
	
	}
	//4��׼��һ����
	treeNode* pRoot = NULL;
	//5����������������Ѿ��߹�
	//treeNode* createNode(MyPoint pos);
	pRoot = createNode(begPos);//����Ϊ���ڵ�
	pathMap[begPos.row][begPos.col].isFind= true;

	//��ǰ��
	MyPoint currentPos = begPos;
	//��ʱָ��
	treeNode* pChild =NULL;
	//6��A��Ѱ·
	while(1)
	{
	    
			for(int i=0;i<8;i++){
			   MyPoint  tempPos = currentPos;
			   switch (i)
			   {
			   case p_up:
				   tempPos.row--;
				   tempPos.g +=10;
				   break;
			    case p_down:
				   tempPos.row++;
				   tempPos.g +=10;
				   break;
			    case p_left:
				   tempPos.col--;
				   tempPos.g +=10;
				   break;
				case p_right:
				   tempPos.col++;
				   tempPos.g +=10;
				   break;
				case l_up:
				   tempPos.row--;
				   tempPos.g +=14;
				   break;
				case l_down:
				   tempPos.row++;
				   tempPos.g +=14;
				   break;
				case r_up:
				   tempPos.col--;
				   tempPos.g +=14;
				   break;
				case r_down:
				   tempPos.col++;
				   tempPos.g +=14;
				   break;
			   }
			
			}

			//6.2�ж��ܲ�����
			if(){//����
				//6.2.1 �������ڵ�
			

				//6.2.2����


				//6.2.3����С
			}
			//6.3 ��fֵ��С��
			//6.4 ����߹�
			//6.5 �ж��Ƿ��ҵ��յ�
	
	}


	//7����ӡ·��



	return 0;
}


//�������ڵ㲢���ؽڵ��׵�ַ
treeNode* createNode(MyPoint pos)
{

	treeNode* pNew= new treeNode;
	memset(pNew,0,sizeof treeNode);


	pNew->pos = pos;
}


//���� ���ֻ� 
//alphago���������Ƶ��㷨

/*f=g+h
f:����
g:��㵽��ǰ�Ѿ������Ĵ���
h����ǰ�㵽�յ�Ԥ������
�����ϰ� ֻ����ֱ�߾���
��Լֱ�ߴ���10��б�ߴ���14
*/
/*
1��׼����ͼ
int map
*/