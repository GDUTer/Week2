#include "LQueue.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Node* head = (Node*)malloc(sizeof(Node));
	if (head) {
		Q->front = head;
		Q->rear = head;
		Q->length = 0;
		head->next = NULL;
	}
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	if (Q->front->next)
	{
		Node* p = Q->front->next;
		Q->front->next = p->next;
		free(p);
	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if (Q->front == Q->rear)
		return TRUE;
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q){
	
	if (Q->front->next->type == 'i') {
		printf(" %d", *(int*)Q->front->next->data);
		return TRUE;
	}
	else if (Q->front->next->type == 'c') {
		printf(" %c", *(char*)Q->front->next->data);
		return TRUE;
	}
	else if (Q->front->next->type == 'd') {
		printf(" %lf", *(double*)Q->front->next->data);
		return TRUE;
	}
	else return FALSE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void* data){
	Node* p = (Node*)malloc(sizeof(Node));
	if (p) {
		Q->rear->next = p;
		Q->rear = p;
		p->type = type;
		p->data=(void*)malloc(sizeof(8));
		if (p->data) {
			memcpy(p->data, data, 8);
		}
		p->next = NULL;
		Q->length++;
		return TRUE;
	}
	else return FALSE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if (Q->front->next) {
		Node* p = Q->front->next;
		Q->front->next = p->next;
		free(p);
		if (!Q->front->next) {
			Q->rear = Q->front;
		}
		Q->length--;
		return TRUE;
	}
	return FALSE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	Node* p = Q->front->next;
	while (Q->front->next) {
		Q->front->next= Q->front->next->next;
		free(p);
		Q->length--;
	}
	Q->length = 0;
	Q->rear = Q->front;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
void TraverseLQueue(const LQueue* Q, void (*foo)(Node*)) {
	if (Q->front)
	{
		Node* p = Q->front->next;
		printf("队列中的全部元素为：");
		while (p) 
		{
			foo(p);
			p = p->next;
			printf("--->");
		}
		printf("NULL");		
	}
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void LPrint(Node *p){
	if (p->type == 'i') {
		printf("%d", *(int*)p->data);
	}
	if (p->type == 'c') {
		printf("%c", *(char*)p->data);
	}
	if (p->type == 'd') {
		printf("%lf", *(double*)p->data);
	}
}

void* shuru()
{
	void* p = NULL;
	while (1) {
		printf("(c：char型     i：int型     d：double型\n请选择入队数据的类型：");
		scanf_s("%c", &type, 1);
		while (getchar() != '\n');
		if (type == 'c') {
			printf("入队数据：");
			scanf_s("%c", &ch, 1);
			while (getchar() != '\n');
			p = &ch;
			break;
		}
		else if (type == 'i') {
			printf("入队数据：");
			scanf_s("%d", &in);
			while (getchar() != '\n');
			p = &in;
			break;
		}
		else if (type == 'd') {
			printf("入队数据：");
			scanf_s("%lf", &db);
			while (getchar() != '\n');
			p = &db;
			break;
		}
		else (printf("请输入正确的选项\n"));
	}
	return p;
}

void Menu()
{
	printf("\n\n\n"
		"******************* 系统功能菜单 ********************\n"
		"-----------------------------------------------------\n"
		"	1.初始化队列		2.检查队列是否为空\n"
		"	3.入队操作		4.出队操作\n"
		"	5.查看队头元素		6.确定队列长度\n"
		"	7.清空队列		8.销毁队列\n"
		"	9.查遍历并输出队列	10.退出系统\n"
		"-----------------------------------------------------\n");
}

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

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
