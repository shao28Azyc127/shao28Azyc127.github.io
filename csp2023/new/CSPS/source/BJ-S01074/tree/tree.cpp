#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>void read(T &x){
	x=0;int f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x=x*f;
}
const int N=100020;
struct Data{int a,b,c;}d[N];
struct Ranj{int x,no;}e[N];
bool cmp(Ranj a,Ranj b){
	if(a.x!=b.x) return a.x<b.x;
	return a.no<b.no;
}
struct Edge{int p,next;}edge[N*2];
int cnt=0,cmt,head[N];
int n,ans,mid,l,r,cmid,cl,cr,s1,s2,s3,s4,fa[N],vis[N];
bool b1,b2;
__int128 bs1,bs2;
void add(int u,int v){
	cnt++;
	edge[cnt]=(Edge){v,head[u]};
	head[u]=cnt;
}
void dfs(int cur,int faa){
	fa[cur]=faa;
	for(int i=head[cur];i;i=edge[i].next)
		if(edge[i].p!=faa) dfs(edge[i].p,cur);
}
void mARC(int cur){
	if(cur==0 or vis[cur]==1) return;
	s4++,vis[cur]=1,mARC(fa[cur]);
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(d[i].a),read(d[i].b),read(d[i].c);
	for(int i=1;i<n;i++){
		read(s1),read(s2);
		add(s1,s2),add(s2,s1);
	}
	dfs(1,0);
	l=1,ans=r=1e9;
	while(l<=r){
		mid=(l+r)/2,b1=1;
		memset(vis,0,sizeof(vis)),s4=0;
		for(int i=1;i<=n;i++){
			cl=1,cr=mid,e[i].x=-1,e[i].no=i;
			s1=((d[i].c<0)?((d[i].b-1-d[i].c)/(-d[i].c)):(1e9+50));
			while(cl<=cr){
				cmid=(cl+cr)/2;
				if(s1>mid){
					bs1=((d[i].b+cmid*d[i].c)+(d[i].b+mid*d[i].c));
					bs1*=(mid-cmid+1),bs1/=2;
				}
				else{
					if(cmid>=s1) bs1=mid-cmid+1;
					else{
						bs1=((d[i].b+cmid*d[i].c)+(d[i].b+(s1-1)*d[i].c));
						bs1*=(s1-cmid),bs1/=2;
						bs1+=(mid-s1+1);
					}
				}
				bs2=d[i].a;
				if(bs1>=bs2) e[i].x=cmid,cl=cmid+1;
				else cr=cmid-1;
			}
			if(e[i].x==-1){b1=0;break;} 
		}
		if(b1==0){l=mid+1;continue;}
		sort(e+1,e+1+n,cmp);
		cmt=1;
		while(cmt<=n){
			mARC(e[cmt].no);
			if(s4>e[cmt].x) b1=0;
			cmt++;
		}
		if(b1==0){l=mid+1;continue;}
		ans=mid,r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
/* 
 * another problem called tree!
 * 
 * our kibou (sadly only for the next month now) "field_and_forest" must have solved this this time!
 * 
 * since this problem is their people again!
 * 
 * so strong wow
 */
