#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// 구조체 선언
typedef struct _astack
{
	char* data1;
	bool* data2;
	int stack_size;
}astack;

// 동적할당하기
void initializeStack(astack* s, int stackMaxSize)
{
	s->data1 = calloc(stackMaxSize, sizeof(char));
	s->data2 = calloc(stackMaxSize, sizeof(bool));
	s->stack_size = 0;
}
// Stack의 push
void pushStack(astack* s, char v1)
{
	s->data1[s->stack_size] = v1;
	s->stack_size++;
}
// 피연산자가 1개인 경우
void one(astack* s1, astack* s2)
{
	int ba;
	bool truthtab[2];
	printf("%c RESULT\n\n", s1->data1[0]);
	for (int i = 1; i <= 2; i++)
	{
		int temp = i;
		ba = i % 2;
		bool baa = (bool)ba;
		for (int j = 0; j < strlen(s1->data1); j++)
			s1->data2[j] = baa;
		truthtab[0] = baa;
		char copy[20];
		strcpy(copy, s2->data1);
		
		for (int j = 0; j < strlen(copy); j++)
		{
			if (copy[j] == 'n')
			{		
				int numof = 0;
				for (int k = 0; k <= j; k++)
				{
					if (copy[k] != 'n')
						numof++;
				}
				s1->data2[numof] = !s1->data2[numof];
				copy[j] = 0;
				for (int k = 0; copy[k]; k++)
				{
					if (copy[k] == 0)
					{
						for (int w = k; copy[w]; k++)
							copy[w] = copy[w + 1];
						copy[strlen(copy) - 1] = 0;
					}
				}
			}  		
		}
		
		for (int j = 0; j< strlen(copy); j++)
		{
			if (copy[j] == 'a')
				s1->data2[j + 1] = s1->data2[j] && s1->data2[j + 1];
			else if (copy[j] == 'o')
				s1->data2[j + 1] = s1->data2[j] || s1->data2[j + 1];
			else if (copy[j] == 'i')
			{
				if (s1->data2[j] == true && s1->data2[j + 1] == false)
					s1->data2[j + 1] = false;
				else if (s1->data2[j] == false && s1->data2[j + 1] == false)
					s1->data2[j + 1] = true;
				else
					s1->data2[j + 1] = s1->data2[j] || s1->data2[j + 1];
			}
		}
		truthtab[1] = s1->data2[strlen(copy)];
		// 출력
		for (int j = 0; j < 1; j++)
		{
			if (truthtab[j] == true)
				printf("T ");
			else
				printf("F ");
		}
		if (truthtab[1] == true)
			printf("T");
		else
			printf("F");
		if(i < 2)
			printf("\n\n");
	}
}
//피연산자가 2개인 경우
void two(astack* s1, astack* s2)
{
	int ba, bb;
	bool truthtab[3];
	char typevar[2]; 
	char max = s1->data1[0];
	char min = s1->data1[0];
	for (int i = 0; i < strlen(s1->data1); i++) {
		if (s1->data1[i] == 0)
			continue;
		if (s1->data1[i] > max) max = s1->data1[i];
		if (s1->data1[i] < min) min = s1->data1[i];
	}
	typevar[0] = (char)min;
	typevar[1] = (char)max;

	printf("%c %c RESULT\n\n", typevar[0], typevar[1]);

	for (int i = 1; i <= 4; i++)
	{
		int temp = i;
		if (i / 3 >= 1)
			ba = 0;
		else
			ba = 1;
		bb = i % 2;
		truthtab[0] = ba;
		truthtab[1] = bb;
		char copy[20];
		strcpy(copy, s2->data1);
		for (int j = 0; j <= strlen(copy); j++)
		{
			if (s1->data1[j] == typevar[0])
				s1->data2[j] = ba;
			else if (s1->data1[j] == typevar[1])
				s1->data2[j] = bb;
		}

		for (int j = 0; j < strlen(copy); j++)
		{
			if (copy[j] == 'n')
			{
				int numof = 0;
				for (int k = 0; k <= j; k++)
				{
					if (copy[k] != 'n')
						numof++;
				}
				s1->data2[numof] = !s1->data2[numof];
				copy[j] = 0;
				for (int k = 0; copy[k]; k++)
				{
					if (copy[k] == 0)
					{
						for (int w = k; copy[w]; k++)
							copy[w] = copy[w + 1];
						copy[strlen(copy) - 1] = 0;
					}
				}
			}
		}

		for (int j = 0; j < strlen(copy); j++)
		{
			if (copy[j] == 'a')
				s1->data2[j + 1] = s1->data2[j] && s1->data2[j + 1];
			else if (copy[j] == 'o')
				s1->data2[j + 1] = s1->data2[j] || s1->data2[j + 1];
			else if (copy[j] == 'i')
			{
				if (s1->data2[j] == true && s1->data2[j + 1] == false)
					s1->data2[j + 1] = false;
				else if(s1->data2[j] == false && s1->data2[j + 1] == false)
					s1->data2[j + 1] = true;
				else
					s1->data2[j + 1] = s1->data2[j] || s1->data2[j + 1];
			}
		}
		truthtab[2] = s1->data2[strlen(copy)];
		// 출력
		for (int j = 0; j < 2; j++)
		{
			if (truthtab[j] == true)
				printf("T ");
			else
				printf("F ");
		}
		if (truthtab[2] == true)
			printf("T");
		else
			printf("F");
		if(i < 4)
			printf("\n\n");
	}
}
//피연산자가 3개인 경우
void three(astack *s1, astack *s2)
{
	int ba, bb, bc;
	bool truthtab[4];
	char typevar[3] = { 0 };
	char max = s1->data1[0];
	char min = s1->data1[0];
	char mid = s1->data1[0];
	for (int i = 0; i < strlen(s1->data1); i++) {
		if (s1->data1[i] == 0)
			continue;
		if (s1->data1[i] > max) max = s1->data1[i];
		if (s1->data1[i] < min) min = s1->data1[i];
	}
	typevar[0] = (char)min;
	typevar[2] = (char)max;
	for (int k = 0; k < strlen(s1->data1); k++)
	{
		if (s1->data1[k] != max && s1->data1[k] != min)
		{
			mid = s1->data1[k];
			break;
		}
	}
	typevar[1] = (char)mid;
	printf("%c %c %c RESULT\n\n", typevar[0], typevar[1], typevar[2]);
	for (int i = 1; i < 9; i++)
	{
		int temp = i;
		if (temp / 5 == 0)
			ba = 1;
		else
			ba = 0;
		if (temp % 4 == 1 || temp % 4 == 2)
			bb = 1;
		else
			bb = 0;
		bc = i % 2;
		truthtab[0] = ba;
		truthtab[1] = bb;
		truthtab[2] = bc;
		char copy[20];
		strcpy(copy, s2->data1);
		for (int j = 0; j <= strlen(copy); j++)
		{
			if (s1->data1[j] == typevar[0])
				s1->data2[j] = ba;
			else if (s1->data1[j] == typevar[1])
				s1->data2[j] = bb;
			else if (s1->data1[j] == typevar[2])
				s1->data2[j] = bc;
		}
		
		for (int j = 0; j < strlen(copy); j++)
		{
			if (copy[j] == 'n')
			{
				int numof = 0;
				for (int k = 0; k <= j; k++)
				{
					if (copy[k] != 'n')
					{
						numof++;
					}
				}
				s1->data2[numof] = !s1->data2[numof];
			}
		}
		for (int j = 0; j < strlen(copy); j++)
		{
			if (copy[j] == 'n')
			{
				for (int k = j; k < strlen(copy); k++)
					copy[j] = copy[j + 1];
				copy[strlen(copy) - 1] = 0;
			}
		}
		
		for (int j = 0; j < strlen(copy); j++)
		{
			if (copy[j] == 'a')
				s1->data2[j + 1] = s1->data2[j] && s1->data2[j + 1];
			else if (copy[j] == 'o')
				s1->data2[j + 1] = s1->data2[j] || s1->data2[j + 1];
			else if (copy[j] == 'i')
			{
				if (s1->data2[j] == true && s1->data2[j + 1] == false)
					s1->data2[j + 1] = false;
				else if (s1->data2[j] == false && s1->data2[j + 1] == false)
					s1->data2[j + 1] = true;
				else
					s1->data2[j + 1] = s1->data2[j] || s1->data2[j + 1];
			}
		}
		truthtab[3] = s1->data2[strlen(copy)];
		//출력
		for (int j = 0; j < 3; j++)
		{
			if (truthtab[j] == true)
				printf("T ");
			else
				printf("F ");
		}
		if (truthtab[3] == true)
			printf("T");
		else
			printf("F");
		if (i < 8)
			printf("\n\n");
	}
}
// 2 2 5
// P i Q a Q
// 2 3 7
// P i Q a Q i P
// 진리표 작성해주는 문제
int main()
{
	int anum, onum, sum;
	char pro[20];
	scanf("%d %d %d %[^\n]s", &anum, &onum, &sum, pro);
	int length = strlen(pro);
	for (int i = 0; i < length; i++)
	{
		if (pro[i] == ' ')
			strcpy(&pro[i], &pro[i + 1]);
	}
	astack operand;
	astack oper;
	initializeStack(&operand, sum);
	initializeStack(&oper, sum);
	for (int i = 0; i < strlen(pro); i++)
	{
		if (pro[i] >= 'A' && pro[i] <= 'Z')
			pushStack(&operand, pro[i]);
		else if (pro[i] >= 'a' && pro[i] <= 'z')
			pushStack(&oper, pro[i]);
	}
	if (anum == 1)
		one(&operand, &oper);
	else if (anum == 2)
		two(&operand, &oper);
	else if (anum == 3)
		three(&operand, &oper);
	free(operand.data1);
	free(operand.data2);
	free(oper.data1);
	free(oper.data2);
	return 0;
}
