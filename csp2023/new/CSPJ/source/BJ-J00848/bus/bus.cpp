#include <iostream>
#include <algorithm>
using namespace std;

int n,m,k;
int map[10010][10010];
bool flag=false;
int bj[10010];
int ans=2000000000;
int asum=0;

void dfs(int time,int x){
	if(x==n){
//		cout<<time<<endl;
		if(time%k==0){
			ans=min(ans,time);
			flag=true;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(map[x][i]!=-1 && map[x][i]<=time && bj[i]!=1){
			bj[i]=1;
//			cout<<i<<endl;
			dfs(time+1,i);
			bj[i]=0;
		}
	}
	
}

int main(){

    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			map[i][j]=-1;
	for(int i=1;i<=m;i++){
		int u,v,a;
		cin>>u>>v>>a;
		map[u][v]=a;
		asum+=a;
	}
	for(int i=0;i<=asum;i+=3){
		dfs(i,1);
		if(flag==true){
			cout<<ans<<endl;
			return 0;
		}
	}
	if(!flag)
		cout<<-1<<endl;
	
    return 0;
}
