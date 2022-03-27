#include<stdio.h>
#include<stdlib.h>
#include "LinkStack.h"

//��ջ

//��ʼ��ջ
Status initLStack(LinkStack* s)
{
	if (s) {
		(s)->count = 0;
		(s)->top = NULL;
		return SUCCESS;
	}
	else return ERROR;
}


//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	if (s->count) { return SUCCESS; }
	return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if (s->count) {
		*e = s->top->data;
		return SUCCESS;
	}
	return ERROR;
}

//���ջ
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

//����ջ
Status destroyLStack(LinkStack *s){
	clearLStack(s);
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	*length = s->count;
}

//��ջ
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

//��ջ
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

//�Ƿ�������
int Scanf_d(void) {
	unsigned int ret;
	int scan;
	ret = scanf_s("%d", &scan);
	while (ret != 1) {
		while (getchar() != '\n');
		printf("����������������룺");
		ret = scanf_s("%d", &scan);
	}
	while (getchar() != '\n');
	return scan;
}

//�˵�
void Menu()
{
	printf("\n\n*************** ϵͳ���ܲ˵� ***************\n");delay();
	printf("--------------------------------------------\n");delay();
	printf("	1.��������ջ	2.��ջ\n");delay();
	printf("	3.��ջ		4.�ж�ջ���Ƿ�Ϊ��\n");delay();
	printf("	5.�õ�ջ��Ԫ��	6.���ջ�ĳ���\n");delay();
	printf("	7.���ջ	8.����ջ\n");delay();
	printf("	9.�˳�ϵͳ\n");delay();
	printf("--------------------------------------------\n");delay();
	printf("********************************************\n");delay();
}

//�ò˵����ֵ�ʱ��ÿ�һ���
void delay(void) {
	for (int i = 0;i < 5000;i++)
		for (int j = 0;j < 10000;j++);
}