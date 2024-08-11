#include<bits/stdc++.h>
using namespace std;
const int maxn=1e9+5;
int n,sum,cnt,ans1,ans2;
bool a[maxn];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	while(sum<n)
	{
		ans1++;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=1)
			{
				if(cnt%3==0)
				{
					if(i==n) ans2=ans1;
					a[i]=1;
					sum++;
				}
				cnt++;
			}
		}
		cnt=0;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}