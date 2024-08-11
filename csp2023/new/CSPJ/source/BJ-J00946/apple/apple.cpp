#include <bits/stdc++.h>
using namespace std;
bool f[1000002]={0};
int ans2[1000002];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int ans1=0;
	bool flag=1;
	int cnt=0;
	while(flag)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==0)
				sum++;
			if(sum==1||(sum-1)%3==0)
			{
				f[i]=1;
			}
		}
		ans1++;
		if(f[n]==1)
			ans2[++cnt]=ans1;
		bool f1=0;
		for(int j=1;j<=n;j++)
		{
			if(f[j]==0)
			{
				f1=1;
				break;
			}
		}
		if(f1==1)
			flag=1;
		if(f1==0)
			flag=0;
	}
	cout<<ans1<<" "<<ans2[1]<<endl;
	return 0;
}