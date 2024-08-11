//Toilet Scuffle
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
ll d;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _,t;cin>>_>>t;while(t--){
		cin>>n>>m>>k>>d;
		if(1ll*n*k<=3e6){
			vector<vector<ll>>dp(n+1,vector<ll>(k+1,0));
			vector<vector<ll>>add(n+1,vector<ll>(k+1,0));
			while(m--){
				int x,y;ll v;
				cin>>x>>y>>v;
				if(y<=k)add[x][y]+=v;
			}
			ll s=0;
			for(int i=1;i<=n;i++){
				dp[i][0]=s;
				for(int j=1;j<=k;j++){
					add[i][j]+=add[i][j-1];
					dp[i][j]=dp[i-1][j-1]-d+add[i][j];
					s=max(s,dp[i][j]);
				}
			}
			cout<<s<<"\n";
		}else{
			ll s=0;
			while(m--){
				int x,y;ll v;
				cin>>x>>y>>v;
				if(y<=k&&v>d*y)s+=v-d*y;
			}
			cout<<s<<"\n";
		}
	}
	return 0;
}




























/*
i am BJ-0084.
luogu: ACaCaca_ / 320423
i want to have 1= in noip.
但是我感觉我发烧了，火大！！！！
后面忘了。
//freopen
froepen
Genshin Impact, launch!!!
// Toilet Scuffle
厕所战神保佑我 noip 1=
stO 10o Orz
stO zch Orz
stO lqy Orz
stO zyh Orz
stO sjl Orz
stO lyc Orz
dfkjfdkjdfkjdfkjdfkjdfkjdfkjsasdfkjhasdflkjhouiyvcxbmnwhjkfdsoijwekdsapokxzmnqeygx
cold. cold. cold. cold. cold. cold. cold. cold. cold.

i saw: farfar, FutureSnow, sdhj7133, WangBX
*/