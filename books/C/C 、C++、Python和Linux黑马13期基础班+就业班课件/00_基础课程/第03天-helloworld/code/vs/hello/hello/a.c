#include <stdio.h>

int main()
{
	int a;//����һ�����������ֽ�a
	int b;
	int c;
	
	a = 2;
	b = 3;
	c = a + b;
	
	/*
	__asm
	{
		mov a, 2//��2�ŵ�a����
		mov b, 3
		mov eax, a//��a�ŵ��Ĵ���eax����
		add eax, b//��b��eax�ӣ����Ժ�Ľṹ����eax
		mov c, eax//��eax��ֵ����c

	}
	*/
	printf("c = %d\n", c);
	return 0;
}