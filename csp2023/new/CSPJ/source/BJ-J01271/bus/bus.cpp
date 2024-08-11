#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n,m,k,i,c=1,all=0,u[10005],v[10005],a[10005];
	cin>>n>>m>>k;
	for(;;)
	{
		if(all%k!=0)
			all++;
		else
			break;
	}
	for(i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>a[i];
	for(;;)
	{
		for(i=1;i<=m;i++)
			if(u[i]==c)
			{
				all++;
				c=v[i];
			}
		if(c==n)
			break;
	}
	for(i=0;i<10;i++)
		if((all+i)%k==0)
		{
			cout<<all+i;
			return 0;
		}
	cout<<-1;
	return 0;
}
