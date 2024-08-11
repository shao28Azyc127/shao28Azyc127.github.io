//Genshin Impact (wrong) Zhenshen Impart (true)
//I love Kamisato Ayaka
#include <bits/stdc++.h>
#define int long long
#define rep(i,a,b,c) for(int (i)=a;i<=(b);i+=(c))
#define per(i,a,b,c) for(int (i)=a;i>=(b);i-=(c))
#define pb push_back
using namespace std;

const int MAXN=200000;

vector<int> adj[MAXN];
int c[MAXN],b[MAXN],a[MAXN];
int f[MAXN];

void sol_sub1(int u,int fa){
	f[u]=(a[u]+b[u]-1)/b[u];
	vector<int> vec;
	for(auto v:adj[u]){
		if(v==fa)	continue ;
		sol_sub1(v,u);
		vec.pb(f[v]);
	}sort(vec.begin(),vec.end(),greater<int>());
	rep(i,0,(int)vec.size()-1,1){
		f[u]=max(f[u],vec[i]+i+1);
	}
}
int gday(int a,int b,int c,int x){
	if(b+x*c>=a)	return x;
	if(c==0){
		return (a+b-1)/b+x-1;
	}
	if(c>=0){
		int u=c,v=(2*x-1)*c+2*b,w=-2*a;
		long double qwq=-v+sqrtl(v*v-4*u*w);
		qwq/=2*u;
		//cout<<fixed<<setprecision(6)<<qwq<<u<<" "<<v<<" "<<w<<" "<<(2*x-1)*c<<" "<<2*b<<endl;
		qwq=ceil(qwq);
		return qwq+x-1;
	}if(c<=0){
		int u=c,v=(2*x-1)*c+2*b,w=-2*a;
		long double qwq=-v-sqrtl((long double)v*v-4*u*w);
		qwq/=2*u;
		qwq=ceil(qwq);
		//cout<<
		if(c*(qwq+x-1)+b>=1)	return qwq+x-1;
		int tt=(1-b)/c;tt=tt-x+1;
		int qwwq=tt*b+c*(2*x+tt-1)*tt/2;
		//cout<<"A"<<x<<" "<<tt<<" "<<qwwq<<endl;
		return x+tt+a-qwwq-1;
	}return 115;
}


signed main(){
freopen("tree.in","r",stdin);
freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	bool is1=1,is2=1;
	rep(i,1,n,1)	cin>>a[i]>>b[i]>>c[i];
	rep(i,1,n,1)	is1&=(c[i]==0);
	rep(i,1,n-1,1){
		int u,v;cin>>u>>v;
		adj[u].pb(v);adj[v].pb(u);
		if(u!=i || v!=i+1)	is2=0;	
	}	
	if(is1){
		sol_sub1(1,0);
		cout<<f[1]<<endl;
		return 0;
	}
		int ans=1;
		rep(i,1,n,1){	ans=max(ans,gday(a[i],b[i],c[i],i));}
		cout<<ans<<endl;
	return 0;
}