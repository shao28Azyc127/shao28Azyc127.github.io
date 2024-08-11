//Ayaka bless me
#include <bits/stdc++.h>
#define rep(i,a,b,c)	for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c)	for(int i=(a);i>=(b);i-=(c))
#define i64 long long
#define pb push_back
#define _1 first
#define _2 second
using namespace std;

const int mod=1e9+7;
const int maxn=1705000;
const int maxn2=305000;

int fpow(int a,int b){
	if(b==1)	return a;if(b==0)	return 1;
	int ans=fpow(a,b/2);ans*=ans;ans%=mod;
	if(b%2)	ans*=a;return ans%mod;
}	

i64 ma[maxn*4],tag[maxn*4];
int lc[maxn*4],rc[maxn*4];
int chs=1;

void pdown(const int u){
if(tag[u]==0)	return ;
if(lc[u]==0)	lc[u]=++chs,ma[chs]=tag[chs]=lc[chs]=rc[chs]=0;
if(rc[u]==0)	rc[u]=++chs,ma[chs]=tag[chs]=lc[chs]=rc[chs]=0;
	ma[lc[u]]+=tag[u],tag[lc[u]]+=tag[u];
	ma[rc[u]]+=tag[u],tag[rc[u]]+=tag[u];
	tag[u]=0;
}
int qadd(int u,int l,int r,const int &ql,const int &qr,const i64 &val){
if(u==0)	u=++chs,ma[u]=tag[u]=lc[u]=rc[u]=0;
if(ql>qr)	return u;
	if(ql<=l && r<=qr){
		ma[u]+=val;tag[u]+=val;return u;
	}int mid=(l+r)/2;pdown(u);
	if(ql<=mid){
		lc[u]=qadd(lc[u],l,mid,ql,qr,val);
	}if(mid<qr){
		rc[u]=qadd(rc[u],mid+1,r,ql,qr,val);
	}ma[u]=max(ma[lc[u]],ma[rc[u]]);return u;
}
i64 query(int u,int l,int r,const int &ql,const int &qr){
if(u==0)	return -1e16;
if(lc[u]==0 && rc[u]==0)	return ma[u];
	if(ql<=l && r<=qr){
		return ma[u];
	}int mid=(l+r)/2;i64 ans=-1e16;pdown(u);
	if(ql<=mid)	ans=max(ans,query(lc[u],l,mid,ql,qr));
	if(mid<qr)	ans=max(ans,query(rc[u],mid+1,r,ql,qr));
	return ans;
}

int tmp[maxn2],tr[maxn2];
int ll[maxn2],rr[maxn2],vv[maxn2];
vector<pair<int,int>> ques[maxn2];
int M2i[maxn2];
int lls[maxn2];

signed main(){
freopen("run.in","r",stdin);
freopen("run.out","w",stdout);
	int c,t;scanf("%d%d",&c,&t);
	while(t--){chs=1;
		int n,m,k;
		i64 d,cc=0;
		scanf("%d%d%d%lld",&n,&m,&k,&d);
		ma[1]=tag[1]=lc[1]=rc[1]=0;
		rep(i,0,m+1,1)	ques[i].clear();
		rep(i,1,m,1){
			int x,y,v;scanf("%d%d%d",&x,&y,&v);
			ll[i]=x-y+1,rr[i]=x,vv[i]=v;
			tr[i]=rr[i];lls[++cc]=ll[i]-1;
		}int lst=0;
		//rep(i,1,n,1)	lls[i]=i-1;
		sort(tr+1,tr+1+m);
		sort(lls+1,lls+1+cc);
		int qwq2=unique(lls+1,lls+1+cc)-lls-1;
		int qwq=unique(tr+1,tr+1+m)-tr-1;
		map<int,int> M;rep(i,1,qwq,1){
			M[tr[i]]=i;M2i[i]=tr[i];
		}rep(i,1,m,1){
			ques[M[rr[i]]].pb({ll[i],vv[i]});
		}i64 ans=0,flst=0;
		int curl=1;
		rep(i,1,qwq,1){
			int afk=max(0,M2i[i]+1-k-1);
			qadd(1,0,n+1,M2i[i-1]+2,M2i[i],flst);
			for(auto [l,v]:ques[i]){
				if(l-1>=afk)	qadd(1,0,n+1,0,l-1,v);
			}
			if(M2i[i-1]>=afk)	qadd(1,0,n+1,M2i[i-1],M2i[i-1],-d*(M2i[i]-1-M2i[i-1]+1));
			if(M2i[i-1]+1>=afk)	qadd(1,0,n+1,M2i[i-1]+1,M2i[i-1]+1,-d*(M2i[i]-1-M2i[i-1]-1+1));
			int lst=M2i[i-1]+2;
			while(curl<=qwq2){
				if(max(lst,lls[curl])>M2i[i]-1)	break ;
				int t=lls[curl];
				if(M2i[i-1]+2<=t){
					if(t>=afk)	qadd(1,0,n+1,max(lst,afk),t,-d*(M2i[i]-1-t+1));
					lst=t+1;
				}curl++;
			}
			qadd(1,0,n+1,lst,M2i[i]-1,-d);//qadd(1,0,n+1,M2i[i],M2i[i],flst);
			if(M2i[i-1]-1>=afk)	qadd(1,0,n+1,0,M2i[i-1]-1,(-d)*(M2i[i]-1-M2i[i-1]+1));
			i64 fnow=query(1,0,n+1,max(0,M2i[i]+1-k-1),n+1);
			qadd(1,0,n+1,M2i[i]+1,M2i[i]+1,fnow);
			ans=max(ans,fnow);flst=fnow;
		}
		printf("%lld\n",ans);
	}
	
	
	return 0;
}