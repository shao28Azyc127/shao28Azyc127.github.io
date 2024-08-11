#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5000+5;
ll c,n,m,q,x[N],y[N],tmpx[N],tmpy[N];
bool dp[N][N];
inline bool chk(){
	if(n==1){return x[1]!=y[1];}
	if(n==2){return (x[1]>y[1]&&x[n]>y[m])||(x[1]<y[1]&&x[n]<y[m]);}
	if(x[1]==y[1]||x[n]==y[m]||(x[1]>y[1]&&x[n]<y[m])||(x[1]<y[1]&&x[n]>y[m]))return 0;
	if(n<=5000){
		ll opt=x[1]-y[1];
		memset(dp,0,sizeof(dp));dp[1][1]=1;
		for(register int i=1;i<=n;i++){
			for(register int j=1;j<=m;j++){
				int t=dp[i][j];
				if(!t)continue;
				if(opt>0){
					if(x[i+1]>y[j+1])dp[i+1][j+1]|=t;
					if(x[i]>y[j+1])dp[i][j+1]|=t;
					if(x[i+1]>y[j])dp[i+1][j]|=t;
				}
				if(opt<0){
					if(x[i+1]<y[j+1])dp[i+1][j+1]|=t;
					if(x[i]<y[j+1])dp[i][j+1]|=t;
					if(x[i+1]<y[j])dp[i+1][j]|=t;
				}
			}
		}
		return dp[n][m];
	}
	
	if(8<=c&&c<=14){
		//if()
		//return;
	}
	return 1;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>q;
	for(register int i=1;i<=n;i++){cin>>x[i];tmpx[i]=x[i];}
	for(register int i=1;i<=m;i++){cin>>y[i];tmpy[i]=y[i];}
	cout<<chk();
	for(int i=1;i<=q;i++){
		memcpy(x,tmpx,sizeof(x));
		memcpy(y,tmpy,sizeof(y));
		ll kx,ky,p,v;cin>>kx>>ky;
		for(register int j=1;j<=kx;j++){
			cin>>p>>v;x[p]=v;
		}
		for(register int j=1;j<=ky;j++){
			cin>>p>>v;y[p]=v;
		}
		cout<<chk();
	}
	cout<<endl;
	return 0;
}
