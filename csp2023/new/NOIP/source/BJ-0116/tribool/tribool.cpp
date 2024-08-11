#include <bits/stdc++.h>
using namespace std;
typedef pair<int, bool> pib;
const int N = 1e5+5;
int n, m;

/*
struct node{
	bool type;
	bool op; int id; // type == 0
	char c;			 // type == 1
}a[N];
*/

char val[N];
int idx[N];

vector<pib> g[N]; // b==0: same val     b==1: different val
bool mark[N];
int visval[N];
int validx;
int cnt = 0;

void dfs1(int idx){
	if(mark[idx]) return;
	cnt++;
	mark[idx] = 1;
	if(val[idx]) validx = idx;
	for(int i=0;i<g[idx].size();i++){
		int x = g[idx][i].first;
		dfs1(x);
	}
}

bool dfs2(int idx, int v){
	bool ret = 1;
	if(visval[idx]){
		if(visval[idx]!=v) return 0;
		return 1;
	}
	visval[idx] = v;
	for(int i=0;i<g[idx].size();i++){
		pib x = g[idx][i];
		if(x.second==1)
			ret &= dfs2(x.first, -v);
		else
			ret &= dfs2(x.first, v);
	}
	return ret;
}

char ob(char c){
	if(c=='F') return 'T';
	if(c=='T') return 'F';
	else return 'U';
}

int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	
	int c, t;
	
	cin >> c >> t;
	while(t--){
		int ans = 0;
		memset(idx, 0, sizeof(idx));
		memset(val, 0, sizeof(val));
		memset(mark, 0, sizeof(mark));
		memset(visval, 0, sizeof(visval));
		for(int i=0;i<N;i++) g[i].clear();
		cin >> n >> m;
		for(int i=1;i<=n;i++) idx[i] = i;
		for(int i=0;i<m;i++){
			char op;
			cin >> op;
			if(op=='+'){
				int x, y;
				cin >> x >> y;
				if(val[y]){
					val[x] = val[y];
					idx[x] = 0;
				}
				else{
					idx[x] = idx[y];
					val[x] = 0;
				}
			}
			else if(op=='-'){
				int x, y;
				cin >> x >> y;
				if(val[y]){
					val[x] = ob(val[y]);
					idx[x] = 0;
				}
				else{
					idx[x] = -idx[y];
					val[x] = 0;
				}
			}
			else{
				int x;
				cin >> x;
				val[x] = op;
				idx[x] = 0;
			}
		}
		for(int i=1;i<=n;i++){
			if(idx[i]){
				int t = abs(idx[i]);
				bool b = (idx[i]<0);
				g[t].push_back(pib(i, b));
				g[i].push_back(pib(t, b));
			}
		}
/*		for(int i=1;i<=n;i++){
			for(int j=0;j<g[i].size();j++){
				cout << g[i][j].first << ' ' << g[i][j].second << ' ';
			}
			cout << endl;
		}
		*/
		for(int i=1;i<=n;i++){
			if(!mark[i]){
				validx = 0, cnt = 0;
				dfs1(i);
				if(validx){
					if(val[validx]=='U') ans += cnt;
					continue;
				}
				if(!dfs2(i, 1)){
					ans += cnt;
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
