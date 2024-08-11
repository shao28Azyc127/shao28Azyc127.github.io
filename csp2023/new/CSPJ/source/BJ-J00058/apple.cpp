#include <bits/stdc++.h>
using namespace std;
bool v[100000000];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int ans1=0,ans2=0;
	while(1)
	{
		ans1++;
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(v[i]==0)
			{
				sum++;
				if(sum>3)
				{
					sum=1;
				}
			}
			if(v[i]==0 && sum==1)
			{
				v[i]=1;
				if(i==n)
				{
					ans2=ans1;
				}
			}
		}
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			if(v[i]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			break;
		}
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}