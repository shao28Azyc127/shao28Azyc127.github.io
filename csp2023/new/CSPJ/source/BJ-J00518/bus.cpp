#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
vector<int>g[N];
int dis[N],g2[15][15],n,m,k,minans=0x3f3f3f3f;
bool v[N];
void dfs(int u,int e,int s){
	if(e==n&&s%k==0)minans=min(minans,s);
	for(int f=1;f<=n;++f){
		if(g2[e][f]==-1||u==f)continue;
		if(g2[e][f]<=dis[u])dfs(e,f,s+1);
	}
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int s=0,i;
	scanf("%d%d%d",&n,&m,&k);
	memset(dis,0x3f,sizeof(dis));
	if(k==1){
		while(m--){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			g[x].push_back(y);
		}
		dis[1]=1;
		v[1]=1;
		s++;
		while(s!=0){
			int mind=0x3f3f3f3f,minid=0;
			for(i=1;i<=n;++i){
				if(dis[i]<mind&&v[i]){
					mind=dis[i];
					minid=i;
				}
			}
			v[minid]=0;
			s--;
			for(auto e:g[minid]){
				if(dis[e]>dis[minid]+1){
					v[e]=1;
					s++;
					dis[e]=dis[minid]+1;
				}
			}
		}
		if(dis[n]==0x3f3f3f3f){
			printf("%d",-1);
			return 0;
		}
		printf("%d",dis[n]);
	}
	else if(n<=10){
		memset(g2,-1,sizeof(g2));
		while(m--){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			g2[x][y]=z;
		}
		dfs(0,1,k);
		if(minans==0x3f3f3f3f)printf("%d",-1);
		else printf("%d",minans);
	}
	else printf("%d",-1);
	return 0;
}
/*
12 14 1
1 2 0
1 3 0
2 4 0
3 5 0
4 5 0
5 6 0
4 7 0
6 7 0
7 8 0
8 9 0
9 11 0
11 8 0
8 10 0
11 12 0*/
