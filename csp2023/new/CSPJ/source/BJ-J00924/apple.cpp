#include<bits/stdc++.h>
using namespace std;
int visit[1000001];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,i=1,j=0,cnt=0,ans;
	cin>>n;
	while(1)
	{
		cnt++;
		while(i<=n)
		{
			if(visit[i]!=1)
			{
				j++;
				if(i==n)
				{
					ans=cnt;
				}
				if(j%3==1)
				{
					visit[i]=1;
				}
				i++;
			}
			else
			{
				i++;
			}
		}
		if(j==0)
		{
			cout<<cnt-1<<' '<<ans;
			return 0;
		}
		i=1;
		j=0;
	}
	return 0;
}