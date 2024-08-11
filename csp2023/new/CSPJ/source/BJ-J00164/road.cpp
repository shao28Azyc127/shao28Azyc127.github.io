#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int dis[N],p[N],s[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,k,r=0,sum=0;
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		cin>>dis[i];
		s[i]=s[i-1]+dis[i];
	}
	for(int i=1;i<=n;i++)
	cin>>p[i];
	int i=1;
	while(i<n)
	{
		bool flag=0;
		for(int j=i+1;j<n;j++)
		{
			if(p[j]<p[i])
			{
				flag=1;
				int dist=s[j-1]-s[i-1];
				if(r>=dist)
				{
					r-=dist;
				}
				else
				{
					sum+=ceil(1.0*(dist-r)/k)*p[i];
					r+=ceil(1.0*(dist-r)/k)*k;
					r-=dist;
				}
				i=j;
			}
		}
		if(flag==0)
		{
			int dist=s[n-1]-s[i-1];
				if(r>=dist)
				{
					cout<<sum;
					return 0;
				}
				else
				{
					sum+=ceil(1.0*(dist-r)/k)*p[i];
					r+=ceil(1.0*(dist-r)/k)*k;
					cout<<sum;
					return 0;
				}
		}
	 } 
	 cout<<sum;
	return 0;
}
/*
5 4
10 10 10 10
9 8 9 6 5
*/