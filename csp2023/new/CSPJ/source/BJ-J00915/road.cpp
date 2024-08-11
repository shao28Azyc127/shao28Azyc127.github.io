#include<bits/stdc++.h>
using namespace std;
long long sum[100005];
int a[100005];
int main()
{
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<n;i++)
	{
		int x;
		cin>>x;
		sum[i]=sum[i-1]+x;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long o=0,p=1,c=0;
	while(1)
	{
		if(p==n)
			break;
		int next=n;
		for(int i=p;i<=n;i++)
		{
			if(a[i]<a[p])
			{
				next=i;
				break;
			}
		}
		int s=sum[next-1]-sum[p-1];
		int z=(s-o-1)/d+1;
		o+=z*d-s;
		c+=z*a[p];
		//cout<<p<<" "<<s<<" "<<z<<" "<<o<<" "<<c<<endl;
		p=next;
	}
	cout<<c;
	return 0;
}
