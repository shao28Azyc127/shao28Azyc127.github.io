#include<bits/stdc++.h>
using namespace std;
int c,q,n,m,a[500005],b[500005];
struct node{
	int lc,rc,mx,mn;
}tr[2000005],tr2[2000005];
struct chg{int x,y;}cg[500005],cg2[500005];
int mmax(int x,int y){return x>y?x:y;}
int mmin(int x,int y){return x<y?x:y;}
inline void pushup(int p){
	tr[p].mx=mmax(tr[p<<1].mx,tr[p<<1|1].mx);
	tr[p].mn=mmin(tr[p<<1].mn,tr[p<<1|1].mn);
}
inline void pushup2(int p){
	tr2[p].mx=mmax(tr2[p<<1].mx,tr2[p<<1|1].mx);
	tr2[p].mn=mmin(tr2[p<<1].mn,tr2[p<<1|1].mn);
}
void build(int p,int l,int r){
	tr[p].lc=l,tr[p].rc=r;
	if(l==r){tr[p].mx=tr[p].mn=a[l];return;}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pushup(p);
}
void build2(int p,int l,int r){
	tr2[p].lc=l,tr2[p].rc=r;
	if(l==r){tr2[p].mx=tr2[p].mn=b[l];return;}
	int mid=(l+r)>>1;
	build2(p<<1,l,mid);
	build2(p<<1|1,mid+1,r);
	pushup2(p);
}
void upd(int p,int x,int v){
	if(tr[p].lc==tr[p].rc){tr[p].mx=tr[p].mn=v;return;}
	int mid=(tr[p].lc+tr[p].rc)>>1;
	if(x<=mid)upd(p<<1,x,v);
	else upd(p<<1|1,x,v);
	pushup(p);
}
void upd2(int p,int x,int v){
	if(tr2[p].lc==tr2[p].rc){tr2[p].mx=tr2[p].mn=v;return;}
	int mid=(tr2[p].lc+tr2[p].rc)>>1;
	if(x<=mid)upd2(p<<1,x,v);
	else upd2(p<<1|1,x,v);
	pushup2(p);
}
int askmin(int p,int l,int r){
	if(l<=tr[p].lc&&tr[p].rc<=r)return tr[p].mn;
	int mid=(tr[p].lc+tr[p].rc)>>1,ans=1e9;
	if(l<=mid)ans=min(ans,askmin(p<<1,l,r));
	if(r>mid)ans=min(ans,askmin(p<<1|1,l,r));
	return ans;
}
int askmin2(int p,int l,int r){
	if(l<=tr2[p].lc&&tr2[p].rc<=r)return tr2[p].mn;
	int mid=(tr2[p].lc+tr2[p].rc)>>1,ans=1e9;
	if(l<=mid)ans=min(ans,askmin2(p<<1,l,r));
	if(r>mid)ans=min(ans,askmin2(p<<1|1,l,r));
	return ans;
}
int askmax(int p,int l,int r){
	if(l<=tr[p].lc&&tr[p].rc<=r)return tr[p].mx;
	int mid=(tr[p].lc+tr[p].rc)>>1,ans=-1e9;
	if(l<=mid)ans=max(ans,askmax(p<<1,l,r));
	if(r>mid)ans=max(ans,askmax(p<<1|1,l,r));
	return ans;
}
int askmax2(int p,int l,int r){
	if(l<=tr2[p].lc&&tr2[p].rc<=r)return tr2[p].mx;
	int mid=(tr2[p].lc+tr2[p].rc)>>1,ans=-1e9;
	if(l<=mid)ans=max(ans,askmax2(p<<1,l,r));
	if(r>mid)ans=max(ans,askmax2(p<<1|1,l,r));
	return ans;
}
void solve(){
	int id=0;
	if(n==m){
		int flag1=1,flag2=1;
		for(int i=1;i<=n;++i){
			int mxa=askmax(1,1,i),nowa=a[i],nowb=b[i],mnb=askmin2(1,1,i);
			// cerr<<i<<": "<<mxa<<' '<<mnb<<' '<<nowa<<' '<<nowb<<'\n';
			if(nowa<=mnb&&nowb>=mxa){flag1=0;break;}
		}
		for(int i=n;i>=1;--i){
			int mxa=askmax(1,i,n),nowa=a[i],nowb=b[i],mnb=askmin2(1,i,m);
			// cerr<<i<<": "<<mxa<<' '<<mnb<<' '<<nowa<<' '<<nowb<<'\n';
			if(nowa<=mnb&&nowb>=mxa){flag2=0;break;}
		}
		if(flag1&&flag2){cout<<"1";return;}
		flag1=flag2=1;
		for(int i=1;i<=n;++i){
			int mna=askmin(1,1,i),nowa=a[i],nowb=b[i],mxb=askmax2(1,1,i);
			// cerr<<i<<": "<<mna<<' '<<mxb<<' '<<nowa<<' '<<nowb<<'\n';
			if(nowa>=mxb&&nowb<=mna){flag1=0;break;}
		}
		for(int i=n;i>=1;--i){
			int mna=askmin(1,i,n),nowa=a[i],nowb=b[i],mxb=askmax2(1,i,m);
			// cerr<<i<<": "<<mna<<' '<<mxb<<' '<<nowa<<' '<<nowb<<'\n';
			if(nowa>=mxb&&nowb<=mna){flag2=0;break;}
		}
		if(flag1&&flag2){cout<<"1";return;}
		cout<<"0";return;
	}
	if(n>m){
		int flag1=1,flag2=1;
		for(int i=1;i<=n;++i){
			int mxa=askmax(1,1,i),nowa=a[i],nowb=b[mmin(m,i)],mnb=askmin2(1,1,mmin(m,i));
			if(nowa<=mnb&&nowb>=mxa){flag1=0;break;}
		}
		for(int i=n;i>=1;--i){
			int mxa=askmax(1,i,n),nowa=a[i],nowb=b[mmax(m-n+i,1)],mnb=askmin2(1,mmax(m-n+i,1),m);
			if(nowa<=mnb&&nowb>=mxa){flag2=0;break;}
		}
		if(flag1&&flag2){cout<<"1";return;}
		flag1=flag2=1;
		for(int i=1;i<=n;++i){
			int mna=askmin(1,1,i),nowa=a[i],nowb=b[mmin(m,i)],mxb=askmax2(1,1,mmin(m,i));
			if(nowa>=mxb&&nowb<=mna){flag1=0;break;}
		}
		for(int i=n;i>=1;--i){
			int mna=askmin(1,i,n),nowa=a[i],nowb=b[mmax(m-n+i,1)],mxb=askmax2(1,mmax(m-n+i,1),m);
			if(nowa>=mxb&&nowb<=mna){flag2=0;break;}
		}
		if(flag1&&flag2){cout<<"1";return;}
		cout<<"0";return;
	}
	if(n<m){
		int flag1=1,flag2=1;
		for(int i=1;i<=m;++i){
			int mxa=askmax(1,1,mmin(n,i)),nowa=a[mmin(n,i)],nowb=b[i],mnb=askmin2(1,1,m);
			if(nowa<=mnb&&nowb>=mxa){flag1=0;break;}
		}
		for(int i=m;i>=1;--i){
			int mxa=askmax(1,mmax(1,n-m+i),n),nowa=a[mmax(1,n-m+i)],nowb=b[i],mnb=askmin2(1,1,m);
			if(nowa<=mnb&&nowb>=mxa){flag2=0;break;}
		}
		if(flag1&&flag2){cout<<"1";return;}
		flag1=flag2=1;
		for(int i=1;i<=m;++i){
			int mna=askmin(1,1,mmin(n,i)),nowa=a[mmin(n,i)],nowb=b[i],mxb=askmax2(1,1,m);
			if(nowa>=mxb&&nowb<=mna){flag1=0;break;}
		}
		for(int i=m;i>=1;--i){
			int mna=askmin(1,mmax(1,n-m+i),n),nowa=a[mmax(1,n-m+i)],nowb=b[i],mxb=askmax2(1,1,m);
			if(nowa>=mxb&&nowb<=mna){flag2=0;break;}
		}
		if(flag1&&flag2){cout<<"1";return;}
		cout<<"0";return;
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i)cin>>b[i];
	build(1,1,n);build2(1,1,m);
	solve();
	for(int i=1;i<=q;++i){
		int kx,ky;cin>>kx>>ky;
		for(int i=1;i<=kx;++i){
			int x,y;cin>>x>>y;
			cg[i].x=x;cg[i].y=a[x];a[x]=y;
			upd(1,x,y);
		}
		for(int i=1;i<=ky;++i){
			int x,y;cin>>x>>y;
			cg2[i].x=x;cg2[i].y=b[x];b[x]=y;
			upd2(1,x,y);
		}
		// for(int i=1;i<=n;++i){
		// 	cerr<<askmin(1,i,i)<<' '<<askmin2(1,i,i)<<'\n';
		// }
		solve();
		for(int i=1;i<=kx;++i)upd(1,cg[i].x,cg[i].y);
		for(int i=1;i<=ky;++i)upd2(1,cg2[i].x,cg2[i].y);
		// for(int i=1;i<=n;++i){
		// 	cerr<<askmin(1,i,i)<<' '<<askmin2(1,i,i)<<'\n';
		// }
	}
	cout<<'\n';
	return 0;
}
//ÂÉÆø