#include <stdio.h>

int main()
{
	signed int a;//������һ���з��ŵ�int,ʡ�Ե�signed����ؼ��֣������з���
	a = 13;
	printf("a = %d\n", a);//���з��ŵ�ʮ���Ʒ�ʽ���
	printf("a = %o\n", a);//���з��ŵİ˽��Ʒ�ʽ���
	printf("a = %x\n", a);//���з��ŵ�ʮ�����Ʒ�ʽ���
	printf("a = %X\n", a);//���з��ŵ�ʮ�����Ʒ�ʽ���
	unsigned int b;//������һ���޷��ŵ�int�����λ�Ͳ��Ƿ���λ��
	b = 0;
	b = 0xffffffff;
	a = 0x7fffffff;
	a = 10;
	b = 100;
	printf("a = %u, b = %u\n", a, b);//ͬʱ���a��b��ֵ
	a = -5;
	printf("a = %u\n", a);//���޷��������һ������
	b = a - 1;
	printf("b = %x\n", b);
	b = 0xfffffff5;
	a = b;
	printf("a = %d\n", a);
	a = -2;
	printf("%x\n", a);
	return 0;
}
