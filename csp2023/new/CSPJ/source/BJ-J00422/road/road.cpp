#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,to=1,guess=0,spend=0;
	cin>>n>>d;
	int a[n+1],b[n+5];
	for(int i=1;i<=n-1;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	spend=a[1]/d*b[1];
	if(a[1]%d!=0)spend+=b[1];
	guess=spend*d/b[1]-a[1];
	for(int i=2;i<n;i++)
	{
		a[i]-=guess;
		if(a[i]<=0)
		{
			guess-=a[i];
			a[i]=0;
			continue;
		}
		else guess=0;
		if(b[i]>=b[to])
		{
			int o=a[i]/d;
			spend+=a[i]/d*b[to];
			if(a[i]%d!=0)
			{
				spend+=b[to];
				o+=1;
			}
			guess=o*d-a[i];
		}
		else
		{
			to=i;
			int o=a[to]/d;
			spend+=a[to]/d*b[to];
			if(a[to]%d!=0)
			{
				spend+=b[to];
				o+=1;
			}
			guess=o*d-a[to];
		}
	}
	cout<<spend;
	return 0;
}
