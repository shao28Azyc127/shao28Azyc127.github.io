#include<bits/stdc++.h>
using namespace std;
int n,m,k,jl[20010],ans=INT_MAX;
struct node{
	int to,sa;
};
vector<node> e[10010];
int mp[10000010];
void pao(int tm){
	queue<node> q;
	q.push(node{1,tm});
	while(!q.empty()){
		node x=q.front();q.pop();
		if(x.to==n&&x.sa%k==0){
			ans=min(ans,x.sa);
			return ;
		}
		for(int i=0;i<e[x.to].size();++i){
			node y=e[x.to][i];
			if(y.sa>x.sa) continue;
			q.push(node{y.to,x.sa+1});
		}
	}
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin>>x>>y>>z,jl[i]=z;
		e[x].push_back(node{y,z});
	}
	for(int i=1;i<=m;++i)
		if(!mp[jl[i]/k*k]) pao(jl[i]/k*k),mp[jl[i]/k*k]=1;
	cout<<ans;
	return 0;
}