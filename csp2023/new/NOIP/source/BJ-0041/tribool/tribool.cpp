//Ayaka bless me
#include <bits/stdc++.h>
#define rep(i,a,b,c)	for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c)	for(int i=(a);i>=(b);i-=(c))
#define i64 long long
#define pb push_back
using namespace std;

const int mod=1e9+7;
const int maxn=5000;

int fpow(int a,int b){
	if(b==1)	return a;if(b==0)	return 1;
	int ans=fpow(a,b/2);ans*=ans;ans%=mod;
	if(b%2)	ans*=a;return ans%mod;
}	

struct ops{
	char ha;int i,j;
}oo[1000];
int g[20];
int f[20];

int main(){//ios::sync_with_stdio(0);cin.tie(0);
freopen("tribool.in","r",stdin);
freopen("tribool.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,m,ans=1e9;
		cin>>n>>m;
		rep(i,1,m,1){
			cin>>oo[i].ha>>oo[i].i;
			if(oo[i].ha=='+' || oo[i].ha=='-'){
				cin>>oo[i].j;
			}
		}	
			rep(g[1],0,2,1)	rep(g[2],0,2,1)	rep(g[3],0,2,1)	rep(g[4],0,2,1)	rep(g[5],0,2,1)rep(g[6],0,2,1)	rep(g[7],0,2,1)	rep(g[8],0,2,1)	rep(g[9],0,2,1)	rep(g[10],0,2,1){
			rep(i,1,n,1)	f[i]=g[i];
			rep(i,1,m,1){
				if(oo[i].ha=='+')	f[oo[i].i]=f[oo[i].j];
				else if(oo[i].ha=='-')	f[pp[i].i]=(f[oo[i].j]==2?f[oo[i].j]:1-f[oo[i].j]);
				else f[oo[i].i]=(oo[i].ha=='T'?0:(oo[i].ha=='F'?1:2));
				
			}
			}
			int cc=0;
			rep(i,1,n,1){
				if(f[i]!=g[i])	c=1e9;
				cc+=(g[i]==2);
			}ans=min(ans,cc);
		cout<<ans<<endl;
	}	
	return 0;
}