#include <bits/stdc++.h>
using namespace std;
string a;
int b[505][505];
int p=9999;
int c[30];
void op(int n)
{
	int i,mi=9999,fl,j,flag=0;
		for(i=1;i<=n;i++)
		{
			if(b[i][0]<mi)
				{
					mi=b[i][0];
					fl=i;
				}
		}
		c[fl]=1;
		for(i=1;i<=n;i++)
			if(b[i][0]==b[fl][0])
				c[i]=1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(b[i][1]>=b[j][0])
					flag=1;
				}
			if(flag==0)
				c[i]=1;
			flag=0;
		}
		for(i=1;i<=n;i++)
		cout<<c[i];
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int m,n,i,j,falg,k=99;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		for(j=0;j<m;j++)
			b[i][j]=a[j]-'a';	
	}
	if(n==1)
			cout<<1;
	if(m==1&&n!=1)
		{
			for(i=1;i<=n;i++)
			{
				if(b[i][0]<=k)
				{
					k=b[i][0];
					falg=i;
				}
			}
			c[falg]=1;
			for(i=1;i<=n;i++)
				if(b[i][0]==k)
					c[i]=1;
			for(i=1;i<=n;i++)
			cout<<c[i];
	}
	if(m==2)
		op(n);
	return 0;
}
