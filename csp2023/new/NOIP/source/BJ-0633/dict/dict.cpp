#include<bits/stdc++.h>
using namespace std;
char d[50][5];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m,c=0;
	char z='z',x='z';
	cin>>n>>m;
	if(n==1)
	{
		cin>>c;
		cout<<"1";
	}
	if(n!=1&&m==1)
	{
		for(int i=0;i<n;i++)
		{
			cin>>d[i][0];
			if(d[i][0]<z)
			{
				z=d[i][0];
			}
		}
		for(int i=0;i<n;i++)
		{
			if(d[i][0]==z)
			{
				cout<<"1";
			}
			else
			{
				cout<<"0";
			}
		}
	}
	if(m==2)
	{
		for(int i=0;i<n;i++)
		{
			cin>>d[i][0]>>d[i][1];
			if(d[i][0]<z)
			{
				z=d[i][0];
			}
		}
		for(int i=0;i<n;i++)
		{
			if(d[i][0]==z&&d[i][1]<x)
			{
				x=d[i][1];
			}
		}
		for(int i=0;i<n;i++)
		{
			if((d[i][0]<z)||(d[i][1]<=z)||(d[i][0]==z&&d[i][1]<=x)||(d[i][1]==z&&d[i][0]<=x))
			{
				cout<<"1";
			}
			else
			{
				cout<<"0";
			}
		}
	}
	return 0;
}
