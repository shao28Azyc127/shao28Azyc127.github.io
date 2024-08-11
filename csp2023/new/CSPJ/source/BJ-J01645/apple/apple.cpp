#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
int cnt=0,m,f=0;
int read()
{
	int x=0,f=1;
	char ch;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
void ca(int l)
{
	if(l==0)
		return;
	if(l%3==1&&f==0)
	{
		m=cnt+1;
		f=1;
	}
	cnt++;
	if(l%3==0)
		ca(l-l/3);
	else
		ca(l-l/3-1);
}
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	n=read();
	ca(n);
	cout<<cnt<<' '<<m;
	return 0;
}
