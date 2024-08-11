#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,t,nm;
struct node{
	ll sp,k;
	string t[105],nm[105];
};
struct node2{
	node t;
	string nm;
	ll l,r;
};
map<string,node> mp;
vector<node2> v;
ll sp;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	ll n,op;
	mp["byte"].sp=1; mp["short"].sp=2; mp["int"].sp=4; mp["long"].sp=8;
	cin>>n;
	for(ll i=1; i<=n; i++){
		scanf("%lld",&op);
		if(op==1){
			cin>>s; scanf("%lld",&mp[s].k);
			ll mx=0;
			for(ll j=1; j<=mp[s].k; j++){
				cin>>mp[s].t[i]>>mp[s].nm[i];
				mx=max(mx,mp[mp[s].t[i]].sp);
			}
			mp[s].sp=mx;
			printf("%lld %lld\n",mx*mp[s].k,mx);
		}else if(op==2){
			cin>>t>>nm;
			printf("%lld\n",sp);
			v.push_back({mp[t],nm,sp,sp+mp[t].k*mp[t].sp});
			sp+=mp[t].k*mp[t].sp;
		}
	}
	return 0;
}
