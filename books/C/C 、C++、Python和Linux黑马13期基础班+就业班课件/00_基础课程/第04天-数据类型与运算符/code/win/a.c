#include <stdio.h>

int main()
{
	int a = 02572575257;//����ط����õİ˽���
	//printf("a = %d\n", a);//�����ʱ����10����
	a = 0x554410f5;

	printf("a = %d\n", a);
	int i = sizeof(a);//����a��ռ�ÿռ��С
	printf("i = %d\n", i);//i����Ľ����4��֤��a��4���ֽڴ�С������һ��DWORD
	a = 0x7fffffff;
	printf("a = %d\n", a);
	a = 2147483647 + 5;
	printf("a = %d\n", a);

	a = 0x7ffffffc;
	printf("%d\n", a);
	
	return 0;
}
