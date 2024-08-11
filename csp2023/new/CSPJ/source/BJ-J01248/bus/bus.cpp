#include<bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

int ans = 1e9;

int n, m, K;

struct node{
    int v;
    long long w;
};

bool vis[N];

vector<node> e[N];

void dfs(int k, int len){
	if(len > ans)return ;
    if(k == n){
        if(len % K == 0)ans = min(ans, len);
        return ;
    }
    for(auto i : e[k]){
        if(!vis[i.v]){ 
            vis[i.v] = true;
            if(len >= i.w)dfs(i.v, len + 1);
            vis[i.v] = false;
        }
    }
}

int main(){
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
    cin >> n >> m >> K;
    long long maxn = 0;
    for(int i = 1; i <= m; i++){
        int x, y;
        long long z; 
        
        scanf("%d%d%lld", &x, &y, &z);maxn = max(maxn, z);
        e[x].push_back({y, z});
    }
    //cout << maxn << endl;
    for(int len = 0; len <= maxn; len += K){
		//cout << len << endl;
		memset(vis, 0, sizeof vis);
		vis[1] = true;
		dfs(1, len);
	}
	if(ans != 1e9)cout << ans << endl;
    else cout << -1;
    return 0;  
}
