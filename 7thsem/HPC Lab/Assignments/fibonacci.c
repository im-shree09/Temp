#include<stdio.h>
#include<omp.h>

int fib(int n)

{
	int f[n+2];
	int i;
	#pragma omp task
	{
		f[0] = 0;
		f[1] = 1;
	}
	#pragma omp task
	{
		for (i = 2; i <= n; i++)
	{
		f[i] = f[i-1] + f[i-2];
	}
	}
	#pragma omp taskwait
	{
	return f[n];
}
}


int main ()

{
	int n = 10; 
	#pragma omp parallel
	{
	printf("%d", fib(n));
	}
	getchar();
	return 0;
}



