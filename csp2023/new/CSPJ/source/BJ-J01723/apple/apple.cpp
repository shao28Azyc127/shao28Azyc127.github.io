#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long n,ans=0,ans2=0;
	cin>>n;
	long long a[n+1];
	for(long long i=1;i<=n;i++)
	{
		a[i]=i;
	}
	long long cnt=0;
	bool f=false;
	for(long long j=1;j<=n;j+=cnt)
	{
		ans++;
		cnt=0;
		for(long long i=j;i<=n;i+=3)
		{
			cnt++;
			a[i]=0;
			if(i==n && !f)
			{
				ans2=ans;
				f=true;
			}
		}
		sort(a+1,a+n+1);
	}
	cout<<ans<<" "<<ans2;
}
