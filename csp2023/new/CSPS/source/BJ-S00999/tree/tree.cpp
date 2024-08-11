#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N],ans=999999999,b[N],c[N],n,q[N];
bool k[N];
vector<int> g[N];
inline int getsum(int x){
	return x*(x-1)/2;
}
inline bool ok(int t){
	for(int i=1;i<=n;i++){
		int res=0;
		if(c[i]>=0) res=b[i]*(t-i+1)+c[i]*(getsum(t)-getsum(t-i-1));
		else{
			int j=t-i+1;
			while(b[i]+j*c[i]>=1){
				res+=b[i]+j*c[i];
				j++;
			}
			res+=(t-j+1);
		}
		if(res<a[i]) return 0;
	}
	return 1;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    	int l=0,r=1e9;
    	while(l<r){
    		int mid=l+r>>1;
    		if(ok(mid)) l=mid+1;
    		else r=mid-1;
    	}
    	cout<<l;
  
    return 0;
}
