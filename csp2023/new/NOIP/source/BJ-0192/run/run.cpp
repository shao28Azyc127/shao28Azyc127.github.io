#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,k,d,ans=0,a[105],s[105],x[105],y[105],v[106];
inline void solve(){
	memset(s,0,sizeof(s));
	long long res=0;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=m;i++){
		if(s[x[i]]-s[x[i]-y[i]+1]==x[i]-y[i]+1) res-=d*y[i],res+=v[i];
	}
	ans=max(ans,res);
}
inline void dfs(int d,int c){
	if(d==n+1){
		solve();
		return ;
	}
	if(c==k) a[d]=0,dfs(d+1,0);
	else{
		a[d]=1,dfs(d+1,c+1);
		a[d]=0,dfs(d+1,0);
	}
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	if(c==17 || c==18){
		while(t--){
			ans=0;
			cin>>n>>m>>k>>d;
			for(int i=1;i<=m;i++){
				long long xx,yy,vv;
				cin>>xx>>yy>>vv;
				if(yy<=k && yy*d<vv) ans-=yy*d,ans+=vv;
			}
			cout<<ans<<'\n';
		}
	}else if(c==1 || c==2){
		while(t--){
			ans=0;
			cin>>n>>m>>k>>d;
			for(int i=1;i<=m;i++) cin>>x[i]>>y[i]>>v[i];
			dfs(1,0);
			cout<<ans<<'\n';
		}
	}
	return 0;
}