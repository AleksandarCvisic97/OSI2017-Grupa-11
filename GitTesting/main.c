#include <stdio.h>
#include <stdlib.h>

int Stepen(int x, int y)
{
	int r = 1;
	for (int i = 0; i < y; i++)
		r *= x;
	return r;
}

int main()
{
	int a = 2, b = 4;
	printf("a="); scanf_s("%d", &a);
	printf("b="); scanf_s("%d", &b);
	printf("2`4= %d", Stepen(a, b));
	getchar();
	getchar();
	return 0;
}