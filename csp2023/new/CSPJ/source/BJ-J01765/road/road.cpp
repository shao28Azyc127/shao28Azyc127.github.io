#include <iostream>
#include <cstdio>
#define N 100010
using namespace std;
int d[N],p[N];
int hf(int d,int w)
{
	int f=0;
	f=d/w;
	if(d%w>0)
	{
		f++;
	}
	return f;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,w,tp=0,j=0,fd=0,i=0;
	cin>>n>>w;
	for(int i=0;i<n-1;i++)
	{
		cin>>d[i];
	}
	for(int i=0;i<n-1;i++)
	{
		cin>>p[i];
	}
	for(int i=0;i<n-1;i)
	{
		int td=0;
		for(j=0;j<n-1;j++)
		{
			if(p[j]<p[i])
			{
				for(int l=i;l<j;l++)
				{
					td+=d[l]; 
				}
				tp+=hf(td-fd,w)*p[i];
				fd+=hf(td-fd,w)*w-td;
				break;
			}	
		}
		i=j;
	}
	int td=0;
	for(int i=j-1;i<n-1;i++)
	{
		td+=d[i];
	}
	tp+=hf(td-fd,w)*p[j-1];
	cout<<tp;
	return 0;
}