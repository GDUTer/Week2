#include<stdio.h>
#include<stdlib.h>
#include "LinkStack.h"

//链栈

//初始化栈
Status initLStack(LinkStack* s)
{
	if (s) {
		(s)->count = 0;
		(s)->top = NULL;
		return SUCCESS;
	}
	else return ERROR;
}


//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if (s->count) { return SUCCESS; }
	return ERROR;
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	if (s->count) {
		*e = s->top->data;
		return SUCCESS;
	}
	return ERROR;
}

//清空栈
Status clearLStack(LinkStack *s){
	StackNode* p;
	if (!s->top) { return ERROR; }
	while (s->top) {
		p = s->top;
		s->top = p->next;
		free(p);
		s->count = 0;
	}return SUCCESS;
	
}

//销毁栈
Status destroyLStack(LinkStack *s){
	clearLStack(s);
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	*length = s->count;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data)
{
	LinkStackPtr p;
	p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (p) {
		p->next = s->top;
		p->data = data;
		s->top = p;
		s->count++;
		return SUCCESS;
	}
	else return ERROR;
}

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	LinkStackPtr p;
	if (s->top) {
		*data = s->top->data;
		p = s->top;
		s->top = p->next;
		free(p);
		s->count--;
		return SUCCESS;
	}
	else return ERROR;
}

//非法输入检测
int Scanf_d(void) {
	unsigned int ret;
	int scan;
	ret = scanf_s("%d", &scan);
	while (ret != 1) {
		while (getchar() != '\n');
		printf("输入错误，请重新输入：");
		ret = scanf_s("%d", &scan);
	}
	while (getchar() != '\n');
	return scan;
}

//菜单
void Menu()
{
	printf("\n\n*************** 系统功能菜单 ***************\n");delay();
	printf("--------------------------------------------\n");delay();
	printf("	1.创建新链栈	2.入栈\n");delay();
	printf("	3.出栈		4.判断栈顶是否为空\n");delay();
	printf("	5.得到栈顶元素	6.检测栈的长度\n");delay();
	printf("	7.清空栈	8.销毁栈\n");delay();
	printf("	9.退出系统\n");delay();
	printf("--------------------------------------------\n");delay();
	printf("********************************************\n");delay();
}

//让菜单出现的时候好看一点点
void delay(void) {
	for (int i = 0;i < 5000;i++)
		for (int j = 0;j < 10000;j++);
}