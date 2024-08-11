#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c,vis[10010],ans=20010;
struct l{
	int b,c;
};
vector<l>v[10010];
int dfs(int times,int where){
	if(where==n)return times;
	if(times>=20010)return -1;
	int ansd=0x3f3f3f3f,s=v[where].size();
	for(int i=0;i<s;i++){
		if(times>v[where][i].c){
			int x=dfs(times+1,v[where][i].b);
			if(x!=-1&&x%k==0) ansd=min(ansd,x);
		}
	}
	if(ansd==0x3f3f3f3f)
		return -1;
	return ansd;
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		v[a].push_back((l){b,c});
	}
	for(int i=0;i<=ans;i+=k){
		int x=dfs(i,1);
		if(x!=-1){
			ans=min(ans,x);
		}
	}
	cout<<ans;
	return 0;
}
