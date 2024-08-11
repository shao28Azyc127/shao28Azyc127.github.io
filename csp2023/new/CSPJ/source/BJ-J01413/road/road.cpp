#include<iostream>
#include<cstdio>

using namespace std;

struct road
{
	int v;
	int a;
};
int cost(int x,int y)
{
	if(x%y==0)
		return x/y;
	else
		return x/y+1;
}
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,d;
	road r[9999999];
	cin>>n>>d;
	for(int i=0;i<n-1;i++)
	{
		cin>>r[i].v;
	}
	for(int i=0;i<n;i++)
	{
		cin>>r[i].a;
	}
	int box=0,km=r[0].v,int j=0,p=0,m=0;
	while(j<n)
	{
		if(r[p].a<r[j+1].a)
		{
			km+=r[j+1].a;
		}
		else
		{
			m+=(cost(km,d)-box)*r[p].a;
			p=j;
		}
		j++;
	}
	cout<<m<<endl;
	return 0;
}
	
