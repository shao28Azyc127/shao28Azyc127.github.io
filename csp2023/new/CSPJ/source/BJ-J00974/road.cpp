#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,d,v[N],a[N],ans,x1;
signed main(){
  freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int dan=a[1];
    for(int i=1;i<=n-1;i++){
		if(ceil(((v[i]-x1)*1.0)/d)*a[i]<=ceil(((v[i]-x1)*1.0)/d)*dan){
			ans+=ceil(((v[i]-x1)*1.0)/d)*a[i];
			dan=a[i];
		}
		else{
			ans+=ceil(((v[i]-x1)*1.0)/d)*dan;
		}
		x1=ceil(((v[i]-x1)*1.0)/d)*d-v[i]+x1;
	}
	cout<<ans;
    return 0;
}
