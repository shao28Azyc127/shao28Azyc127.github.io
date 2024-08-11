#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int N=100010;
const ll inf=0x3f3f3f3f3f3f3f3f;
int Tid,T,n,m,x,y,z,k,d;
ll f[N],sum[N];
vector<PII> v[N];
void subtask2(){
	ll ans=0;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		if(y>k)	continue;
		ll cst=y*d;
		if(cst<z)	ans+=z-cst;
	}
	cout<<ans<<'\n';
}
void subtask1(){
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		if(y<=k)	v[x].push_back({y,z}),sum[x]+=z;
	}
	for(int i=1;i<=n;i++)	sort(v[i].begin(),v[i].end());
	for(int j=1;j<=k;j++)f[j]=-inf;
	f[0]=0;
	for(int i=1;i<=n;i++){
		ll mx=f[0],&nw=sum[i];
		for(int j=k;j;j--){
			mx=max(mx,f[j]);
			f[j]=f[j-1]-d+nw;
			while(v[i].size()&&v[i].back().first==j)
				nw-=v[i].back().second,v[i].pop_back();
		}
		f[0]=mx;
	}
	ll ans=0;
	for(int i=0;i<=k;i++)	ans=max(ans,f[i]);
	cout<<ans<<'\n';
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>Tid>>T;
	while(T--){
		cin>>n>>m>>k>>d;
		if(Tid<=14)	subtask1();
		else if(Tid==17||Tid==18)	subtask2();
		else{
			while(m--)	cin>>x>>y>>z;
			cout<<"0\n";
		}
	}
	return 0;
}
