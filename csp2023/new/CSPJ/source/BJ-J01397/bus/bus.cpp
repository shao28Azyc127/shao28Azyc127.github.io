#include<bits/stdc++.h>
using namespace std;
struct road{
	int u=0,v=0,a=0;
}r[20004];
int minn=INT_MAX;
int n,m,k;
bool vis[20004];
void dfs(int x,int t){
	if(x==n){
		if(t+(k-t%k)<minn){
			minn=t+(k-t%k);
		}
	}
	for(int i=0;i<m;i++){
		if(r[i].u==x&&t>=r[i].a&&vis[i]==0){
			vis[i]=1;
			cout << r[i].v<<endl;
			dfs(r[i].v,t+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=0;i<m;i++){
		cin >> r[i].u >> r[i].v >> r[i].a;
	}
	dfs(1,k);
	if(minn==INT_MAX){
		cout << -1;
	}else{
		cout << minn;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
