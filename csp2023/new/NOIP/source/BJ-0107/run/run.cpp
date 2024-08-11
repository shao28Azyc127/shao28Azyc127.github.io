#include<bits/stdc++.h>
#define ffor(i,l,r) for(ll i=(l),i##_end=(r);i<=i##_end;i++)
#define rfor(i,l,r) for(ll i=(l),i##_end=(r);i>=i##_end;i--)
#define file(name,dat) freopen(name".in","r",stdin),freopen(name dat,"w",stdout)
using namespace std;
using ll = long long;
ll c,t,n,m,k,d;
ll x[100010],y[100010],v[100010];
ll dp[1010][1010];
vector<ll> vc[100010];
void toMax(ll &x,ll y){
	if(x<y) x = y;
}
void Do(){
	cin>>n>>m>>k>>d;
	ffor(i,1,n){
		vc[i].clear();
	}
	ffor(i,1,m) {
		cin>>x[i]>>y[i]>>v[i];
		vc[x[i]].push_back(i);
	}
	//if(t!=) return;
	memset(dp,-0x7f,sizeof(dp));
	dp[0][0] = 0;
	ffor(i,1,n){
		dp[i][0] = dp[i-1][0];
		ffor(j,1,k){
			dp[i][0] = max(dp[i][0],dp[i-1][k]);
		}
		ffor(j,1,k){
			dp[i][j] = dp[i-1][j-1]-d;
			for(int c:vc[i]){
				if(j>=y[c]) dp[i][j]+=v[c];
			}
		}
	}
	ll ans = 0;
	ffor(i,0,k) ans = max(ans,dp[n][i]);
	cout<<ans<<"\n";
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--) Do();
	return 0;
}