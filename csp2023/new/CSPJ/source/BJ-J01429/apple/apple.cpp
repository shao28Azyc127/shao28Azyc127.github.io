#include<bits/stdc++.h>
using namespace std;
int a[500000005];
long long s=0;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,sumv=0;
	cin>>n;
	int sum=n,ans=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=1;
	}
	while(sum>0)
	{
		int x=0;
		ans++;
		for(int i=1;i<=n;i+=3)
		{
			a[i]=0;
			sum--;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				x++;
				a[x]=1;
			}
			if(a[n]==0)
			{
				sumv++;
				if(sumv==1)
				{
					s=ans;
				}
			}
		}
		n=x;
	}
	cout<<ans<<" ";
	cout<<s;
	return 0;
}