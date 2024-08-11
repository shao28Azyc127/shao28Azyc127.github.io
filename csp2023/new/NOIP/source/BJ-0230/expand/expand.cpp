#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int x[N],y[N];
int c,n,m,Q;
struct u{
	int p,v;
};
struct qry{
	vector<u> ux,uy;
};
vector<qry> q;
struct A{
	int a[N],b[N],f[2005][2005]={0};
	bool flg1,flg2;
	bool l(int i,int j){
		if(flg1&&i>j)return 1;
		if(!flg1&&i<j)return 1;
		return 0;
	}
	void sol(){
		flg1=a[1]>b[1],flg2=a[n]>b[m];
		if(flg1^flg2){cout<<0;return; }
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)f[i][j]=0;
		}
		for(int j=1;j<=m;++j){
			if(l(a[1],b[j])){
				f[1][j]=1;
			}else{
				break;
			}
		}
		for(int i=2;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(!f[i-1][j])continue;
				for(int k=j+1;k<=m;++k){
					if(!l(a[i],b[j]))break;
					f[i][k]=1;
				}
			}
		}
		cout<<f[n][m];
	}
	void solve(){
		for(int i=1;i<=n;++i)a[i]=x[i],b[i]=y[i];
		sol();
		for(int i=1;i<=Q;++i){
			for(int j=1;j<=n;++j)a[j]=x[j];
			for(int j=1;j<=m;++j)b[j]=y[j];
			for(u t:q[i].ux)a[t.p]=t.v;
			for(u t:q[i].uy)b[t.p]=t.v;
			sol();
		}
		cout<<'\n';
	}
}Sol1;
struct T{
    bool b=0;int x;
};
T ux1[N],uxn[N],uy1[N],uym[N];
signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin>>c>>n>>m>>Q;
	for(int i=1;i<=n;++i)cin>>x[i];
	for(int i=1;i<=m;++i)cin>>y[i];
	for(int i=1;i<=Q;++i){
		int kx,ky;cin>>kx>>ky;
		vector<u> ux,uy;ux.clear(),uy.clear();
		for(int j=0;j<kx;++j){
			int p,v;cin>>p>>v;
			ux.push_back({p,v});
			if(p==1)ux1[i]={1,v};
			if(p==n)uxn[i]={1,v};
		}
		for(int j=0;j<ky;++j){
			int p,v;cin>>p>>v;
			uy.push_back({p,v});
			if(p==1)uy1[i]={1,v};
			if(p==m)uym[i]={1,v};
		}
		q.push_back({ux,uy});
	}
	if(n<=200&&Q<=200)Sol1.solve();
	else{
        bool flg1=x[1]>y[1],flg2=x[n]>y[m];
        cout<<(flg1==flg2);
        for(int i=1;i<=Q;++i){
            if(ux1[i].b)x[1]=ux1[i].x;
            if(uxn[i].b)x[n]=uxn[i].x;
            if(uy1[i].b)y[1]=uy1[i].x;
            if(uym[i].b)y[m]=uym[i].x;
            flg1=x[1]>y[1],flg2=x[n]>y[m];
            cout<<(flg1==flg2);
        }
	}
	return 0;
}
