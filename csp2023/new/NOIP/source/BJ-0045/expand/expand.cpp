#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,q,a[N],b[N],x[N],y[N];
bool f[N];
void spe(){
	
}
void solve(){
	int res=0;
	fill(f,f+1+m,0);f[1]=1;
	for(int i=1;i<=n;i++){
		int nxt;
		for(int j=1;j<=m;j=nxt){
			nxt=m+1;
			for(int k=j+1;k<=m;k++)
				if(f[k]){nxt=k;break;}
			if(!f[j])continue;
			for(int k=j;k<nxt;k++){
				if(y[k]>=x[i]){
					f[k]=0;
					break;
				}else f[k]=1;
			}
		}
	}
	res|=f[m];if(res){cout<<1;return;}
	fill(f,f+1+m,0);f[1]=1;
	for(int i=1;i<=n;i++){
		int nxt;
		for(int j=1;j<=m;j=nxt){
			nxt=m+1;
			for(int k=j+1;k<=m;k++)
				if(f[k]){nxt=k;break;}
			if(!f[j])continue;
			for(int k=j;k<nxt;k++){
				if(y[k]<=x[i]){
					f[k]=0;
					break;
				}else f[k]=1;
			}
		}
	}
	res|=f[m];
	cout<<res;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	y[m+1]=2e9;y[0]=-1;
	for(int i=1;i<=n;i++)x[i]=a[i];
	for(int i=1;i<=m;i++)y[i]=b[i];
	solve();
	while(q--){
		int kx,ky,p,v;
		cin>>kx>>ky;
		for(int i=1;i<=n;i++)x[i]=a[i];
		for(int i=1;i<=m;i++)y[i]=b[i];
		for(int i=1;i<=kx;i++)
			cin>>p>>v,x[p]=v;
		for(int i=1;i<=ky;i++)
			cin>>p>>v,y[p]=v;
		solve();
	}
	cout<<endl;
	//cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
