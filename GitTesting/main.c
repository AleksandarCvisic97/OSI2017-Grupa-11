#include <stdio.h>
#include <stdlib.h>

int Stepen(int x, int y)
{
	int r = 1;
	for (int i = 0; i < y; i++)
		r *= x;
	return r;
}

void f()
{
	printf("\nOvo nije normalno!\n");
}

int g(const int x, const int y)
{
	return x * y;
}

int faktorijel(int x)
{
	int i,p=1;
	for (i =0 ;i <= x;i++)
		p *= i;
	return p;

}

int sumOfDigits(int x)
{
	int s = 0;
	while (x)
	{
		s += x % 10;
		x /= 10;
	}
	return s;
}

void funkCIA()
{
	printf("\ntest, proba, test\n");
}

int main()
{
	int a = 2, b = 4,y;
	printf("Unesi broj:");
	scanf("%d", &y);
	int p = faktorijel(y);
	printf("Suma cifara broja %d je %d.\n", y, sumOfDigits(y));
	printf("Faktorijel broja %d je %d!", y, p);
	printf("a="); scanf_s("%d", &a);
	printf("b="); scanf_s("%d", &b);
	printf("2`4= %d", Stepen(a, b));
	f();
	int c = g(5, 6);
	printf("%d", c);
	funkCIA();
	getchar();
	getchar();
	return 0;
}
