#include<bits/stdc++.h>
using namespace std;
const int MAXN=10005;
vector<int>Graph[MAXN];
int n,vis[MAXN],ok[MAXN];
long long ans=LLONG_MAX,a[MAXN],b[MAXN],c[MAXN];
void dfs(int id,int tian){
	vis[id]=tian;
	for(unsigned int i=0;i<Graph[id].size();i++)ok[Graph[id][i]]++;
	int flag=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]&&ok[i])dfs(i,tian+1),flag=1;
	}
	if(!flag){
		long long ans2=INT_MIN;
		for(int i=1;i<=n;i++){
			long long tree=0,day=0;
			while(tree<a[i]){
				day++;
				tree+=max(b[i]+c[i]*(day+vis[i]-1),1LL);
			}
			ans2=max(ans2,day+vis[i]-1);
		}
		ans=min(ans,ans2);
	}
	for(unsigned int i=0;i<Graph[id].size();i++)ok[Graph[id][i]]--;
	vis[id]=0;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		Graph[min(u,v)].push_back({max(u,v)});
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}
//kkkbaoyou,baosoubiegua
