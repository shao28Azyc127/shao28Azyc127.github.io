#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
long long n,d,dis[MAXN],val[MAXN],ans,cnt,minn=LLONG_MAX;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<=n-1;i++)cin>>dis[i];
	for(int i=1;i<=n;i++)cin>>val[i];
	for(int i=1;i<=n-1;i++){
		minn=min(minn,val[i]);
		if(dis[i]<=cnt){
			cnt-=dis[i];
			continue;
		}
		long long num=ceil((dis[i]*1.0-cnt*1.0)*1.0/d*1.0);
		ans+=num*minn;
		cnt+=num*d;
		cnt-=dis[i];
	}
	cout<<ans;
	return 0;
}
