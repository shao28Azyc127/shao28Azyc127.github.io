#include<bits/stdc++.h>
using namespace std;
bool a[int(1e9+5)];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,i,cnt=0,sum=2,ans,tmp=0;
	cin>>n;
	while(tmp<n)
	{
		sum=2;
		cnt++;
		for(i=1;i<=n;i++)
		{
			if(a[i]==1) continue;
			if(sum==2)
			{
				sum=0;
				a[i]=1;
				if(i==n) ans=cnt;
				tmp++;
			}
			else sum++;
		}
	}
	cout<<cnt<<' '<<ans;
	return 0;
}
