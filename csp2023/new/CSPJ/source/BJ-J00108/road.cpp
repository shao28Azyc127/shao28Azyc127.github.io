#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
priority_queue<ll,vector<ll>, greater<ll> >q;
ll n,d,p[N],dis[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;ll genshin=0,impact=0;
	for(int i=1;i<n;i++){scanf("%lld",&dis[i]);}
	for(int i=1;i<=n;i++){
		scanf("%lld",&p[i]);
		q.push(p[i]);
		if(genshin>=dis[i]){
			genshin-=dis[i];
		}
		else{
			ll low=q.top();
			//cout<<dis[i]<<' '<<genshin<<' '<<d<<endl;
			ll t;
			if((dis[i]-genshin)%d==0){t=(dis[i]-genshin)/d;}
			else t=(dis[i]-genshin)/d+1;
			//cout<<i<<' '<<t<<"sheng"<<endl;
			impact+=t*low;
			genshin+=t*d;
			genshin-=dis[i];
		}
	}
	cout<<impact;
	return 0;
}
//~ 5 4
//~ 10 10 10 10
//~ 9 8 9 6 5
