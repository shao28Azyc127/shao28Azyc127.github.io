#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5,M=1e5+5;
struct qry{
	char op;int x,y;
};
int n, Q;
vector<qry> q;
struct A{
	int res,ucnt,a[11],b[11];
	int rev(int x){
		return x==2?x:!x;
	}
	void dfs(int k){
		if(ucnt>=res)return ;
		if(k==n+1){
			for(int i=1;i<=n;++i)b[i]=a[i];
			for(int i=0;i<Q;++i){
				char op=q[i].op;int x=q[i].x,y=q[i].y;
				if(op=='T')b[x]=0;
				if(op=='F')b[x]=1;
				if(op=='U')b[x]=2;
				if(op=='+')b[x]=b[y];
				if(op=='-')b[x]=rev(b[y]);
			}
			bool flg=1;
			for(int i=1;i<=n;++i){
				if(b[i]^a[i]){flg=0;break;}
			}
			if(flg==1)res=ucnt;
			return ;
		}
		for(int i=0;i<3;++i){
			a[k]=i;
			ucnt+=(i==2);
			dfs(k+1);
			a[k]=0;
			ucnt-=(i==2);
		}
	}
	void solve(){
		res=1e9;
		dfs(1);
		cout<<res<<'\n';
	}
}Sol1;
struct B{
    char ans[N];
    void solve(){
        for(int i=0;i<Q;++i){
            ans[q[i].x]=q[i].op;
        }
        int res=0;
        for(int i=1;i<=n;++i)res+=ans[i]=='U';
        cout<<res<<'\n';
    }
}Sol2;
int fa[N<<1];
bool isu[N<<1];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
//inline bool chku(int x){
  //  if(isu[x])return 1;
    //if(fa[x]==x)return 0;
    //return chku)
