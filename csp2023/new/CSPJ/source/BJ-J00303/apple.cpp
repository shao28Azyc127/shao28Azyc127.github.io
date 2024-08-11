#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int ret=0,f=1;char c=getchar();
	while(!(c>='0'&&c<='9'))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret*f;
}
int n;
signed main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);	
	n=read();
	int len=n,day=1,flag=0,ans;
	while(len)
	{
		if(len%3==1&&flag==0)
		{
			flag=1;
			ans=day;
		}
		int now=len/3;
		if(len%3) now++;
		len-=now;day++;
	}
	printf("%lld %lld",day-1,ans);
	return 0;
}