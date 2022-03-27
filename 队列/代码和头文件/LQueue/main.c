#include "LQueue.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//"	1.初始化队列		2.检查队列是否为空\n"
//"	3.入队操作		4.出队操作\n"
//"	5.查看队头元素		6.确定队列长度\n"
//"	7.清空队列		8.销毁队列\n"
//"	9.查遍历并输出队列	10.退出系统\n"
int main()
{
	LQueue  Queue1;
	void* p;
	Menu();
	int scan;
	int flag = 0;
	while (1)
	{
		printf("\n请选择菜单编号:");
		scan = Scanf_d();//检测输入的菜单编号
		if (!(scan < 11 && scan >0)) {//输入不合法菜单编号时，提示
			printf("请输入正确的菜单编号\n");
		}
		else if (scan == 10) { //输入10时，清空显示并退出系统
			system("cls");
			return 0;
		}
		else if (scan < 10 && scan >0)//如果输入合法菜单编号
		{
			if (scan == 1) {//初始化泛型队列
				if (flag) { ClearLQueue(&Queue1); }//如果队列已存在，先清空队列释放内存
				InitLQueue(&Queue1);
				printf("队列初始化成功^-^");
				flag = 1;
			}
			if (flag == 1)//如果已经初始化队列，则可进行如下操作
			{
				if (scan == 2) {//判断队列是否为空
					if (IsEmptyLQueue(&Queue1) == TRUE)
						printf("队列为空^-^\n");
					else
						printf("队列不为空^-^\n");
				}
				if (scan == 3) {//入队
					p = shuru();
					EnLQueue(&Queue1, p);
					printf("入队成功^-^\n");
				}
				if (scan == 4) {//出队
					if (Queue1.length) {
						printf("出队元素为");
						GetHeadLQueue(&Queue1);
						DeLQueue(&Queue1);
						printf(" ，出队成功^-^\n");
					}
					else printf("队列为空，无法出队\n");
				}
				if (scan == 5)//查看队头元素
					if (Queue1.length) {
						printf("队头元素为");
						GetHeadLQueue(&Queue1);
						printf(" ^-^\n");
					}
					else printf("队列为空，无队头元素\n");
				if (scan == 6) {//确定队列长度
					printf("队列当前长度为 %d ^-^", LengthLQueue(&Queue1));
				}
				if (scan == 7) {//清空队列
					ClearLQueue(&Queue1);
					printf("队列清空成功^-^\n");
				}
				if (scan == 8) {//销毁队列
					DestoryLQueue(&Queue1);
					printf("队列销毁成功^-^\n");
					flag = 0;
				}
				if (scan == 9) {//遍历并输出队列
					TraverseLQueue(&Queue1, LPrint);
				}
			}
			else printf("队列不存在，请先初始化队列\n");
		}

	}

	return 0;
}
