#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans,nx[2000005],cnt;
char s[2000005];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%s",&n,s+1);
	for(ll i=1;i<n;i++)
	{
		for(ll j=i+1;j<=n;j++)
		{
			for(ll k=i-1;k<=j;k++) nx[k]=k+1;
			nx[j]=0;
			cnt=j-i+1;
			while(1)
			{
				bool f=0;
				for(ll k=i-1;nx[nx[k]];k=nx[k])
				{
					if(s[nx[k]]==s[nx[nx[k]]]) cnt-=2,f=1,nx[k]=nx[nx[nx[k]]];
				}
				if(!f) break;
			}
			if(cnt==0) ans++;
			nx[0]=0;
		}
	}
	printf("%lld",ans);
	return 0;
}