#include<bits/stdc++.h>
using namespace std;
int n,m,q,x,y,z,a[10005][10005],minn=2e9;
void dfs(int s,int t,int maxx){
	if(s==n){
		minn=min((maxx+q-1)/q*q,minn);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(a[s][i]){
			dfs(i,t+1,max(maxx,a[s][i]-t));
		}
	}
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		a[x][y]=z;
	}
	dfs(1,0,0);
	if(minn==2e9)	cout<<-1;
	else
	{
		cout<<minn;
	}
}