//}
inline void merge(int x,int y){
    x=find(x),y=find(y);
    if(x^y)fa[y]=x;
}
bool vis[N];
struct C{
    void solve(){
        for(int i=1;i<=n;++i)fa[i]=i,isu[i]=vis[i]=0;
        for(int i=Q-1;i>=0;--i){
            char op=q[i].op;int x=q[i].x,y=q[i].y;
            if(op=='U'){
                if(!vis[x])isu[find(x)]=1,vis[x]=1;
            }else{
                merge(x,y);
            }
        }
        int res=0;
        for(int i=1;i<=n;++i)res+=isu[find(i)];
        cout<<res<<'\n';
    }
}Sol3;
struct D{
    void solve(){
    	for(int i=(1<<1);i<=(n<<1|1);++i)fa[i]=i,isu[i]=0;
        for(int i=Q-1;i>=0;--i){
        	char op=q[i].op;int x=q[i].x,y=q[i].y;
        	if(op=='+')merge(y<<1,x<<1);
        	else merge(y<<1|1,x<<1);
        }
        for(int i=1;i<=n;++i){
        	int p=find(i<<1),q=find(i<<1|1);
        	if(p==q)isu[p]=1;
        }
        int res=0;
        for(int i=1;i<=n;++i)res+=isu[find(i<<1)];
        cout<<res<<'\n';
    }
}Sol4;
signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int c,T;cin>>c>>T;
	while(T--){
        q.clear();
        cin>>n>>Q;
        bool flg1=1,flg2=1,flg3=1;
        for(int i=1;i<=Q;++i){
            char op;int x,y;cin>>op>>x;
            if(op=='T'||op=='F'||op=='U')q.push_back({op,x});
            else cin>>y,q.push_back({op,x,y}),flg1=0;
            flg2&=(op=='U'||op=='+');
            flg3&=(op=='+'||op=='-');
        }
        if(n<=10)Sol1.solve();
        else if(flg1)Sol2.solve();
        else if(flg2)Sol3.solve();
        else if(flg3)Sol4.solve();
        else{
            cout<<0<<'\n';
        }
	}
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, M = 3e5 + 5;
struct edge {
	int v, nxt;
} e[M];
int head[N], cnt;
void prt(int x) {
    cout << x / 3 + 1 << ' ';
    if (x % 3 == 0) cout << 'T';
    else if (x % 3 == 1) cout << 'F';
    else cout << 'U';
}
inline void Add(int u, int v) {
	e[++cnt] = {v, head[u]}, head[u] = cnt;
}
inline void add(int u, int v) {
    cout << "add: "; prt(u); cout << ' '; prt(v); cout << '\n';
    Add(u, v), Add(v, u);
}
int dfn[N], low[N], times;
int scc[N], scc_cnt;
int S[N], tp = 0;
vector<int> Scc[N];
bool okscc[N];
int usum[N], Usum;
char num[N];
void dfs(int u) {
    //int ccnt = 0;
    //for (int i = head[u]; i; i = e[i].nxt) ++ccnt;
    //if (!ccnt) return ;
	dfn[u] = low[u] = ++times;
	S[++tp] = u;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (!dfn[v]) dfs(v), low[u] = min(low[u], low[v]);
		else if (!scc[v]) low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u] && !scc[u]) {
        set<int> s;
		++scc_cnt;
		//okscc[scc_cnt] = 1;
		usum[scc_cnt] = Usum;
		bool flg = 1;
		cout << "new scc: \n";
		bool tt = 0;
		while (1) {
			int v = S[tp--];
			scc[v] = scc_cnt;
			if (flg && s.count(v / 3)) cout << "doubled " << v / 3 + 1 << '\n';
            if (flg && s.count(v / 3)) flg = 0;
            s.insert(v / 3);
			Scc[scc_cnt].push_back(v);
			//usum[scc_cnt] -= num[v / 3] == 'U';
			tt |= (num[v / 3 + 1] == 'U' && v % 3 == 2);
			//if (num[v / 3 + 1] == 'U' && v % 3 == 2) cout << "catched: ", prt(v), cout << '\n';
			prt(v); cout << '\n';
			if (v == u) break;
		}
		cout << '\n';
		if (tt) {
            for (int x : Scc[scc_cnt]) scc[x] = -scc_cnt;
		}
		if (!flg) {
            for (int x : Scc[scc_cnt]) scc[x] = 1e9;
		}
	}
}
inline int g(int x, int op) {
    return 3 * (x - 1) + op;
}
signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("tribool.in", "r", stdin);
	//freopen(".out", "w", stdout);
	int c, T; cin >> c >> T;
	while (T--) {
		memset(dfn, 0, sizeof dfn), memset(low, 0, sizeof low), times = 0;
		memset(scc, 0, sizeof scc), scc_cnt = 0;
		memset(head, 0, sizeof head), cnt = 0;
		memset(usum, 0, sizeof usum), Usum = 0;
        tp = 0;
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; ++i) num[i] = '#';
		while (m--) {
			char v; int x, y; cin >> v >> x;
			if (v == 'T' || v == 'F' || v == 'U') num[x] = v;
			else {
				cin >> y;
				if (v == '+' && x == y) continue;
				if (v == '-' && x == y) { num[x] = 'U'; continue; }
				if (v == '+') {
					for (int j = 0; j < 3; ++j) add(g(x, j), g(y, j));
				} else {
					add(g(x, 0), g(y, 1)), add(g(x, 1), g(y, 0)), add(g(x, 2), g(y, 2));
				}
			}
		}
		// for (int i = 1; i <= n; ++i) {
  //           if (num[i] == '#') continue;
  //           if (num[i] == 'T') add(g(i, 1), g(i, 2));
  //           else if (num[i] == 'F') add(g(i, 0), g(i, 2));
  //           else if (num[i] == 'U') add(g(i, 0), g(i, 1)), ++Usum;
  //           //cout << "num: " << i << ' ' <<  num[i] << '\n';
		// }
		for (int i = 1; i <= n; ++i) {
            //if (num[i] == '#') cout << i << " skipped\n";
            if (num[i] == '#') continue;
            for (int j = 0; j < 3; ++j) dfn[g(i, j)] = scc[g(i, j)] = 1e9;
            int t = 0;
            if (num[i] == 'F') t = 1;
            if (num[i] == 'U') t = 2;
            int tt = g(i, t); dfn[tt] = scc[tt] = 0;
            //cout << "num: " << i << ' ' << num[i] << '\n';
		}
		for (int i = g(1, 0); i <= g(n, 2); ++i) {
            if (dfn[i] == 0) dfs(i);
		}
		int res = 0;
		for (int i = 1; i <= n; ++i) {
            cout << i << ": " << scc[g(i, 0)] << ' ' << scc[g(i, 1)] << ' ' << scc[g(i, 2)] << '\n';
			res += (scc[g(i, 2)] < min(scc[g(i, 0)], scc[g(i, 1)]));
		}
		// int res = 1e9;
		// for (int i = 1; i <= scc_cnt; ++i) {
  //           //if (!okscc[i]) continue;
  //           int ans = 0;
  //           for (int j : Scc[i]) ans += (j % 3 == 2);
  //           ans += usum[i];
  //           res = min(res, ans);
		// }
		cout << res << '\n';
	}
	return 0;
}
*/
