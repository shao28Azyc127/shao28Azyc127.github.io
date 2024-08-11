#include <bits/stdc++.h>
using namespace std;
long long n,cnt,day;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	day=0;
	scanf("%lld",&n);
	while(n)
	{
		cnt++;
		if((n-1)%3==0 && day==0) day=cnt;
		n-=((n-1)/3+1);
	}
	printf("%lld %lld",cnt,day);
	return 0;
}
