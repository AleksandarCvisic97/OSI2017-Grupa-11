#include <stdio.h>
#include <stdlib.h>

int Stepen(int x, int y)
{
	int r = 1;
	for (int i = 0; i < y; i++)
		r *= x;
	return r;
}

int fakt(int x)
{
	int r = 1;
	for (int i = 0; i < x; i++)
		r *= (x - i);
	return r;
}

int main()
{
	int a = 2, b = 4,c;
	printf("a="); scanf_s("%d", &a);
	printf("b="); scanf_s("%d", &b);
	printf("2`4= %d", Stepen(a, b));
	printf("c="); scanf_s("%d", &c);
	printf("\nFaktorijel: %d", fakt(c));
	getchar();
	getchar();
	return 0;
}