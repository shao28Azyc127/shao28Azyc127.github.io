#include <bits/stdc++.h>
using namespace std;
int read() {
	int ff = 0, x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') x ^= (ch == '-'), ch = getchar();
	while(ch >= '0' && ch <= '9') ff = ff * 10 + ch - 48, ch = getchar();
	return x ? -ff : ff;
}
int n, m, cas, ans, vis[100010];
char a[1000010];
string s[100010], b[100010];
map <string, int> mp;
struct input{
	char op; 
	int x, y;
}in[100010];
void dfs(int k) {
	if(k > n) {
		int cnt = 0;
		string str = "";
		for(int i = 1; i <= n; ++i) str += b[i];
		//cout << str << endl;
		if(mp[str]) return ;
		mp[str] = 1;
		for(int i = 1; i <= n; ++i) {
			if(b[i] == "U") a[i] = 'U';
			if(b[i] == "T") a[i] = 'T';
			if(b[i] == "F") a[i] = 'F';
		}
		for(int i = 1; i <= m; ++i) {
			if(isupper(in[i].op)) a[in[i].x] = in[i].op;
			else {
				if(in[i].op == '+') a[in[i].x] = a[in[i].y];
				else {
					if(a[in[i].y] == 'U') a[in[i].x] = 'U';
					else if(a[in[i].y] == 'F') a[in[i].x] = 'T';
					else a[in[i].x] = 'F';
			    }
			}
	    }
		for(int i = 1; i <= n; ++i) {
			//cout << a[i] << " ";
			int ag = 0;
			if(b[i] == "U") ++cnt;
			if(b[i] == "U" && a[i] == 'U') ag = 1;
			if(b[i] == "T" && a[i] == 'T') ag = 1;
			if(b[i] == "F" && a[i] == 'F') ag = 1;
			if(!ag) return ;
		}
		//cout << endl;
	    ans = min(ans, cnt);
	    return ;			
 	}
	b[k] = "U";
	dfs(k + 1);
	b[k] = "T";
	dfs(k + 1);
	b[k] = "F";
	dfs(k + 1);
}
void solve() {
	cin >> n >> m;
	if(cas <= 2) {
		for(int i = 1; i <= m; ++i) {
			cin >> in[i].op >> in[i].x;
			if(in[i].op == '+' || in[i].op == '-') cin >> in[i].y;
	    }
		mp.clear();
		ans = 1e9;
		dfs(1);
		cout << ans << endl;
    }else if(cas == 3 || cas == 4) {
		for(int i = 1, x; i <= m; ++i) {
			char op; cin >> op >> x;
			a[x] = op;
	    }
	    int cnt = 0;
		for(int i = 1; i <= n; ++i) if(a[i] == 'U') ++cnt;	
		cout << cnt << endl;
    }
		
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int T; cin >> cas >> T;
	while(T--) solve();
}
