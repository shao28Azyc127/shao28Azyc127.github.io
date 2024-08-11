#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int a[5],n;
int s[10][5];
bool check(int pos)
{
	int cnt=0;
	for(int i=0;i<5;i++)cnt+=s[pos][i]!=a[i];
	if(cnt>=3)return false;
	if(cnt==0)return false;
	if(cnt==1)return true;
	int x=-1,y=-1;
	for(int i=0;i<5;i++)
	{
		if(s[pos][i]==a[i])continue;
		if(x==-1)x=i;
		y=i;
	}
	if(x!=y-1)return false;
	if((a[x]-s[pos][x]+10)%10==(a[y]-s[pos][y]+10)%10)return true;
	else return false;
}
int ans=0;
void dfs(int now)
{
	if(now==5)
	{
		bool f=1;
		for(int i=1;i<=n;i++)f&=check(i);
		ans+=f;
		return;
	}
	for(int i=0;i<10;i++)a[now]=i,dfs(now+1);
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)for(int j=0;j<5;j++)s[i][j]=read();
	dfs(0);printf("%d\n",ans);
	return 0;
}