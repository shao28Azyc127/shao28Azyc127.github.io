#include<bits/stdc++.h>
using namespace std;
int n,m,c,t,k,d,ans;
int x[1005],y[1005],v[1005];
bool run[2005];
void dfs(int depth){
	if(depth==n){
		int res=0;
		for(int i=1;i<=n-k;i++){
			bool flag=1;
			for(int j=0;j<=k;j++){
				if(!run[i+j]){flag=0;break;}
			}
			if(flag){
				return;
			}
		}
		for(int i=1;i<=n;i++)if(run[i])res-=d;
		for(int i=1;i<=m;i++){
			bool flag=1;
			for(int j=x[i]-y[i]+1;j<=x[i];j++){
				if(!run[j]){flag=0;break;}
			}
			if(flag)res+=v[i];
		}
		ans=max(ans,res);
	}
	if(depth<n){
		dfs(depth+1);
		run[depth+1]=1;
		dfs(depth+1);
		run[depth+1]=0;
	}
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> c >> t;
	while(t--){
		ans=0;
		cin >> n >> m >> k >> d;
		for(int i=1;i<=m;i++)cin >> x[i] >> y[i] >> v[i];
		if(c==1){
			dfs(0);
			cout << ans << endl;
		}
	}
	return 0;
}