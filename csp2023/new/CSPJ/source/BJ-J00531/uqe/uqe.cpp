#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,M;
double a,b,c;
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	scanf("%lld%lld",&T,&M);
	while(T--)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		double e=b*b-4*a*c;
		if(e<0) printf("NO\n");
		else
		{
			double ans=max((-b+sqrt(e))/2,(-b+sqrt(e))/2);
			if((long long)ans==ans)
			{
				printf("%lld\n",(long long)ans);
				continue;
			}
		}
	}
	return 0;
}