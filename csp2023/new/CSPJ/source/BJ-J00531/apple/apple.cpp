#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans,cnt;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	scanf("%lld",&n);
	while(n)
	{
		cnt++;
		if(!ans&&(n-1)%3==0) ans=cnt;
		n-=1+(n-1)/3;
	}
	printf("%lld %lld",cnt,ans);
	return 0;
}