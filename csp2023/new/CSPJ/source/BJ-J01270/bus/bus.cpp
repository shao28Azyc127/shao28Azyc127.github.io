#include<bits/stdc++.h>
using namespace std;
int d,ans,cnt = 10000000;
int n,m,k;
int l[1001][1001];
bool vis[1001][1001];
void dfs(int step,int t){
	if(step == n){
		ans = min(ans,t);
		return;
	}
	for(int i = 1; i <= n; i++){
		if(l[step][i] == 1 && vis[step][i] == 0){
			vis[step][i] = 1 ;
			dfs(i,t + 1);
			vis[step][i] = 0;
		}
	}
}
struct node{
	int a,u,v;
}b[100100];
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> b[i].u >> b[i].v >> b[i].a;
		l[b[i].u][b[i].v] = 1;
		if(b[i].a != 0){
			cout << -1;
			return 0;
		}
	}
	dfs(1,0);
	if(ans ==10000000) cout << -1;
	else cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
