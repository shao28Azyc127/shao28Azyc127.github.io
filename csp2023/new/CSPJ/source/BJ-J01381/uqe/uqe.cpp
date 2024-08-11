#include<bits/stdc++.h>
using namespace std;
double t,m,a,b,c,x1,x2;
int main()
{
	scanf("%d%d",&t,&m);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,c);
		long long delta=pow(b),d=4*a;
		delta-=c*d;
		if(delta<0)
		{
			printf("NO");
			continue;
		}
		x1=-b+sqrt(delta),x2=-b-sqrt(delta);
		x1/=2,x2/=2;
		printf("%f",x1);
		printf("%f",x2);
	}
	return 0;
}
