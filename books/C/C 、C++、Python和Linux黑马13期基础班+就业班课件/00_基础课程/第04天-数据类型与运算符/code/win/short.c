#include <stdio.h>

int main()
{
	short a = 0;
	size_t len = sizeof(a);//�õ�a�Ĵ�С
	printf("%u\n", len);
	int b = 0x7ffffffe;
	a = b;
	printf("%d\n", a);
	a = -2;
	b = a;//b����-2�Ĳ���,c���Ա��������Զ���2���ֽڵ�-2����ת��Ϊ4���ֽڵ�-2����
	printf("%d\n", b);
	long c = 0;
	len = sizeof(c);
	printf("%u\n", len);
	len = sizeof(long long);
	printf("%u\n", len);
	c = 100;
	return 0;
}
