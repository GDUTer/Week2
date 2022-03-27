#include<stdio.h>
#include<stdlib.h>
typedef struct fuhao {//用于存储符号及其优先级
	char fu;
	int youxianji;
}fuhao;
int main()
{
	printf("四则运算计算器（不支持单目运算符‘-’和‘+’，不支持输入小数）\n提示：若想输入负数，可以用（0 - 正数）代替\n若想输入小数，可用分数代替\n");
	double n = 0;//用于计算过程中暂存数字的变量
	fuhao sfu;
	char s[500];//用于存后缀表达式
	int r = 0;//s[]的指针
	int i=0;
	double num[100];//用于存数字的栈
	int p = 0;//数字指针
	fuhao a[100];//存符号的栈
	int q = 0;//符号指针
	char scan;
	double answer = 0;
	double e = num[0];
	int cntnum = 0,cntfuhao = 1, cnt_right=0, cnt_left=0;//一些计数器（数字，运算符，左右括号），用于判断算式是否合法

	printf("请输入算式（带等号）:\n");
	scanf_s("%c", &scan,1);
	while (scan != '=')//读入算式，并且转为后缀表达式
	{
		if (scan >= '0' && scan <= '9')//数字直接读入
		{
			s[r] = scan;
			r++;
		}
		else if (scan == '+' || scan == '-' || scan == '*' || scan == '/' || scan == '(' || scan == ')')
			//符号的一系列入栈出栈操作
		{
			s[r] = '?';//‘？’用于隔开数字
			r++;
			sfu.fu = scan;//得到运算符
			if (scan == '+' || scan == '-') {//判断运算符的优先级
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
			//符号入栈
			if (q == 0) {//在栈中没有符号时，符号直接入栈
				a[q] = sfu;
				q++;
			}
			else if (sfu.fu == '(') {//左括号可直接入栈
				a[q] = sfu;
				q++;
			}
			else if (sfu.fu == ')')//若输入右括号，则匹配左括号，并使中间所有符号出栈
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
			else {//栈不为空且输入符号为 + - * / 时
				//若优先级不大于栈顶数时，左括号前的所有运算符出栈
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
		else {//若输入不合法的字符，或算式中没有等号，则算式不合法，需重新输入算式
			printf("输入有误\n");
			system("PAUSE");
			return 0;
		}
		scanf_s("%c", &scan, 1);
	}
	while (q >0) {//出栈剩下的所有符号
		if (a[q - 1].fu != '(') {
			s[r] = a[q - 1].fu;
			r++;
		}
		q--;
	}

	//后缀表达式的计算
	for (i = 0;i < r;i++)//遍历后缀表达式
	{
		if (s[i] >= '0' && s[i] <= '9') {//数字入栈
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
		else if (s[i] == '?') {//读掉用于分割数字的‘？’
		}
		else {//读入后缀运算符，并对运算符的前两位数字进行运算
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
	//若运算符数与数字数不匹配，或左右括号数量不匹配，则算式不合法，需重新输入算式
	if ((cntnum != cntfuhao)||(cnt_left!=cnt_right)) {
		printf("输入算式不合法，请重新输入\n");
		system("PAUSE");
		return 0;
	}
	else{//算式合法，输出后缀表达式和计算结果
		printf("后缀表达式为");
		for (i = 0;i < r;i++) {
			if (s[i] != '?') {
				printf("%c ", s[i]);
			}
		}
		printf("\n计算结果为%lf\n", num[0]);
		system("PAUSE");
		return 0;//计算任务圆满完成啦！！！再见！
	}	
}

