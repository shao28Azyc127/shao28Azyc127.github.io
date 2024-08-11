#include<bits/stdc++.h>

using namespace std;

int n;
int a[100000000];
int ans;

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
	}
	bool flag=true;
	int i;
	for(i=1;flag;i++)
	{
		int cnt=0;
		flag=false;
		for(int j=1;j<=n;j++)
		{
			if(a[j]==0)
			{
				continue;
			}
			else
			{
				flag=true;
			}
			
			if(cnt%3==0)
			{
				if(a[j]==n)
				{
					ans=i;
				}
				a[j]=0;
				cnt=0;
			}
			cnt++;
		}
	}
	cout<<i-2<<' '<<ans;
	
	return 0;
}