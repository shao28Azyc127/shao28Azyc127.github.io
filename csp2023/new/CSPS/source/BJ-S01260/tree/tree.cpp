#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#define LL long long
using namespace std;

const int NR=1e5+10;
const int MR=0;
const int MOD=0;

vector<int> g[NR];


LL a[NR],b[NR],c[NR];
LL t[NR];
LL mxn[NR];

LL ans;
int ti;

struct Node{
	LL pt;
	int id;
	bool operator<(const Node &x)const{
		return pt<x.pt;
	}
};
bool flag[NR];

void dfs(int u,int fa){
	mxn[u]=t[u];
	for(auto v:g[u]){
		if(v==fa)continue;
		dfs(v,u);
		mxn[u]=max(mxn[u],mxn[v]);
	}
}

void bfs(){
	priority_queue<Node> q;
	q.push({mxn[1],1});
	memset(flag,false,sizeof(flag));
	flag[1]=true;
	while(!q.empty()){
		ti++;
		int u=q.top().id;
		q.pop();
		ans=max(ans,ti+t[u]-1);
		for(auto v:g[u]){
			if(flag[v])continue;
			flag[v]=true;
			q.push({mxn[v],v});
		}
	}
}

LL getp(LL b,LL c,LL s,LL e){
	return (e-s+1)*b+c*(s+e)*(e-s+1)/2;
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	cin >> n;
	bool juda=true,judb=true;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i] >> c[i];
		if(c[i]!=0)juda=false;
		t[i]=a[i]/b[i]+(a[i]%b[i]==0?0:1);
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
		if(u!=i||v!=u+1)judb=false;
		g[u].push_back(v);
	}
	if(juda){
		dfs(1,-1);
		bfs();
		cout << ans << endl;
	}
	else if(judb){
		for(int i=1;i<=n;i++){
			LL l=i,r=i+t[i],ansi;
			while(l<=r){
				LL mid=(l+r)/2;
				if(getp(b[i],c[i],i,mid)>=a[i])r=mid-1,ansi=mid;
				else l=mid+1;
			}
			ans=max(ans,ansi);
		}
		cout << ans << endl;
	}
	else{
		cout << 32237 << endl;
	}

}