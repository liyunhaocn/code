#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define StrSize 100

typedef struct Stack
{
	char data[StrSize];
	int top;
}CulStack, StrStack;

typedef struct intStack
{
	double data[StrSize];
	int top;
}StStack;

// ����׺���ʽ�ַ���ת��Ϊ��׺���ʽ�ַ�����
// �����ַ����飬��'\0'��β��lengthΪ�ַ������ȡ�
// ���ָ��StrStack ��ʽ��ָ�롣
StrStack *Trans(char str[], int length) {
	StrStack *sStack = (StrStack *)malloc(sizeof(StrStack));
	sStack->top = 0;
	StrStack opStack;
	opStack.top = 0;

	for (int i = 0; i < length; i++)
	{
		if (str[i] >= '0' && str[i] <= '9') {
			sStack->data[sStack->top] = str[i];
			sStack->top++;
		}
		if (str[i] == '.') {
			sStack->data[sStack->top] = str[i];
			sStack->top++;
		}
		if (str[i] == '+' || str[i] == '-')
		{
			sStack->data[sStack->top] = ' ';
			sStack->top++;
			while (opStack.top != 0 && opStack.data[opStack.top - 1] != '(')
			{
				sStack->data[sStack->top] = opStack.data[opStack.top - 1];
				sStack->top++;
				opStack.top--;
			}
			opStack.data[opStack.top] = str[i];
			opStack.top++;
		}
		if (str[i] == '*' || str[i] == '/')
		{
			sStack->data[sStack->top] = ' ';
			sStack->top++;
			while (opStack.top != 0 && opStack.data[opStack.top - 1] != '+'&&opStack.data[opStack.top - 1] != '-'&& opStack.data[opStack.top - 1] != '(')
			{
				sStack->data[sStack->top] = opStack.data[opStack.top - 1];
				sStack->top++;
				opStack.top--;
			}
			opStack.data[opStack.top] = str[i];
			opStack.top++;
		}

		if (str[i] == '(')
		{
			opStack.data[opStack.top] = str[i];
			opStack.top++;
		}
		if (str[i] == ')')
		{
			while (opStack.top != 0 && opStack.data[opStack.top - 1] != '(')
			{
				sStack->data[sStack->top] = opStack.data[opStack.top - 1];
				sStack->top++;
				opStack.top--;
			}
			opStack.top--;
		}
	}
	while (opStack.top != 0)
	{
		sStack->data[sStack->top] = opStack.data[opStack.top - 1];
		sStack->top++;
		opStack.top--;
	}
	sStack->data[sStack->top] = '\0';

	return sStack;
}

// ����׺���ʽͨ��ջ�Ľṹ��������
// ����c��ʽ�ַ�������'\0'��β��
// ���int�ͽ����
double Calcul(StrStack *opStack) {
	StStack *sStack = (StStack *)malloc(sizeof(StStack));
	sStack->top = -1;

	double result = 0, num = 0;
	int numLen = 0;

	for (int i = 0; i < opStack->top; i++) {
		// ���ַ���ϳ�double������
		if (opStack->data[i] >= '0' && opStack->data[i] <= '9') {
			num = 0;

			for (numLen = 0; opStack->data[i + numLen] >= '0' && opStack->data[i + numLen] <= '9'; numLen++)
				;
			for (int k = 0; k < numLen; k++)
				num = num + (opStack->data[i + k] - '0') * pow(10, numLen - k - 1);

			/*
			//ɾ�����ֶΣ�20170420
			//���ַ���ϳ����֣��˶ν��������ַ������
			//��������ж�λ���������
			num = 0;
			for (numLen = 0; opStack->data[i + numLen] >= '0' && opStack->data[i + numLen] <= '9'; numLen++)
			num = num + (opStack->data[i + numLen] - '0') * pow(10, numLen);
			*/

			if (opStack->data[i + numLen] == '.') {
				for (int j = -1; opStack->data[i + numLen + 1] >= '0' && opStack->data[i + numLen + 1] <= '9'; numLen++, j--)
					num = num + (opStack->data[i + numLen + 1] - '0') * pow(10.0, j);
				sStack->data[++sStack->top] = num;
				i = i + numLen;
				continue;
			}

			sStack->data[++sStack->top] = num;

			i = i + numLen - 1;
		}
		// �����ո�
		else if (opStack->data[i] == ' ')
			continue;
		// ����
		else {
			switch (opStack->data[i])
			{
			case '+':
				result = sStack->data[sStack->top - 1] + sStack->data[sStack->top];
				sStack->top -= 2;
				sStack->data[++sStack->top] = result;
				break;
			case '-':
				result = sStack->data[sStack->top - 1] - sStack->data[sStack->top];
				sStack->top -= 2;
				sStack->data[++sStack->top] = result;
				break;
			case '*':
				result = sStack->data[sStack->top - 1] * sStack->data[sStack->top];
				sStack->top -= 2;
				sStack->data[++sStack->top] = result;
				break;
			case '/':
				result = sStack->data[sStack->top - 1] / sStack->data[sStack->top];
				sStack->top -= 2;
				sStack->data[++sStack->top] = result;
				break;
			default:
				break;
			}
		}
	}

	free(opStack);

	return result;
}

int main() {
	char in[100];

	printf("��������ʽ��");

	scanf("%s", in);

	StrStack *str = Trans(in, strlen(in));

	printf("��׺���ʽΪ��%s\n", str->data);

	printf("ԭʽ�Ĵ�Ϊ��%lf\n", Calcul(str));

	return 0;
}
