#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>void read(T &x){
	int f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
const int N=500020;
int CASE,n,m,q,kx,ky,s1,s2,s3,s4;
int od[N],d[N],oe[N],e[N];
void init1(){
	for(int i=1;i<=n;i++) d[i]=od[i];
	for(int i=1;i<=m;i++) e[i]=oe[i];
}
queue<pair<int,int> >qq;
void Solve(){
	bool bb=0;
	if((d[1]-e[1])*(d[n]-e[m])<=0){
		cout<<'0';
		return;
	}
	if(d[1]>e[1]){
		for(int i=1;i<=max(n,m);i++) swap(d[i],e[i]);
		swap(n,m);
	}
	while(!qq.empty()) qq.pop();
	qq.push(make_pair(1,1));
	while(!qq.empty()){
		int x=qq.front().first,y=qq.front().second;
		qq.pop();
		if(x==n and y==m){bb=1;break;}
		if(x!=n and d[x+1]<e[y]) qq.push(make_pair(x+1,y));
		if(y!=m and d[x]<e[y+1]) qq.push(make_pair(x,y+1));
	}
	cout<<bb;
}
signed main(){
	freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
	read(CASE),read(n),read(m),read(q);
	for(int i=1;i<=n;i++) read(od[i]);
	for(int i=1;i<=m;i++) read(oe[i]);
	init1();
	Solve();
	for(int i=1;i<=q;i++){
		init1();
		read(kx),read(ky);
		for(int i=1;i<=kx;i++) read(s1),read(s2),d[s1]=s2;
		for(int i=1;i<=ky;i++) read(s1),read(s2),e[s1]=s2;
		Solve();
	}
	return 0;
}
