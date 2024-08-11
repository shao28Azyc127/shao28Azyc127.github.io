#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<long long>mp[2][20004];
bool flag[20004][102];
long long bfs(){
	queue<pair<int,long long>>q;
	q.push({1,0});
	while(!q.empty()){
		int w=q.front().first;
		long long d=q.front().second;
		q.pop();
		if(w==n)return d;
		for(int i=0;i<mp[0][w].size();i++){
			if(!flag[mp[0][w][i]][d+1]){
				flag[mp[0][w][i]][d+1]=true;
				q.push({mp[0][w][i],d+1});
			}
		}
	}
	return -1;
}
long long ans=2e18;
void dfs(int x,long long cnt){
	if(x==n)if(cnt%k==0)ans=min(ans,cnt);
	for(int i=0;i<mp[0][x].size();i++){
		if(!flag[mp[0][x][i]][cnt+1]){
			flag[mp[0][x][i]][cnt+1]=true;
			dfs(mp[0][x][i],cnt+1);
		}
	}
}
void dfs_all(int x,long long cnt){
	if(x==n)if(cnt%k==0)ans=min(ans,cnt);
	for(int i=0;i<mp[0][x].size();i++){
		if(cnt+1>mp[1][x][i]&&!flag[mp[0][x][i]][cnt+1]){
			flag[mp[0][x][i]][cnt+1]=true;
			dfs(mp[0][x][i],cnt+1);
		}
	}
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	bool flag=true;
	long long ooo=0;
	for(int i=1;i<=m;i++){
		long long u,v,a;cin>>u>>v>>a;
		if(a!=0)flag=false;
		mp[0][u].push_back(v);
		mp[1][u].push_back(a);
		ooo=max(ooo,a);
	}
	if(k==1&&flag)cout<<bfs();
	else if(flag){
		dfs(1,0);
		if(ans==2e18)cout<<"-1";
		else cout<<ans;
	}else if(n<=10){
		for(int i=0;i<=ooo;i++)dfs_all(1,i);
		if(ans==2e18)cout<<"-1";
		else cout<<ans;
	}else cout<<"-1";
	return 0;
}
