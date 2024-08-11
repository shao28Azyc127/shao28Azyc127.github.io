#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int c, T, n, m, w[N], trn[N], h[N], ans;
int vis[N], id[N], ch[N], lf[N], flg[N];
int val(int x){
	if(x == 'T') return 2;
	if(x == 'F') return 3;
	if(x == 'U') return 4;
}
int op(int x){
	if(x < 2) return x^1;
	if(x == 2) return 3;
	if(x == 3) return 2;
	if(x == 4) return 4;
}
int fnd(int x){
	if(id[x] == x) return x;
	return fnd(id[x]);
}
void dfs(int x){//cout<<x<<" "<<fnd(x)<<endl;
	flg[x]=1;
	if(w[x]<2) w[x] ^= 1;
	if(!flg[ch[x]]) dfs(ch[x]);
	flg[x]=0;
}
int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int v, x, y, p, q;
	scanf("%d%d", &c, &T);
	while(T--){//cout<<T<<endl;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) id[i] = ch[i] = i;
		for(int i = 1; i <= m; i++){
			v = getchar();
			while(v!='T'&&v!='F'&&v!='U'&&v!='+'&&v!='-') v=getchar();
			if(v!='+'&&v!='-'){
				scanf("%d", &x);
				w[x] = val(v);//cout<<x<<" "<<x<<endl;
				if(w[x]==4) vis[x]=1;
				else vis[x]=0;
			}
			else if(v == '+'){
				scanf("%d%d", &x, &y);
				p = fnd(x), q = fnd(y);
				if(x==q && w[x]^w[y]) vis[x] = 1;
				else if(x^q) vis[x] = 0;
				if(p^q) id[x] = y, ch[y] = x;
				if(w[x]^w[y]) dfs(x);
				//cout<<x<<" "<<fnd(x)<<endl;
			}
			else if(v == '-'){
				scanf("%d%d", &x, &y);
				p = fnd(x), q = fnd(y);
				if(x==q && w[x]^op(w[y])) vis[x] = 1;
				else if(x^q) vis[x] = 0;
				if(p^q) id[x] = y, ch[y] = x;
				if(w[x]^op(w[y])) dfs(x);//cout<<x<<" "<<w[x]<<endl;
			}
		}
		for(int i = 1; i <= n; i++){//cout<<i<<" "<<fnd(i)<<endl;
			if(vis[fnd(i)] || w[i]==4 || w[fnd(i)]==4) ans++;}
		printf("%d\n", ans);
		ans = 0;
		memset(vis, 0, sizeof(vis));
		memset(w, 0, sizeof(w));
	}
	return 0;
}
/*
1 1
10 10
- 7 6
+ 4 1
+ 6 4
T 1
+ 2 9
- 9 10
U 10
+ 5 5
U 8
T 3

*/
