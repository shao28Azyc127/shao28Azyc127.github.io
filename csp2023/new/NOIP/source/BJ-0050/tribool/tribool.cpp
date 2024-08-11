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
int CASE,T,n,m,d[N],co[N];
int cnt,cmt,head[N],ans,s1,s2,s3;
vector<int>g;
char op;
struct Oper{char tp;int x,y;}c[N];
struct Edge{int p,next;}edge[N];
void add(int u,int v){
	cnt++;
	edge[cnt]=(Edge){v,head[u]};
	head[u]=cnt;
}
void dfs0(int x,int col){
	if(d[x]==0 and col==0) return;
	d[x]=0;
	for(int i=head[x];i;i=edge[i].next)
		dfs0(edge[i].p,0);
}
void dfs1(int x,int col){
	if(co[x]!=0 and col!=co[x]) s2=1;
	if(s2 or co[x]!=0) return;
	co[x]=col;
	for(int i=head[x];i;i=edge[i].next)
		dfs1(edge[i].p,3-col);
}
void dfs2(int x){
	if(co[x]==3) return;
	co[x]=3;
	if(x<=n) s1++;
	for(int i=head[x];i;i=edge[i].next)
		dfs2(edge[i].p);
}
signed main(){
	freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
	cin>>CASE>>T;
	while(T){
		T--;
		memset(head,0,sizeof(head)),cnt=cmt=ans=0;
		g.clear();
		memset(co,0,sizeof(co));
		cin>>n>>m,cmt=n;
		for(int i=1;i<=n;i++) d[i]=i;
		for(int i=1;i<=m;i++){
			cin>>op;
			c[i].tp=op;
			if(op=='T' or op=='F' or op=='U') cin>>c[i].x;
			else cin>>c[i].x>>c[i].y;
		}
		for(int i=1;i<=m;i++){
			if(c[i].tp=='T') d[c[i].x]=100001;
			if(c[i].tp=='F') d[c[i].x]=-100001;
			if(c[i].tp=='U') d[c[i].x]=0;
			if(c[i].tp=='+') d[c[i].x]=d[c[i].y];
			if(c[i].tp=='-') d[c[i].x]=-d[c[i].y];
		}
		for(int i=1;i<=n;i++){
			if(abs(d[i])>100000) continue;
			if(d[i]==0){g.push_back(i);continue;}
			add(abs(d[i]),i);
		}
		for(int i=0;i<g.size();i++) dfs0(g[i],1);
		memset(head,0,sizeof(head)),cnt=0;
		for(int i=1;i<=n;i++){
			if(abs(d[i])>100000 or d[i]==0) continue;
			if(d[i]<0) add(abs(d[i]),i),add(i,abs(d[i]));
			else{
				cmt++;
				add(abs(d[i]),cmt),add(cmt,abs(d[i]));
				add(i,cmt),add(cmt,i);
			}
		}
		for(int i=1;i<=n;i++){
			if(abs(d[i])>100000 or d[i]==0){
				if(d[i]==0) ans++;
				continue;
			}
			if(co[i]!=0) continue;
			s1=s2=s3=0;
			dfs1(i,1),dfs2(i);
			if(s2) ans+=s1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
 * a problem called tribool!
 * 
 * out big-black-red-sun devout must have solved this with all those gadgets!
 * 
 * after all he proved that graph 3-coloring is npc using this
 * 
 * so strong wow
 */
