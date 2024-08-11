#include<bits/stdc++.h>
using namespace std;
long long t,m;
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	scanf("%lld%lld",&t,&m);
	for(long long i=1;i<=t;i++)
	{
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long der=b*b-4*a*c;
		if(der<0)
		{
			printf("NO\n");
		}
		else
		{
			long long num1=((-b)+sqrt(der))/(2*a);
			long long num2=((-b)-sqrt(der))/(2*a);
			printf("%lld\n",max(num1,num2));
		}
	}
	return 0;
}