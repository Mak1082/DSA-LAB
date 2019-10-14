#include<iostream>
using namespace std;

int multiplyTwoDigits(int a, int b)
{
	int c2,c1,c0;
	c2=a/10*b/10;
	c0=a%10*b%10;
	c1=(a/10+a%10)*(b/10+b%10)-c2-c0;
	c=100*c2+10*c1+c0;
	return c;
}

int main()
{
	int n1,n2;
	cin>>n1>>n2;
	int a1=n1/100; int a0=n1%100;
	int b1=n2/100; int b0=n2%100;
	
}
