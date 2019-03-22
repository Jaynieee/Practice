// findRoad.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

//Y竖 行数
#define ROWS 9
//X横 列数
#define COLS 9

enum direct{p_up,p_down,p_left,p_right,l_up,l_down,r_up,r_down};


struct MyPoint{
	int row;//y
	int col;//x

	int f;//代价
	int h;//当前代价
	int g;//预估代价
};
//辅助地图类型
struct pathNode{
 int val;//地图上的值
 bool isFind;//是否走过
};
//树节点类型
struct treeNode{
	MyPoint pos;
	treeNode* pParent;//指向父节点
	vector<treeNode*> child;//数组 保存指向汉孩子的指针
};





int _tmain(int argc, _TCHAR* argv[])
{
	//地图
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
	//起点终点
	MyPoint begPos ={1,1};
	MyPoint endPos ={3,7};


	//3.准备辅助地图标记
	pathNode pathMap[ROWS][COLS]={0};
	for(int i=0;i< ROWS;i++)
	{
	    for(int j=0;j< COLS; j++)
		{
		   pathMap[i][j].val = map[i][j];
		}
	
	}
	//4、准备一棵树
	treeNode* pRoot = NULL;
	//5、起点入数，并且已经走过
	//treeNode* createNode(MyPoint pos);
	pRoot = createNode(begPos);//起点成为根节点
	pathMap[begPos.row][begPos.col].isFind= true;

	//当前点
	MyPoint currentPos = begPos;
	//临时指针
	treeNode* pChild =NULL;
	//6、A星寻路
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

			//6.2判断能不能走
			if(){//能走
				//6.2.1 创建树节点
			

				//6.2.2入树


				//6.2.3找最小
			}
			//6.3 找f值最小的
			//6.4 标记走过
			//6.5 判断是否找到终点
	
	}


	//7、打印路径



	return 0;
}


//创建树节点并返回节点首地址
treeNode* createNode(MyPoint pos)
{

	treeNode* pNew= new treeNode;
	memset(pNew,0,sizeof treeNode);


	pNew->pos = pos;
}


//代价 数字化 
//alphago运用了相似的算法

/*f=g+h
f:代价
g:起点到当前已经付出的代价
h：当前点到终点预估代价
无视障碍 只计算直线距离
大约直线代价10，斜线代价14
*/
/*
1、准备地图
int map
*/