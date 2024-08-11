#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
const int maxn = 1e5+10;
struct place{int a,b,c;int cur;}t[maxn];
struct edge{int u,v;}k[maxn];

bool cmp(place x,place y){
	if(x.a!=y.a)return x.a>y.a;
	if(x.b!=y.b)return x.b>y.b;
	return x.c>y.c;
}

bool done(){
	for(int i=1;i<=n;i++)
		if(t[i].cur!=t[i].a)return false;
	return true;
}

signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>t[i].a>>t[i].b>>t[i].c,t[i].cur=0;
	for(int i=1;i<n; i++)cin>>k[i].u>>k[i].v;
	sort(t+1,t+n+1,cmp);
	int x=1;
	for(;x<=n&&!done();x++){
		for(int j=1;j<=x;j++)
			t[j].cur+=max(t[j].b+x*t[j].c,(long long)(1));
	}
	if(done())cout<<x<<endl,exit(0);
	for(;!done();x++)
		for(int j=1;j<=n;j++)
			t[j].cur+=max(t[j].b+x*t[j].c,(long long)(1));
	cout<<x<<endl;
	return 0;
}