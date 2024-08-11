#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s[10][10],ans,a[10],c[20][20];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=5;j++) scanf("%lld",&s[i][j]);
	}
	for(ll i=0;i<10;i++)
	{
		for(ll j=0;j<10;j++)
		{
			if(j<i) c[i][j]=9-i+j+1;
			else c[i][j]=j-i;
		}
	}
	for(a[1]=0;a[1]<10;a[1]++)
	{
		for(a[2]=0;a[2]<10;a[2]++)
		{
			for(a[3]=0;a[3]<10;a[3]++)
			{
				for(a[4]=0;a[4]<10;a[4]++)
				{
					for(a[5]=0;a[5]<10;a[5]++)
					{
						bool f=0;
						for(ll i=1;i<=n;i++)
						{
							ll cnt=0,x=0;
							for(ll j=1;j<=5;j++)
							{
								if(a[j]!=s[i][j])
								{
									cnt++;
									if(cnt>2||(cnt==2&&x!=j-1)||(cnt==2&&x==j-1
									&&c[s[i][x]][a[x]]!=c[s[i][j]][a[j]]))
									{
										f=1;
										break;
									}
									x=j;
								}
							}
							if(cnt==0)
							{
								f=1;
								break;
							}
						}
						if(!f) ans++;
					}
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}