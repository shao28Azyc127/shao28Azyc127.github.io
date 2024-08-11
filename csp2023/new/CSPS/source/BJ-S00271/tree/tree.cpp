#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 22;
int n,idx,ans = 1e9;
int h[N],ne[2*N],e[2*N];
int a[N],b[N],c[N],d[N];
bool vis[N];
void add(int x,int y)
{
	e[idx] = y,ne[idx] = h[x],h[x] = idx ++;
}
int get(int x,int y)
{
	if(c[x] == 0) 
	{
		if(a[x]%b[x] == 0) return y+(a[x]/b[x])-1;
		else return y+(a[x]/b[x]);
	}
	else
	{
		int now = 0;
		while(now < a[x])
		{
			now = now + max(b[x] + c[x]*y,1);
			++y;
		}
		return y-1;
	}
}
void dfs(int x,int sz,int now[])
{
	if(x == n+1)
	{
		int cnt = 0;
		for(int i = 1;i <= n;++i)
			cnt = max(cnt,get(d[i],i));
		//for(int i = 1;i <= n;++i) cout << d[i] << ' ';
		//cout << endl;
		ans = min(ans,cnt);
		return ;
	}
	for(int i = 1;i <= sz;++i)
	{
		int cnt[22];
		int tot = 0;
		vis[now[i]] = true;
		d[x] = now[i];
		for(int j = 1;j < i;++j) cnt[++tot] = now[j];
		for(int j = i+1;j <= sz;++j) cnt[++tot] = now[j];
		for(int j = h[now[i]];j != -1;j = ne[j])
		{
			int y = e[j];
			if(!vis[y])
			{
				cnt[++tot] = y;
			//	cout << y << endl;
			}
		}
		dfs(x+1,tot,cnt);
		//return ;
		vis[now[i]] = false;
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(h,-1,sizeof(h));
	cin >> n;
	for(int i = 1;i <= n;++i)
		cin >> a[i] >> b[i] >> c[i];
	for(int i = 1;i < n;++i)
	{
		int x,y;
		cin >> x >> y;
		add(y,x);
		add(x,y);
	}
	int ad[20];
	ad[1] = 1;
	dfs(1,1,ad);
	cout << ans << endl;
	return 0;
}
