#include <bits/stdc++.h>
using namespace std;
struct node{
	int u,time;
};
vector<node> a[10005];
int t[10005],n,m,k;
bool v[10005];
int dfs(int x){
	if (x==1){
		return m*k;
	}
	v[x]=1;
	if (t[x]) return t[x];
	int ans=1e9,len=a[x].size(),y;
	for (int i=0;i<len;++i){
		if (v[a[x][i].u]&&t[a[x][i].u]==0) continue;
		y=dfs(a[x][i].u);
		if (y==-1||y<a[x][i].time) continue;
		ans=min(ans,y+1);
	}
	if (ans==1e9) ans=-1;
	t[x]=ans;
	//cout<<x<<" "<<ans<<"\n";
	return ans;
}
int f()
{
	int ans=1e9,x,ed=1e4+1;
	for (m=0;m<=ed;++m){
		x=dfs(n);
		if (x!=-1) ans=min(x,ans);
		memset(v,0,sizeof(v));
		memset(t,0,sizeof(t));
	}
	return ans==1e9?-1:ceil(ans/double(k))*k;
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,Time;
	for (int i=1;i<=m;++i){
		cin>>u>>v>>Time;
		a[v].push_back(node{u,Time});
	}
	cout<<f();
	//cout<<dfs(n);
    return 0;
}
