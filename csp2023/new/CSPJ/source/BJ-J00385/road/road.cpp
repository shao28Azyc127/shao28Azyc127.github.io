#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,d,dis[100005],p[100005],dist[100005],tot,minn=1e5+7,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>d;
	for(ll i=1;i<n;i++){
		cin>>dis[i];
		tot+=dis[i];
		dist[i]=dist[i-1]+dis[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>p[i];
		minn=min(p[i],minn);
	}
	if(n==1)cout<<0;
	else if(n==2)cout<<p[1]*(dis[1]/d+1);
	else if(minn==p[1]){
		if((tot-1)*p[1]/d==0)cout<<(tot*p[1])/d;
		else cout<<(tot*p[1]+1)/d;
	}
	else{
		ll flag=p[1],flag2=0;
		for(ll i=1;i<=n;i++){
			if(p[i]<flag){
				cout<<flag2;
				ans+=((dist[i]-dist[flag2])/d)*flag+1;
				flag=p[i];
				flag2=i;
			}
		}
		cout<<ans;
	}
	return 0;
}