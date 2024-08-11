#include<bits/stdc++.h>
using namespace std;
const int MX = 3e5 + 7;
vector<int > g[MX],scc[MX],r[MX];
int dfn[MX],low[MX],stk[MX],f[MX],col[MX],buc[MX],in[MX],cc = 0,top = 0,tot = 0;
bool instk[MX],uke[MX],bad[MX];
void dfs(int x){
	//cerr << "pos = " << x << '\n';
	low[x] = dfn[x] = ++tot;
	stk[++top] = x;
	instk[x] = true;
	for(int i = 0;i < g[x].size();i++){
		int to = g[x][i];
		if(!dfn[to]){
			dfs(to);
			low[x] = min(low[x],low[to]);
		}
		else if(instk[to])low[x] = min(low[x],dfn[to]);
	}
	if(low[x] == dfn[x]){
		cc++;
		while(stk[top] != x){
			col[stk[top]] = cc;
			scc[cc].push_back(stk[top]);
			instk[stk[top]] = false;
			top--;
		}
		scc[cc].push_back(stk[top]);
		col[stk[top]] = cc;
		instk[stk[top]] = false;
		top--;
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--){
		int n,m;
		cin >> n >> m;
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(stk,0,sizeof(stk));
		memset(f,0,sizeof(f));
		memset(col,0,sizeof(col));
		memset(in,0,sizeof(in));
		memset(instk,false,sizeof(instk));
		memset(uke,false,sizeof(uke));
		memset(bad,false,sizeof(bad));
		cc = top = tot = 0;
		for(int i = 1;i <= n;i++)f[i] = i;
		for(int i = 1;i <= m;i++){
			char opt;int x,y;
			cin >> opt;
			if(opt == '+'){
				cin >> x >> y;
				f[x] = f[y];
			}
			else if(opt == '-'){
				cin >> x >> y;
				f[x] = -f[y];
			}
			else{
				cin >> x;
				if(opt == 'T')f[x] = n + 1;
				else if(opt == 'F')f[x] = n + 2;
				else f[x] = n + 3;
			}
		}
		//cerr << "working\n";
		//cerr << "f = \n";
		//for(int i = 1;i <= n;i++)cerr << f[i] << ' ';
		//cerr << '\n';
		for(int i = 1;i <= n;i++){
			int fg = 1;
			if(f[i] < 0){
				fg = -1;
				f[i] *= -1;
			}
			if(f[i] <= n){
				if(fg == 1){
					g[f[i]].push_back(i);
					g[f[i] + n].push_back(i + n);
				}
				else{
					g[f[i] + n].push_back(i);
					g[f[i]].push_back(i + n);
				}
			}
			else{
				if(f[i] == n + 1){
					if(fg == 1){
						g[2 * n + 1].push_back(i);
						g[2 * n + 2].push_back(i + n);
					}
					else{
						g[2 * n + 2].push_back(i);
						g[2 * n + 1].push_back(i + n);
					}
				}
				else if(f[i] == n + 2){
					if(fg == 1){
						g[2 * n + 2].push_back(i);
						g[2 * n + 1].push_back(i + n);
					}
					else{
						g[2 * n + 1].push_back(i);
						g[2 * n + 2].push_back(i + n);
					}
				}
				else{
					g[2 * n + 3].push_back(i);
					g[2 * n + 3].push_back(i + n);
					uke[i] = true;
				}
			}
		}
		//cerr << "build done\n";
		for(int i = 1;i <= 2 * n + 3;i++){
			//cerr << "st " << i << '\n';
			if(!dfn[i])dfs(i);
			//cerr << "ed " << i << '\n';
		}
		//cerr << "tarjan done\n";
		for(int i = 1;i <= cc;i++){
			if(scc[i][0] > 2 * n){
				if(scc[i][0] == 2 * n + 3)bad[i] = true;
				continue;
			}
			//cerr << "st " << i << '\n';
			for(auto j : scc[i])buc[j]++;
			bool flag = false;
			for(auto j : scc[i])
				if((j <= n && buc[j + n]) || uke[j])flag = true;
			if(flag)bad[i] = true;
			for(auto j : scc[i])buc[j]--;
			//cerr << "ed " << i << '\n';
		}
		//cerr << "start top sort\n";
		for(int i = 1;i <= 2 * n + 3;i++)
			for(auto to : g[i])
				if(col[to] != col[i])r[col[i]].push_back(col[to]),in[col[to]]++;
		queue<int > q;
		for(int i = 1;i <= cc;i++)
			if(in[i] == 0)q.push(i);
		while(!q.empty()){
			int x = q.front();
			q.pop();
			for(auto to : r[x]){
				if(bad[x] && !bad[to])bad[to] = true;
				in[to]--;
				if(in[to] == 0)q.push(to);
			}
		}
		for(int i = 1;i <= cc;i++){
			if(scc[i][0] > 2 * n)continue;
			if(bad[i]){
				for(auto j : scc[i])uke[j] = true;
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++)
			if(uke[i])ans++;
		cout << ans << '\n';
		for(int i = 1;i <= n * 2 + 3;i++){
			g[i].clear();
			r[i].clear();
			scc[i].clear();
		}
		//cerr << n * 2 + 3 << " ok\n";
	}
}