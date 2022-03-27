#include "LQueue.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//"	1.��ʼ������		2.�������Ƿ�Ϊ��\n"
//"	3.��Ӳ���		4.���Ӳ���\n"
//"	5.�鿴��ͷԪ��		6.ȷ�����г���\n"
//"	7.��ն���		8.���ٶ���\n"
//"	9.��������������	10.�˳�ϵͳ\n"
int main()
{
	LQueue  Queue1;
	void* p;
	Menu();
	int scan;
	int flag = 0;
	while (1)
	{
		printf("\n��ѡ��˵����:");
		scan = Scanf_d();//�������Ĳ˵����
		if (!(scan < 11 && scan >0)) {//���벻�Ϸ��˵����ʱ����ʾ
			printf("��������ȷ�Ĳ˵����\n");
		}
		else if (scan == 10) { //����10ʱ�������ʾ���˳�ϵͳ
			system("cls");
			return 0;
		}
		else if (scan < 10 && scan >0)//�������Ϸ��˵����
		{
			if (scan == 1) {//��ʼ�����Ͷ���
				if (flag) { ClearLQueue(&Queue1); }//��������Ѵ��ڣ�����ն����ͷ��ڴ�
				InitLQueue(&Queue1);
				printf("���г�ʼ���ɹ�^-^");
				flag = 1;
			}
			if (flag == 1)//����Ѿ���ʼ�����У���ɽ������²���
			{
				if (scan == 2) {//�ж϶����Ƿ�Ϊ��
					if (IsEmptyLQueue(&Queue1) == TRUE)
						printf("����Ϊ��^-^\n");
					else
						printf("���в�Ϊ��^-^\n");
				}
				if (scan == 3) {//���
					p = shuru();
					EnLQueue(&Queue1, p);
					printf("��ӳɹ�^-^\n");
				}
				if (scan == 4) {//����
					if (Queue1.length) {
						printf("����Ԫ��Ϊ");
						GetHeadLQueue(&Queue1);
						DeLQueue(&Queue1);
						printf(" �����ӳɹ�^-^\n");
					}
					else printf("����Ϊ�գ��޷�����\n");
				}
				if (scan == 5)//�鿴��ͷԪ��
					if (Queue1.length) {
						printf("��ͷԪ��Ϊ");
						GetHeadLQueue(&Queue1);
						printf(" ^-^\n");
					}
					else printf("����Ϊ�գ��޶�ͷԪ��\n");
				if (scan == 6) {//ȷ�����г���
					printf("���е�ǰ����Ϊ %d ^-^", LengthLQueue(&Queue1));
				}
				if (scan == 7) {//��ն���
					ClearLQueue(&Queue1);
					printf("������ճɹ�^-^\n");
				}
				if (scan == 8) {//���ٶ���
					DestoryLQueue(&Queue1);
					printf("�������ٳɹ�^-^\n");
					flag = 0;
				}
				if (scan == 9) {//�������������
					TraverseLQueue(&Queue1, LPrint);
				}
			}
			else printf("���в����ڣ����ȳ�ʼ������\n");
		}

	}

	return 0;
}
