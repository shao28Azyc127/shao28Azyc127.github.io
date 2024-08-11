#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans1,ans2;
bool flag=1;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	scanf("%lld",&n);
	while(n!=0)
	{
		ans1++;
		if(n%3==1&&flag==1)
		{
			flag=0;
			ans2=ans1;
		}
		if(n%3!=0)
		{
			n=n-(n/3)-1;
		}
		else
		{
			n=n-(n/3);
		}
	}
	printf("%lld %lld",ans1,ans2);
	return 0;
}