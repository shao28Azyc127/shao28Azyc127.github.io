#include <bits/stdc++.h>

using namespace std;

struct block{
    int a,b,c;
} b[100005];

vector<int> v[100005];

bool vis[100005];

int ans;
int n;

void dfs(int now,int t,int maxn){
    if(t==n){
        ans=min(maxn,ans);
        return;
    }
    if(vis[now]){
        return;
    }
    vis[now]=true;
    for(int i=0;i<=v[now].size();i++){
        int to=v[now][i];
        maxn=max(maxn,t+1+b[to].a/b[to].b+(b[to].a%b[to].b));
        dfs(to,t+1,maxn);
    }
    vis[now]=false;
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
        cin>>b[i].a>>b[i].b>>b[i].c;
	}
	for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
	}
	ans=0x3f3f3f;
	dfs(1,1,b[1].a/b[1].b+(b[1].a%b[1].b));
	cout<<ans<<endl;
	return 0;
}
