#include <bits/stdc++.h>
#define for0(i,n) for(i=0;i<(n);i++)
#define for1(i,n) for(i=1;i<=(n);i++)
#define forlr(i,l,r) for(i=(l);i<=(r);i++)
using namespace std;
const int N=400010;
int C,T,ans,fa[N],cp,cb,tal[N],n,m,hea[N],nxt[N],to[N],w[N],f[N];
char s[10];
bool b[N],g,v[N];
void addb(int x,int y,int z){
	to[++cb]=y;w[cb]=z;
	nxt[cb]=hea[x];hea[x]=cb;
}
void add(int x,int y,int z){
	addb(x,y,z);
	addb(y,x,z);
}
void dfs(int x,int dis){
	int i;
	if(f[x]){
		if((dis-f[x])&1) g=1;
		return ;
	}
	f[x]=dis;
	if(b[x]) g=1;
	for(i=hea[x];i;i=nxt[i]) dfs(to[i],dis+w[i]);
}
void sov(int x){
	if(v[x]) return ;
	v[x]=1;
	if(x<=n) ans++;
	int i;
	for(i=hea[x];i;i=nxt[i]) sov(to[i]);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int i,tim,x,y;
	char o;
	scanf("%d%d",&C,&T);
	for1(tim,T){
		scanf("%d%d",&n,&m);
		cp=n;cb=1;ans=0;g=0;
		for1(i,n) tal[i]=i;
		memset(hea,0,sizeof(hea));
		memset(nxt,0,sizeof(nxt));
		memset(to,0,sizeof(to));
		memset(w,0,sizeof(w));
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		memset(v,0,sizeof(v));
		for1(i,m){
			scanf("%s",s);
			o=s[0];
			if(o=='T'||o=='F'||o=='U'){
				scanf("%d",&x);
				tal[x]=++cp;
				if(o=='U') b[cp]=1;
			}else{
				scanf("%d%d",&x,&y);
				y=tal[y];tal[x]=++cp;
				if(o=='+') add(cp,y,0);
				else add(cp,y,1);
			}
		}
		for1(i,n) add(i,tal[i],0);
		for1(i,cp) if(!f[i]){
			g=0;dfs(i,1);
			if(g==1) sov(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1 1
5 7
U 5
+ 5 1
+ 5 2
+ 5 3
+ 5 4
U 5
+ 1 5
*/
