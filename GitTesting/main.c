#include <stdio.h>
#include <stdlib.h>

int Stepen(int x, int y)
{
	int r = 2;
	for (int i = 0; i < y; i++)
		r *= x;
	return r;
}

void f()
{
	printf("\nOvo nije normalno!\n");
}

int main()
{
	int a = 2, b = 4;
	printf("a="); scanf_s("%d", &a);
	printf("b="); scanf_s("%d", &b);
	printf("2`4= %d", Stepen(a, b));
	f();
	getchar();
	getchar();
	return 0;
}