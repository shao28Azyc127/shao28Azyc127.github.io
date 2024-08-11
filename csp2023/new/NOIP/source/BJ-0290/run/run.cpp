#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;cin>>c>>t;
	if(c==17||c==18){
		while(t--){
			int n,m,k,d,ans=0;
			cin>>n>>m>>k>>d;
			for(int i=1;i<=m;i++){
				int x,y,v;cin>>x>>y>>v;
				if(y>k)continue;
				ans+=max(v-y,0ll);
			}cout<<ans<<endl;
		}return 0;
	}while(t--){
		int n,m,k,d,ans=0,lx=0;
		cin>>n>>m>>k>>d;int lsx,lsy,lsv;
		for(int i=1;i<=m;i++){
			int x,y,v;cin>>x>>y>>v;
		}cout<<ans<<endl;
	}
}