#include "LQueue.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
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
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if (Q->front == Q->rear)
		return TRUE;
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
void TraverseLQueue(const LQueue* Q, void (*foo)(Node*)) {
	if (Q->front)
	{
		Node* p = Q->front->next;
		printf("�����е�ȫ��Ԫ��Ϊ��");
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
 *    @description : ��������
 *    @param         q ָ��q
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
		printf("(c��char��     i��int��     d��double��\n��ѡ��������ݵ����ͣ�");
		scanf_s("%c", &type, 1);
		while (getchar() != '\n');
		if (type == 'c') {
			printf("������ݣ�");
			scanf_s("%c", &ch, 1);
			while (getchar() != '\n');
			p = &ch;
			break;
		}
		else if (type == 'i') {
			printf("������ݣ�");
			scanf_s("%d", &in);
			while (getchar() != '\n');
			p = &in;
			break;
		}
		else if (type == 'd') {
			printf("������ݣ�");
			scanf_s("%lf", &db);
			while (getchar() != '\n');
			p = &db;
			break;
		}
		else (printf("��������ȷ��ѡ��\n"));
	}
	return p;
}

void Menu()
{
	printf("\n\n\n"
		"******************* ϵͳ���ܲ˵� ********************\n"
		"-----------------------------------------------------\n"
		"	1.��ʼ������		2.�������Ƿ�Ϊ��\n"
		"	3.��Ӳ���		4.���Ӳ���\n"
		"	5.�鿴��ͷԪ��		6.ȷ�����г���\n"
		"	7.��ն���		8.���ٶ���\n"
		"	9.��������������	10.�˳�ϵͳ\n"
		"-----------------------------------------------------\n");
}

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

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
