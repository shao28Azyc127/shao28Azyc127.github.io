#include<iostream>
using namespace std;
int n,f[2000010],g[2000010],h[2000010][26];
char s[2000010];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>s+1;
	long long ans=0;
	for(int i=n;i;i--)
	{
		if(g[i]=h[i+1][s[i]-'a'])
		{
			ans+=(f[i]=f[g[i]+1]+1);
			for(int j=0;j<26;j++)
			{
				h[i][j]=h[g[i]+1][j];
			}
		}
		h[i][s[i]-'a']=i;
	}
	cout<<ans<<endl;
	return 0;
}