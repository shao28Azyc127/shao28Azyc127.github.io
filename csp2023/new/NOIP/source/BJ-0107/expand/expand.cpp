#include<bits/stdc++.h>
#define ffor(i,l,r) for(int i=(l),i##_end=(r);i<=i##_end;i++)
#define rfor(i,l,r) for(int i=(l),i##_end=(r);i>=i##_end;i--)
#define file(name,dat) freopen(name".in","r",stdin),freopen(name dat,"w",stdout)
using namespace std;
using ll = long long;
int c,n,m,q;
int dp[1010][1010];
int _x[1010],_y[1010];
int x[1010],y[1010];
int tmp[1010];
bool solve(){
	memset(dp,0,sizeof(dp));
	//ffor(i,1,n) dp[i][0] = 1;
	//dp[0][0] = 1;
	dp[0][0] = 1;
	ffor(i,1,n){
		ffor(j,1,m){
			if(x[i]>y[j]){
				dp[i][j]|=dp[i-1][j];
				dp[i][j]|=dp[i-1][j-1];
				dp[i][j]|=dp[i][j-1];
			} 
			// for(int k=j;x[i]>y[k];k--){
			// 	dp[i][j]|=dp[i-1][k-1];
			// }
			
		}
	}
	return dp[n][m];
}
bool solvee(){
	if(solve()) return 1;
	memcpy(tmp,x,sizeof(x));
	memcpy(x,y,sizeof(y));
	memcpy(y,tmp,sizeof(x));
	swap(n,m);
	bool d = solve();
	swap(n,m);
	return d;
}
void copye(){
	memcpy(x,_x,sizeof(x));
	memcpy(y,_y,sizeof(y));
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	//_x[0] = -1e9;
	//_y[0] = 1e9;
	ffor(i,1,n) cin>>_x[i];
	ffor(i,1,m) cin>>_y[i];
	copye();
	cout<<solvee();
	ffor(_,1,q){
		copye();
		int kx,ky;cin>>kx>>ky;
		ffor(i,1,kx){
			int px,vx;cin>>px>>vx;
			x[px] = vx;
		} 
		ffor(i,1,ky){
			int py,vy;cin>>py>>vy;
			y[py] = vy;
		}
		// if(0&&_==3){
		// 	cout<<"\n:\n";
		// 	ffor(i,1,n) cout<<x[i]<<" ";
		// 	cout<<"\n";
		// 	ffor(i,1,m) cout<<y[i]<<" ";
		// 	cout<<"\n";
		// }
		cout<<solvee();
	}
	return 0;
}