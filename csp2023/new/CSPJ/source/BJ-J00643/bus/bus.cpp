#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n,m,k,u,v,w,f[10005][105],V,l,r,mid;
vector<pair<int,int> > G[10005];
priority_queue<pair<int,pair<int,int> > > q;
int check(int x){
	memset(f,-1,sizeof(f));
	f[n][0]=x;
	q.push({x,{n,0}});
	while(!q.empty()){
		int curx=q.top().second.first,cury=q.top().second.second;
		q.pop();
		if(curx==1&&cury==0){
			return 1;
		}
		for(int i=0;i<G[curx].size();i++){
			if(f[curx][cury]>G[curx][i].second){
				int to=G[curx][i].first;
				if(f[to][(cury+1)%k]<f[curx][cury]-1){
					f[to][(cury+1)%k]=f[curx][cury]-1;
					q.push({f[to][(cury+1)%k],{to,(cury+1)%k}});
				}
			}
		}
	}
	return 0;
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		G[v].push_back({u,w});
		V=max(V,w+m);
	}
	l=0,r=V/k;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid*k)){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	if(!check(l*k)){
		cout<<-1;
		return 0;
	}
	cout<<l*k;
	return 0;
}
