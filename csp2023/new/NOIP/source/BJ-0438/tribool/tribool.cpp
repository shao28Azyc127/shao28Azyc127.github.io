#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a;i<=b;i++)
#define cls(u) memset(u,0,sizeof u)
bool flag = 0;
int n,m;
int need[100010];
bool vis[100010];
void taskA(){
	cls(need);
	//only TFU
	scanf("%d%d",&n,&m);
	int x,ans=0;char o;
	rep(i,1,m){
		cin>>o>>x;
		if(o=='T') need[x] = 1;
		else if(o=='F') need[x] = 0;
		else if(o=='U') need[x] = 3;
	}
	rep(i,1,m){if(need[i]==3) ans++;}
	printf("%d\n",ans);

}

vector<int> h[100010],f[100010];
set<int> uk;

bool check(int u,int v){
	for(int i:f[v]) if(i==u) return true;
	return false;
}

bool uuk[100010];
void dfs(int u){
	vis[u] = 1;
	uk.insert(u);
	for(int i:h[u])
		if(!vis[i]&&check(u,i)) dfs(i);

}

void dfs2(int u){
	vis[u] = 1;
	if(uk.find(u)!=uk.end()) uk.erase(uk.find(u));
	for(int i:h[u])
		if(!vis[i]&&check(u,i)) dfs2(i);

}

void taskB(){
	cls(vis);cls(uuk);uk.clear();
	scanf("%d%d", &n, &m);
	rep(i,1,n) h[i].clear();
	rep(i,1,n) f[i].clear();
	int x,y;char o;
	rep(i,1,m){
		cin>>o;
		if(o=='+'){
			cin>>x>>y;
			h[y].push_back(x);
			f[x].push_back(y);
		}
		if(o=='U'){
			cin>>x;
			uuk[x] = 1;
			uk.insert(x);
			f[x].clear();
		}
	}
	for(int i:uk) dfs(i);
	cls(vis);
	rep(i,1,n) if(!uuk[i]) dfs2(i); 
	printf("%d\n",uk.size());
}

int main(){
	freopen("tribool3.in","r",stdin);
	freopen("tribool.out","w",stdout);

	int c,T;
	scanf("%d%d", &c, &T);
	if(c==2||c==3) while(T--) taskA();
	else if(c==4||c==5) while(T--) taskB();
	return 0;
}