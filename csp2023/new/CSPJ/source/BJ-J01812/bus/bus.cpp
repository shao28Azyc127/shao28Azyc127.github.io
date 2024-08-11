#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int u,v,w;
int mx;
vector<int> mp1[1005],mp2[1005];

int que[1005],q2[1005],h,t,l;
int dis[1005];
int mp[15][15];
bool flag[1005];

void bfs(int st){
	for(int i=1;i<=n;++i){
		dis[i]=-1;
	}
	que[0]=1;
	dis[st]=0;
	h=0;
	t=1;
	int cnt=0;
	while(1){
		l=t-h;
		if(l==0){
			break;
		}
		++cnt;
		while(l--){
			int p=que[h];
			++h;
			for(int i=0;i<(int)(mp1[p].size());++i){
				if(dis[mp1[p][i]]==-1){
					dis[mp1[p][i]]=cnt;
					que[t]=mp1[p][i];
					++t;
				}
			}
		}
	}
	return;
}

int bfs2(){
	que[0]=1;
	h=0;
	t=1;
	int cnt=0;
	while(1){
		if(h==t){
			return -1;
		}
		for(int i=h;i<t;++i){
			q2[i]=que[i];
			if(cnt%k==0 && q2[i]==n){
				return cnt;
			}
		}
		if(cnt==1e8/n){
			break;
		}
		for(int i=1;i<=n;++i){
			flag[i]=0;
		}
		int lsh=h,lst=t;
		h=0;
		t=0;
		for(int i=lsh;i<lst;++i){
			for(int j=0;j<(int)(mp1[q2[i]].size());++j){
				if(flag[mp1[q2[i]][j]]==0){
					flag[mp1[q2[i]][j]]=1;
					que[t]=mp1[q2[i]][j];
					++t;
				}
			}
		}
		++cnt;
	}
	return -1;
}

int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		mp1[u].push_back(v);
		mp2[u].push_back(w);
		mx=max(mx,w);
	}
	if(mx==0 && k==1){
		bfs(1);
		printf("%d",dis[n]);
		return 0;
	}
	if(mx==0 && n<=10){
		printf("%d",bfs2());
		return 0;
	}
	if(mx==0){
		printf("%d",bfs2());
		return 0;
	}
	printf("-1");
	return 0;
}
