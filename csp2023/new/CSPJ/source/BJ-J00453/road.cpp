#include<bits/stdc++.h>
using namespace std;
long long a[100001];
long long u[100001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	cin>>n;
	int d;
	cin>>d;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&u[i]);
	}
	long long pre=0;
	long long cnt=0;
	int p=1;
	for(int i=1;i<n;i++)
	{
	    //cout<<pre<<" "<<cnt<<" "<<i<<endl;
		if(u[i]<u[p])
		{
			p=i;
		}
		if(pre<a[i])
		{
			cnt+=ceil((a[i]-pre)*1.0/d)*u[p];
			pre+=ceil((a[i]-pre)*1.0/d)*d;

		}
		pre=pre-a[i];
	}
	cout<<cnt;
	return 0;
}