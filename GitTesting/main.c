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

void g(const int x, const int y)
{
	return x * y;
}

int faktorijel(int x)
{
	int i,p=1;
	for (i = ;i <= x;i++)
		p *= i;
	return p;

}
int main()
{
	int a = 2, b = 4,x;
	printf("Unesi broj:");
	scanf("%d", &x);
	int p = faktorijel(x);
	printf("Faktorijel broja %d je %d!", x, p);
	printf("a="); scanf_s("%d", &a);
	printf("b="); scanf_s("%d", &b);
	printf("2`4= %d", Stepen(a, b));
	f();
	int c = g(5, 6);
	cout << c;
	getchar();
	getchar();
	return 0;
}