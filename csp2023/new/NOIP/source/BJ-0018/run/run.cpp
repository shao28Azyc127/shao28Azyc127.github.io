#include <bits/stdc++.h>
#define ll long long
#define N 100011
#define M N*100
using namespace std;
int t,n,m,k,d,c;
ll mx[M],cB[M],tag[M];int lc[M],rc[M],cA[M],rt,sz;
int make(){++sz;mx[sz]=0;cA[sz]=-1;cB[sz]=0;lc[sz]=rc[sz]=tag[sz]=0;return sz;}
void pushup(int x){mx[x]=max(mx[lc[x]],mx[rc[x]]);}
void applyc(int x,int A,ll B,int L,int R)
{
	mx[x]=1ll*A*R+B;cA[x]=A;cB[x]=B;tag[x]=0;
}
void applyt(int x,ll p,int L,int R)
{
	mx[x]+=p;tag[x]+=p;
}
void pushdown(int x,int L,int R)
{
	if(!lc[x])lc[x]=make();
	if(!rc[x])rc[x]=make();
	if(cA[x]!=-1)
	{
		applyc(lc[x],cA[x],cB[x],L,L+R>>1);
		applyc(rc[x],cA[x],cB[x],(L+R>>1)+1,R);
		cA[x]=-1;cB[x]=0;
	}
	if(tag[x])
	{
		applyt(lc[x],tag[x],L,L+R>>1);
		applyt(rc[x],tag[x],L+R>>1,R);
		tag[x]=0;
	}
}
void add(int l,int r,ll p,int L=1,int R=n+1,int x=rt)
{//printf("add([%d,%d],%lld,[%d,%d],%d)\n",l,r,p,L,R,x);
	if(l>r)return;
	if(l<=L&&R<=r){applyt(x,p,L,R);return;}pushdown(x,L,R);
	if(l<=L+R>>1)add(l,r,p,L,L+R>>1,lc[x]);if(r>L+R>>1)add(l,r,p,(L+R>>1)+1,R,rc[x]);pushup(x);
}
void add(int l,int r,int cA,ll cB,int L=1,int R=n+1,int x=rt)
{//printf("add([%d,%d],%lldx+%lld,[%d,%d],%d)\n",l,r,cA,cB,L,R,x);
	if(l>r)return;
	if(l<=L&&R<=r){applyc(x,cA,cB,L,R);return;}pushdown(x,L,R);
	if(l<=L+R>>1)add(l,r,cA,cB,L,L+R>>1,lc[x]);if(r>L+R>>1)add(l,r,cA,cB,(L+R>>1)+1,R,rc[x]);pushup(x);
}
vector<int> vr;
struct meal{int l,r,d;meal(){}meal(int _l,int _r,int _d){l=_l;r=_r;d=_d;}}ml[N];
vector<meal> vm[N];
bool cmp(meal a,meal b){return a.l>b.l;}
ll f[N];
int main()
{
	freopen("run.in","r",stdin);freopen("run.out","w",stdout);
	scanf("%*d%d",&t);while(t--)
	{
		for(int i=0;i<=c;++i)vm[i].clear();vr.clear();sz=0;rt=make();
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;++i)
		{
			int l,r,d;scanf("%d%d%d",&r,&l,&d);
			l=r-l+1;
			vr.push_back(r);
			ml[i]=meal(l,r,d);
			//printf("meal l:%d r:%d d:%d\n",l,r,d);
		}
		vr.push_back(0);
		sort(vr.begin(),vr.end());vr.resize(unique(vr.begin(),vr.end())-vr.begin());
		for(int i=1;i<=m;++i)
		{
			int id=lower_bound(vr.begin(),vr.end(),ml[i].r)-vr.begin();
			vm[id].push_back(ml[i]);
		}
		//printf("vr:");for(int x:vr)printf("%d ",x);putchar(10);
		c=vr.size()-1;
		for(int i=1;i<=c;++i)
		{//printf("==============================i:%d r:%d\n",i,vr[i]);
			//for(meal mm:vm[i])printf("meal l:%d r:%d d:%d\n",mm.l,mm.r,mm.d);
			f[i-1]=mx[rt];//printf("f[%d]:%lld\n",i-1,f[i-1]);
			add(1,vr[i-1]+1,-1ll*(vr[i]-vr[i-1])*d);
			add(vr[i-1]+2,vr[i]+1,d,-1ll*(vr[i]+1)*d+f[i-1]);
			add(1,max(0,vr[i]-k),0,-2000000000000000000ll);
			for(meal mm:vm[i])add(1,mm.l,mm.d);
		}
		printf("%lld\n",mx[rt]);//printf("sz:%d\n",sz);
	}
	fclose(stdin);fclose(stdout);return 0;
}