#include<bits/stdc++.h>
using namespace std;
int n,m,k,r,c,t,ans=1e9,mxt=-1e9;
struct nd{
	int zd,sj;
};
vector<nd>vt[10005];
void dfs(int dq,int t){
	if(dq==n){
		ans=min(ans,t);
		return;
	}
	for(auto it:vt[dq]){
		if(it.zd==n){
			if(t+1>=it.sj&&(t+1)%k==0){
				dfs(it.zd,t+1);
			}
			continue;
		}
		if(t+1>=it.sj){
			dfs(it.zd,t+1);
		}
	}
	return;
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> r >> c >> t;
		mxt=max(t,mxt);
		vt[r].push_back(nd{c,t});
	}
	for(int i=0;i<=mxt;i+=k){
		dfs(1,i);
	}
	if(ans==1e9){
		cout << -1;
		return 0;
	}
	cout << ans;
	return 0;
}
/*
 * 5 5 3 1 2 0 2 5 1 1 3 0 3 4 3 4 5 1
 * */
