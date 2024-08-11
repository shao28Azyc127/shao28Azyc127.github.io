#include<bits/stdc++.h>
using namespace std;
bool op[100005];
struct node{
	int op,v,id,rev;
}st[100005];
struct edg{
	int v,w;
};
vector<edg>edge[300005];
void addedge(int u,int v,int w){
	edge[u].push_back((edg){v,w});
	edge[v].push_back((edg){u,w});
}
bool vis[300005];
int ccnt=0,color[300005];
void dfs1(int x){
	vis[x]=1;
	color[x]=ccnt;
	for(int i=0;i<edge[x].size();i++){
		int v=edge[x][i].v,w=edge[x][i].w;
		if(vis[v]||w==1) continue;
		dfs1(v);
	}
}
void dfs2(int x){
	vis[x]=1;
	for(int i=0;i<edge[x].size();i++){
		int v=edge[x][i].v;
		if(vis[v]) continue;
		dfs2(v);
	}
}
int fa[600005],kil[600005];
int find(int x){
	if(x==fa[x]) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int n,m,c,t,x,y;
	cin>>c>>t;
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			st[i]=(node){1,0,i,0};
		}
		for(int i=1;i<=m;i++){
			char ch=getchar();
			while(ch!='T'&&ch!='F'&&ch!='U'&&ch!='+'&&ch!='-') ch=getchar();
			if(ch=='T'){
				scanf("%d",&x);
				st[x]=(node){2,1,0,0};
			}
			else if(ch=='F'){
				scanf("%d",&x);
				st[x]=(node){2,-1,0,0};
			}
			else if(ch=='U'){
				scanf("%d",&x);
				st[x]=(node){2,0,0,0};
			}
			else if(ch=='+'){
				scanf("%d%d",&x,&y);
				st[x]=st[y];
			}
			else{
				scanf("%d%d",&x,&y);
				st[x]=st[y];
				st[x].v=-st[x].v,st[x].rev=st[x].rev^1;
			}
		}
		for(int i=1;i<=n+3;i++) vis[i]=0,edge[i].clear();
		for(int i=1;i<=n;i++){
			if(st[i].op==1) addedge(i,st[i].id,st[i].rev);
			else addedge(i,n+2+st[i].v,0);
		}
		for(int i=1;i<=n+3;i++) vis[i]=0;
		ccnt=0;
		for(int i=1;i<=n+3;i++) if(!vis[i]) ccnt++,dfs1(i);
		for(int i=1;i<=ccnt*2;i++) fa[i]=i;
		for(int i=1;i<=ccnt;i++) kil[i]=0;
		kil[color[n+2]]=1;
		for(int i=1;i<=n+3;i++){
			for(int j=0;j<edge[i].size();j++){
				int v=edge[i][j].v,w=edge[i][j].w;
				if(w==0) continue;
				if(color[v]==color[i]){
					kil[color[v]]=1;
					continue;
				}
				int fu=find(color[i]),fv=find(color[v]+ccnt);
				if(fu!=fv){
					fa[fu]=fv;
				}
				fu=find(color[i]+ccnt),fv=find(color[v]);
				if(fu!=fv){
					fa[fu]=fv;
				}

			}
		}
		for(int i=1;i<=ccnt;i++){
			if(find(i)==find(i+ccnt)){
				kil[i]=1;
			}
		}
		for(int i=1;i<=n+3;i++) vis[i]=0;
		for(int i=1;i<=n+3;i++){
			if((!vis[i])&&kil[color[i]]) dfs2(i);
		}
		int ans=0;
		for(int i=1;i<=n;i++) ans+=vis[i];
		printf("%d\n",ans);
	}
	return 0;
}