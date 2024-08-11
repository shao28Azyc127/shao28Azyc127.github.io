#include<bits/stdc++.h>
using namespace std;
vector<int> v[10005];
int a[10005][10005],n,k,Min=0x3f3f3f3f;
bool vis[10005];
void dfs(int u,int t){
	if(u==n&&t%k==0){
		Min=min(Min,t);
		return;
	}
	for(auto j:v[u]){
		if(vis[j]==false){
			vis[j]=true;
			dfs(j,t+1);
			vis[j]=false;
		}
	}
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int m,a1,b;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a1>>b;
		v[a1].push_back(b);
		cin>>a[a1][b];
	}
	dfs(1,0);
	if(Min==0x3f3f3f3f){
		cout<<"-1";
		return 0;
	}
	cout<<Min;
	return 0;
}