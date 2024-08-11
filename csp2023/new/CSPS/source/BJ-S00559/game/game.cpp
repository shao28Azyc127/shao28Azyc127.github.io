#include<bits/stdc++.h>
#include<cstdio>
#include<string>
using namespace std;
const int N=2e6+5;
string s;
long long n,ans,r[N],l[N];
bool f[8000][8000];
void dfs(int x,int y)
{
	while(x>=0&&y<n)
	{
		if(s[x]==s[y])	ans++;
		else return;
		r[x]++,l[y]++;
		x--;y++;
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	cin>>s;
	for(int i=0;i<n-1;i++)	dfs(i,i+1);
	for(int i=1;i<n-1;i++)
	{
		ans+=l[i]*r[i+1];
	}
	cout<<ans;
	return 0;
}
