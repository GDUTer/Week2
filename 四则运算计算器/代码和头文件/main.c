#include<stdio.h>
#include<stdlib.h>
typedef struct fuhao {//���ڴ洢���ż������ȼ�
	char fu;
	int youxianji;
}fuhao;
int main()
{
	printf("�����������������֧�ֵ�Ŀ�������-���͡�+������֧������С����\n��ʾ���������븺���������ã�0 - ����������\n��������С�������÷�������\n");
	double n = 0;//���ڼ���������ݴ����ֵı���
	fuhao sfu;
	char s[500];//���ڴ��׺���ʽ
	int r = 0;//s[]��ָ��
	int i=0;
	double num[100];//���ڴ����ֵ�ջ
	int p = 0;//����ָ��
	fuhao a[100];//����ŵ�ջ
	int q = 0;//����ָ��
	char scan;
	double answer = 0;
	double e = num[0];
	int cntnum = 0,cntfuhao = 1, cnt_right=0, cnt_left=0;//һЩ�����������֣���������������ţ��������ж���ʽ�Ƿ�Ϸ�

	printf("��������ʽ�����Ⱥţ�:\n");
	scanf_s("%c", &scan,1);
	while (scan != '=')//������ʽ������תΪ��׺���ʽ
	{
		if (scan >= '0' && scan <= '9')//����ֱ�Ӷ���
		{
			s[r] = scan;
			r++;
		}
		else if (scan == '+' || scan == '-' || scan == '*' || scan == '/' || scan == '(' || scan == ')')
			//���ŵ�һϵ����ջ��ջ����
		{
			s[r] = '?';//���������ڸ�������
			r++;
			sfu.fu = scan;//�õ������
			if (scan == '+' || scan == '-') {//�ж�����������ȼ�
				sfu.youxianji = 1;
			}
			else if (scan == '*' || scan == '/') {
				sfu.youxianji = 2;
			}
			else if (scan == '(' || scan == ')') {
				if (scan == '(') cnt_left++;
				else cnt_right++;
				sfu.youxianji = 3;
			}
			//������ջ
			if (q == 0) {//��ջ��û�з���ʱ������ֱ����ջ
				a[q] = sfu;
				q++;
			}
			else if (sfu.fu == '(') {//�����ſ�ֱ����ջ
				a[q] = sfu;
				q++;
			}
			else if (sfu.fu == ')')//�����������ţ���ƥ�������ţ���ʹ�м����з��ų�ջ
			{
				q--;
				while (a[q].fu != '('&&q>0) {
					if (a[q].fu!= 'c') {
						s[r] = a[q].fu;
						r++;
					}
					q--;
				}
			}
			else {//ջ��Ϊ�����������Ϊ + - * / ʱ
				//�����ȼ�������ջ����ʱ��������ǰ�������������ջ
				while ((sfu.youxianji <= a[q - 1].youxianji && a[q-1].fu!='(') && q != 0)
				{
					if (a[q - 1].fu != '(') {
						s[r] = a[q - 1].fu;
						r++;
					}
					q--;
				}
				a[q] = sfu;
				q++;
			}
		}
		else {//�����벻�Ϸ����ַ�������ʽ��û�еȺţ�����ʽ���Ϸ���������������ʽ
			printf("��������\n");
			system("PAUSE");
			return 0;
		}
		scanf_s("%c", &scan, 1);
	}
	while (q >0) {//��ջʣ�µ����з���
		if (a[q - 1].fu != '(') {
			s[r] = a[q - 1].fu;
			r++;
		}
		q--;
	}

	//��׺���ʽ�ļ���
	for (i = 0;i < r;i++)//������׺���ʽ
	{
		if (s[i] >= '0' && s[i] <= '9') {//������ջ
			while (s[i] >='0'&&s[i]<='9' && i<r)
			{	
				n *= 10;
				n += s[i] - '0';
				i++;
				cntnum++;
			}
			i--;
			num[p] = n;
			n = 0;
			p++;
		}
		else if (s[i] == '?') {//�������ڷָ����ֵġ�����
		}
		else {//�����׺������������������ǰ��λ���ֽ�������
			//if (p > 1) {
				cntfuhao++;
				if (s[i] == '+') {
					n = num[p - 2] + num[p - 1];
					p--;
					num[p - 1] = n;
					n = 0;
				}
				else if (s[i] == '-') {
					num[p - 1] = -num[p - 1];
					n = num[p - 2] + num[p - 1];
					p--;
					num[p - 1] = n;
					n = 0;
				}
				else if (s[i] == '*') {
					n = num[p - 2] * num[p - 1];
					p--;
					num[p - 1] = n;
					n = 0;
				}
				else if (s[i] == '/') {
					n = num[p - 2] / num[p - 1];
					p--;
					num[p - 1] = n;
					n = 0;
				}
		}
	}
	//�������������������ƥ�䣬����������������ƥ�䣬����ʽ���Ϸ���������������ʽ
	if ((cntnum != cntfuhao)||(cnt_left!=cnt_right)) {
		printf("������ʽ���Ϸ�������������\n");
		system("PAUSE");
		return 0;
	}
	else{//��ʽ�Ϸ��������׺���ʽ�ͼ�����
		printf("��׺���ʽΪ");
		for (i = 0;i < r;i++) {
			if (s[i] != '?') {
				printf("%c ", s[i]);
			}
		}
		printf("\n������Ϊ%lf\n", num[0]);
		system("PAUSE");
		return 0;//��������Բ��������������ټ���
	}	
}

