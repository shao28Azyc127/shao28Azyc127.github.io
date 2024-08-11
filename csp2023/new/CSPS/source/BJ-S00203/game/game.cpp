#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
inline int read()
{
	int res=0,op=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		op|=ch=='-';
		ch=getchar();
	}
	while(isdigit(ch))
	{
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	return op?-res:res;
}
inline void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
int n,to[2000005],d[2000005];
string s;
ll ans;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();
	cin>>s;
	for(re int i=1;i<=n;++i)
	{
		int j=i-1;
		while(j&&s[j-1]!=s[i-1]) j=to[j];
		if(j)
		{
			to[i]=j-1;
			d[i]=d[j-1]+1;
			ans+=d[i];
		}
	}
	write(ans);
	return 0;
}