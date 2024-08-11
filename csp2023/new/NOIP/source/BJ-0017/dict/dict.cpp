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
inline void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
int n,m,minc[3005],maxc[3005];
string s;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();
	m=read();
	for(re int i=1;i<=n;++i)
	{
		minc[i]=26;
		cin>>s;
		for(re int j=0;j<m;++j)
		{
			maxc[i]=max(maxc[i],s[j]-'a');
			minc[i]=min(minc[i],s[j]-'a');
		}
	}
	for(re int i=1;i<=n;++i)
	{
		bool flag=1;
		for(re int j=1;j<=n&&flag;++j) flag&=i==j||minc[i]<maxc[j];
		putchar(flag+'0');
	}
	return 0;
}