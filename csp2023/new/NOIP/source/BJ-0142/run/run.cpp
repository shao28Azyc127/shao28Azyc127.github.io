#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int c,t,n,m,k,d;
int x[100005],y[100005],v[100005];
bool fined[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	if(c>=17 && c<=18){
		while(t--){
			int ans=0;
			cin>>n>>m>>k>>d;
			for(int i=1;i<=m;i++){
				cin>>x[i]>>y[i]>>v[i];
			}
			for(int i=1;i<=m;i++){
				if(y[i]>k) continue;
				if(v[i]-d*y[i]>0){
					ans+=v[i]-d*y[i];
				}
			}
			cout<<ans<<endl;
		}
	}else{
		while(t--){
			memset(fined,0,sizeof(fined));
			int ans=0;
			cin>>n>>m>>k>>d;
			for(int i=1;i<=m;i++){
				cin>>x[i]>>y[i]>>v[i];
				if(v[i]-d*y[i]>0) for(int j=x[i]-y[i]+1;j<=x[i];j++) fined[j]=1;
			}
			if(k<=100){
				for(int i=1;i<=m;i++){
				if(y[i]>k) continue;
				if(v[i]-d*y[i]>0){
					ans+=v[i]-d*y[i];
					}
				}
				cout<<ans<<endl;
				continue;
			}
			for(int i=1;i<=n;i++){
				ans-=fined[i]*d;
			}
			for(int i=1;i<=m;i++) ans+=v[i];
			cout<<ans<<endl;
		}
	}
	return 0;
}
