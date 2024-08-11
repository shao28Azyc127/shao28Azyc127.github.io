#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[3001],ss[3001];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		ss[i]=s[i];
	}
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	if(m==1)
	{
		int cnt=0,p;
		char c='z';
		for(int i=1;i<=n;i++)
		{
			if(s[i][0]<c)
			{
				c=s[i][0];
				p=i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(c==s[i][0])
				cnt++;
		}
		if(cnt>1)
		{
			for(int i=1;i<=n;i++)
				cout<<0;
			return 0;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(i==p)
					cout<<1;
				else
					cout<<0;
			}
		}
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			bool flag=true;
			if(ss[i][0]>ss[i][1])
					swap(ss[i][0],ss[i][1]);
			for(int j=1;j<=n;j++)
			{
				if(j==i)
					continue;
				if(ss[j][0]<ss[j][1])
					swap(ss[j][0],ss[j][1]);
			}
			for(int j=1;j<=n;j++)
			{
				if(j==i)
					continue;
				if(ss[i][0]>ss[j][0])
				{
					flag=false;
					break;
				}
				if(ss[i][0]==ss[j][0] && ss[i][1]>=ss[j][1])
				{
					flag=false;
					break;
				}
			}
			if(flag==true)
				cout<<1;
			else
				cout<<0;
			for(int j=1;j<=n;j++)
				ss[j]=s[j];
		}
	}
	return 0;
}
