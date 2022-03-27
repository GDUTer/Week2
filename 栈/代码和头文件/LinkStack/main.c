#include<stdio.h>
#include<stdlib.h>
#include "LinkStack.h"

int main()
{
	LinkStack  stack;
	int scan, flag = 0, num;
	Menu();
	while (1)
	{
		printf("\n请选择菜单编号:");
		scan = Scanf_d();//检测输入的菜单编号
		if (!(scan < 10 && scan >0)) {//输入不合法菜单编号时，提示
			printf("请输入正确的菜单编号\n");
		}
		else if (scan == 9) { //输入9时，清空显示并退出系统
			system("cls");
			return 0;
		}
		else if (scan < 10 && scan >0)//如果输入合法菜单编号
		{
			if (scan == 1) {//初始化链栈
				if(flag){ clearLStack(&stack); }//如果栈已存在，先清空栈释放内存
				initLStack(&stack);
				printf("链栈初始化成功^-^");
				flag = 1;
			}
			if (flag == 1)//如果已经初始化链栈，则可进行如下操作
			{
				if (scan == 2) {//入栈
					printf("请输入入栈的数据：");
					num = Scanf_d();
					pushLStack(&stack, num);
					printf("数据入栈成功^-^\n");
				}
				if (scan == 3) {//出栈
					if (stack.count) {
						popLStack(&stack, &num);
						printf("出栈的数为 %d ,出栈成功^-^", num);
					}
					else printf("链栈为空，无法出栈\n");
				}
				if (scan == 4) {//判断栈是否为空
					if (stack.count)
						printf("链栈不为空^-^\n");
					else
						printf("链栈为空^-^\n");
				}
				if (scan == 5)//得到栈顶元素
					if (stack.count) {
						getTopLStack(&stack, &num);
						printf("栈顶元素为 %d ^-^\n", num);
					}
					else printf("链栈为空，无栈顶元素\n");
				if (scan == 6) {//得到当前栈顶长度
					LStackLength(&stack, &num);
					printf("链栈当前长度为 %d ^-^", num);
				}
				if (scan == 7) {//清空栈
					clearLStack(&stack);
					printf("链栈清空成功^-^\n");
				}
				if (scan == 8) {//销毁栈
					destroyLStack(&stack);
					printf("链栈销毁成功^-^\n");
					flag = 0;
				}
			}
			else printf("链栈不存在，请先初始化链栈\n");
		}
		
	}
}

