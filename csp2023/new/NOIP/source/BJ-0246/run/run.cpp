#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
int x[100010],y[100010],v[100010],mp[110],q[110];
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin >> c >> t;
	if(c>=3){
		while(t--){
			int  n,m,k,d,ans=0;
			cin >> n >> m >> k >> d;
			fr(i,1,m){
				
				cin >> x[i] >> y[i]>>v[i];
				if(y[i]*d<v[i])ans+=v[i]-(y[i]*d);
			}
			cout << ans <<endl;
		}
	}
	else{
		while(t--){
			int  n,m,k,d;
			cin >> n >> m >> k >> d;
			fr(i,1,m)
				cin >> x[i] >> y[i]>>v[i];
			int rans=0;
			fr(md,0,(1<<n)-1){
				int ans=0,cnt=0;
				bool flag=0;
				fr(i,1,n){
					mp[i]=(md>>(i-1))&1,q[i]=q[i-1]+mp[i];
					if(mp[i]){
						cnt++;
						if(cnt>k){
							flag=1;
							break;
							
						}
					}
					ans-=mp[i]*d;
					if(!mp[i])cnt=0;
				}
				if(flag)continue;
				fr(i,1,m)
					if(q[x[i]]-q[x[i]-y[i]]==y[i])ans+=v[i];
				rans=max(rans,ans);
			}
			cout << rans << endl;
		}
	}
	return 0;
}
