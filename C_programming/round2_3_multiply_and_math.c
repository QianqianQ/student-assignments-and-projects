#include <stdio.h>
int simple_multiply(int a, int b)
{
	scanf("%d %d", &a,&b);
	int c = a*b;
	printf("%d * %d = %d\n", a, b, c);
	return 0;
}
void simple_math(void)
{
	float num1, num2;
	char sym;
	scanf("%f %c %f", &num1,&sym,&num2);
	if (sym == '+')
		printf("%.1f\n", num1 + num2);
	else if(sym=='-')
		printf("%.1f\n", num1 - num2);
	else if (sym == '*')
		printf("%.1f\n", num1*num2);
	else if (sym == '/')
		printf("%.1f\n", num1/num2);
	else
		printf("ERR\n");
}

int main(void)
{
	int n1=0;
	int n2=0;
	simple_multiply(n1,n2);
	simple_math();
	return 0; 
	
}