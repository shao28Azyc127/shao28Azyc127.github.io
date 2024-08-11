#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=100010;
int c,t,n,m,val[N],done[N],tim;
vector<int> g[N];
void clear(int p){
	vector<int> nn;
	swap(nn,g[p]);
}
int vis[N];
void dfsset(int p){
	for(int i=0; i<g[p].size(); ++i){
		int tar=g[p][i];
		if(done[tar])
			continue;
		if(val[tar]<0)
			done[tar]=4-done[p];
		else
			done[tar]=done[p];
		dfsset(tar);
	}
}
int pos[N];
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d %d",&c,&t);
	for(int xyz=1; xyz<=t; ++xyz){
		scanf("%d %d",&n,&m);
		memset(val,0,sizeof(val));
		for(int i=1; i<=n; ++i)
			val[i]=i;
		for(int i=1; i<=m; ++i){
			char typ;
			int x,y;
			typ=getchar();
			while(typ==' ' || typ=='\n')
				typ=getchar();
			if(typ=='+'){
				scanf("%d %d",&x,&y);
				val[x]=val[y];
			}
			else if(typ=='-'){
				scanf("%d %d",&x,&y);
				if(val[y]>N)
					val[x]=N+4-(val[y]-N);
				else
					val[x]=-val[y];
			}
			else{
				scanf("%d",&x);
				if(typ=='T')
					val[x]=N+1;
				else if(typ=='F')
					val[x]=N+3;
				else
					val[x]=N+2;
			}
		}
		memset(done,0,sizeof(done));
		for(int i=0; i<=n+5; ++i)
			clear(i);
		for(int i=1; i<=n; ++i){
			if(val[i]<N){
				if(val[i]==-i)
					done[i]=2;
				else if(val[i]==i)
					done[i]=1;
				else
					g[abs(val[i])].push_back(i);
			}
			else
				done[i]=val[i]-N;
		}
		memset(vis,0,sizeof(vis));
		tim=1;
		for(int i=1; i<=n; ++i){
			if(done[i]>0)
				dfsset(i);
		}
		for(int i=1; i<=n; ++i){
			if(!done[i]){
				int p=i,typ=1;
				++tim;
				while(vis[p]!=tim){
					vis[p]=tim;
					pos[p]=typ;
					if(val[p]<0){
						typ=4-typ;
						p=-val[p];
					}
					else
						p=val[p];
				}
				if(typ==pos[p]){
					++tim;
					while(vis[p]!=tim){
						vis[p]=tim;
						done[p]=pos[p];
						dfsset(p);
					}
				}
				else{
					++tim;
					while(vis[p]!=tim){
						vis[p]=tim;
						done[p]=2;
						dfsset(p);
					}
				}
			}
		}
		int ans=0;
		for(int i=1; i<=n; ++i)
			if(done[i]==2)
				++ans;
		printf("%d\n",ans);
	}
	return 0;
}