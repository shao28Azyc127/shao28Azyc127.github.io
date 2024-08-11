#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
int n;
char s[2000005];
int cnt[27];
int ans;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&s[i]);
		cnt[s[i]-'a'+1]++;
	}
	for(int i=1;i<=26;i++)
	{
		ans+=cnt[i]/2;
	}
	cout<<ans;
    return 0;
}
