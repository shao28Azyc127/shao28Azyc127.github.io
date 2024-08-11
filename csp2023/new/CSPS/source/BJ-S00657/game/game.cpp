#include<bits/stdc++.h>
using namespace std;
long long f[2000005];
int c[2000005];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;
	cin>>n;
	string s;
	cin>>s;
	s=' '+s;
	if(s.size()>=3)
		if(s[1]==s[2])
		{
			f[2]=1;
			c[2]=2;
		}
	for(int i=3;i<=n;i++)
	{
		for(int j=i-1;j>=1;j-=2)
		{
			if(s[j]==s[i])
			{
				if(c[i-1]-c[j]==i-j-1)
				{
					f[i]=f[j-1]+1;
					c[i]=c[j-1]+i-j+1;
				}
			}
		}
	}
	long long ans=0;
	for(int i=2;i<=n;i++)
	{
		cout<<f[i]<<" "<<c[i]<<endl;
		ans+=f[i];
	}
	cout<<ans;
	return 0;
}
