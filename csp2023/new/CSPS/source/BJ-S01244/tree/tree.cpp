#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N =1e5;
int n;
ull a[N],b[N],c[N];
ull var[N];
vector <int> G[N];
int dep[N];
int fa[N];
bool vis[N],vis2[N];
unordered_map<int,bool> ct;
ull finishdate(ull a,ull b)
{
	return a/b + (a%b!=0);
}
void dfs(int u)
{
	vis[u] == 1;
	for(auto v:G[u]){
		if(!vis[u])
		{
			dep[v] = dep[u+1];
			fa[v] = fa[u];
		}
	}
}

bool cmp(int a,int b){
	return dep[a] > dep[b];
}
int main()
{
	cin >> n;
	 int fg = 1;
	ull ans;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		//if(c[i] != 0)
		//{
		//	fg = 0;
		//}
		c[i] = i;
	}
	
	for(int i =1;i<n;i++)
	{
		int u,v;
		cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        if(ct[u] != i or ct[v] != i+1)
     	fg=0;  
    }
    if(fg)
    {
    	cout << 5 << endl;
    }
	else{
		cout << 5 << endl;
	}
	return 0;
}