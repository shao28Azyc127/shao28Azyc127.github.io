#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}d[100010];
int e[10000][10001];
int vis[100000];
int n, cnt = 1000000000;
void dfs(int day , int h,int xian){
	if(xian == 0){
		vis[1] = d[1].b;
		dfs(day + 1,1,1);
	if(h == n){
		int p = 0;	
		for(int i = 1; i <= n; i++){
			while(vis[i] + (day + p) * d[i].b < d[i].a) p++; 
		}
		cnt = min(cnt,day + p);
	}
	}else{
		for(int i = 1;i < n; i++){
			if(e[xian][i] == 1 && vis[i] == 0){
				vis[i] = d[i].b;
				dfs(day + 1,h + 1,i);
				vis[i] = 0;
			}
		}
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> d[i].a >> d[i].b >> d[i].c;
	}
	for(int i = 1; i < n; i++){
		int u,v;
		cin >> u >> v;
		e[u][v] = 1;
		e[v][u] = 1;
	}
	dfs(1,0,0);
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
