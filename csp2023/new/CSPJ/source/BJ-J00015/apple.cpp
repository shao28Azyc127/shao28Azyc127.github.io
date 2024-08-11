#include<bits/stdc++.h>
using namespace std;
long long a[100000001];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long n,m,cnt,ans=0;
	cin>>n;
	m=n;
	while(m>0)
	{
		ans++;
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=0)
				continue;
			cnt++;
			if(cnt%3==1)
			{
				a[i]=ans;
				m--;
			}
		}
	}
	cout<<ans<<" "<<a[n]<<endl;
	return 0;
}