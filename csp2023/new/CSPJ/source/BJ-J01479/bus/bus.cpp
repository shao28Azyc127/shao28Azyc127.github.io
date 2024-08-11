#include <bits/stdc++.h>
using namespace std;
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
vector<pair<int,int> > mp[10010];
int dis[10010][110];
bool vis[10010];
signed main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	int cnt=0,cnt2=0,maxc=0;
	fr(i,1,m){
		int a,b,c;
		cin >> a >> b >> c;
		mp[a].push_back({b,c});
		cnt+=c;
		cnt2+=a<b;
		maxc=max(maxc,c);
	}
	if(cnt==0){
		queue<pair<int,pair<int,int> > > q;
		memset(dis,0x3f,sizeof dis);
		dis[1][0]=0;
		q.push({1,{0,0}});
		while(!q.empty()){
			int p=q.front().first,mod=q.front().second.first,d=q.front().second.second;
			q.pop();
			vis[p]=0;
			for(auto t:mp[p]){
				int x=t.first;
				int tmp=(mod+1)%k;
				if(dis[x][tmp]>d+1){
					dis[x][tmp]=d+1;
					if(vis[x])continue;
					vis[x]=1;
					q.push({x,{tmp,d+1}});
				}
			}
		}
		if(dis[0][0]==dis[n][0])cout << -1;
		else cout << dis[n][0];
		
	}
	else if(cnt2==m){
		queue<pair<int,pair<int,int> > > q;
		memset(dis,0x3f,sizeof dis);
		dis[1][0]=0;
		q.push({1,{0,0}});
		while(!q.empty()){
			int p=q.front().first,mod=q.front().second.first,d=q.front().second.second;
			q.pop();
			vis[p]=0;
			for(auto t:mp[p]){
				int x=t.first,nd=t.second;
				if(nd>d)continue;
				int tmp=(mod+1)%k;
				if(dis[x][tmp]>d+1){
					dis[x][tmp]=d+1;
					if(vis[x])continue;
					vis[x]=1;
					q.push({x,{tmp,d+1}});
				}
			}
		}
		if(dis[0][0]==dis[n][0]){
			int buff=k;
			while(1){
				fr(p,1,n){
					fr(mod,0,k-1){
						int d=dis[p][mod];
						for(auto t:mp[p]){
							int x=t.first,nd=t.second;
							if(nd>d+buff)continue;
							int tmp=(mod+1)%k;
							if(dis[x][tmp]>d+1){
								dis[x][tmp]=d+1;
								if(vis[x])continue;
								vis[x]=1;
								q.push({x,{tmp,d+1}});
							}
						}
					}
				}
				
				while(!q.empty()){
					int p=q.front().first,mod=q.front().second.first,d=q.front().second.second;
					q.pop();
					vis[p]=0;
					for(auto t:mp[p]){
						int x=t.first,nd=t.second;
						if(nd>d+buff)continue;
						int tmp=(mod+1)%k;
						if(dis[x][tmp]>d+1){
							dis[x][tmp]=d+1;
							if(vis[x])continue;
							vis[x]=1;
							q.push({x,{tmp,d+1}});
						}
					}
				}
				if(dis[0][0]!=dis[n][0]){
					cout << dis[n][0]+buff;
					break;
				}
				if(buff>maxc){
					cout << -1;
					return 0;
				}
				buff+=k;
				
			}
			
		}
		else
			cout << dis[n][0];
	}
	else{
		cout << -1;
	}
	return 0;
}
