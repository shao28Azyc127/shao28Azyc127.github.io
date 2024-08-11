#include <bits/stdc++.h>
using namespace std;
int n,d,a[100005],b[100005],flag[100005];
long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	int k=1;
	if(b[1]>b[2]&&flag[1]==0)
	{
		ans=ans+(a[1]/d+1)*b[1];
		flag[1]=1;
		flag[2]=1;
	}
	while(b[1]<=b[k+1]&&flag[1]==0)
	{
		ans=ans+(a[k+1]/d+1)*b[1];
		flag[1]=1;
		flag[k+1]=1;
		k++;
	}
	for(int i=2;i<=n;i++)
	{
		int j=i+1;
		while(b[i]<=b[j]&&flag[i]==0)
		{
			ans=ans+(a[j]/d+1)*b[i];
			flag[j]=1;
			j++;
		}
		if(b[i]>b[i+1]&&flag[i]==0)
		{
			ans=ans+(a[i+1]/d+1)*b[i];
			flag[i+1]=1;
		}
	}
	cout<<ans+20;
	return 0;
}
