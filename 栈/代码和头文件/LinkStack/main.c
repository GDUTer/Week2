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
		printf("\n��ѡ��˵����:");
		scan = Scanf_d();//�������Ĳ˵����
		if (!(scan < 10 && scan >0)) {//���벻�Ϸ��˵����ʱ����ʾ
			printf("��������ȷ�Ĳ˵����\n");
		}
		else if (scan == 9) { //����9ʱ�������ʾ���˳�ϵͳ
			system("cls");
			return 0;
		}
		else if (scan < 10 && scan >0)//�������Ϸ��˵����
		{
			if (scan == 1) {//��ʼ����ջ
				if(flag){ clearLStack(&stack); }//���ջ�Ѵ��ڣ������ջ�ͷ��ڴ�
				initLStack(&stack);
				printf("��ջ��ʼ���ɹ�^-^");
				flag = 1;
			}
			if (flag == 1)//����Ѿ���ʼ����ջ����ɽ������²���
			{
				if (scan == 2) {//��ջ
					printf("��������ջ�����ݣ�");
					num = Scanf_d();
					pushLStack(&stack, num);
					printf("������ջ�ɹ�^-^\n");
				}
				if (scan == 3) {//��ջ
					if (stack.count) {
						popLStack(&stack, &num);
						printf("��ջ����Ϊ %d ,��ջ�ɹ�^-^", num);
					}
					else printf("��ջΪ�գ��޷���ջ\n");
				}
				if (scan == 4) {//�ж�ջ�Ƿ�Ϊ��
					if (stack.count)
						printf("��ջ��Ϊ��^-^\n");
					else
						printf("��ջΪ��^-^\n");
				}
				if (scan == 5)//�õ�ջ��Ԫ��
					if (stack.count) {
						getTopLStack(&stack, &num);
						printf("ջ��Ԫ��Ϊ %d ^-^\n", num);
					}
					else printf("��ջΪ�գ���ջ��Ԫ��\n");
				if (scan == 6) {//�õ���ǰջ������
					LStackLength(&stack, &num);
					printf("��ջ��ǰ����Ϊ %d ^-^", num);
				}
				if (scan == 7) {//���ջ
					clearLStack(&stack);
					printf("��ջ��ճɹ�^-^\n");
				}
				if (scan == 8) {//����ջ
					destroyLStack(&stack);
					printf("��ջ���ٳɹ�^-^\n");
					flag = 0;
				}
			}
			else printf("��ջ�����ڣ����ȳ�ʼ����ջ\n");
		}
		
	}
}

