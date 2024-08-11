#include <bits/stdc++.h>
using namespace std;
long long cnt = -1;
string dizhi[1000005];
long long n, mn = 1e18;
struct node{
	long long kx;
	string lx[105], mc[105];
	long long bigs[105];
	long long mx = 0, su = 0;
};
map<string, node> mp;
map<string, long long> mp2;
void dfs(string u, long long jiange, string le){
	if (mp.count(u)){
		for (long long i = 1; i <= mp[u].kx; i++){
			string p = le;
			p += '.';
			for (long long j = 0; j < (long long)(mp[u].mc[i].size()); j++){
				p += mp[u].mc[i][j];
			}
			dfs(mp[u].lx[i], mp[u].mx, p);
		}
	}else{
		long long idx = 0;
		if (u == "byte"){
			idx = 1;
		}
		if (u == "short"){
			idx = 2;
		}
		if (u == "int"){
			idx = 4;
		}
		if (u == "long"){
			idx = 8;
		}
		for (long long i = 1; i <= jiange; i++){
			if (i <= idx){
				dizhi[++cnt] = le;
				if (i == 1){
					mp2[le] = cnt;
				}
			}else{
				dizhi[++cnt] = "";
			}
			mn = min(mn, cnt);
		} 
	}
	return ;
}
int main(){
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	scanf("%lld", &n);
	mp.clear();
	mp2.clear();
	for (long long i = 1; i <= n; i++){
		long long opt;
		scanf("%lld", &opt);
		if (opt == 1){
			string s;
			long long k;
			cin >> s >> k;
			node q;
			q.kx = k;
			for (long long j = 1; j <= k; j++){
				string st, st2;
				cin >> st >> st2;
				q.mc[j] = st2;
				q.lx[j] = st;
				if (st == "long"){
					q.bigs[j] = 8;
				}else if (st == "int"){
					q.bigs[j] = 4;
				}else if (st == "short"){
					q.bigs[j] = 2;
				}else if (st == "byte"){
					q.bigs[j] = 1;
				}else{
					q.bigs[j] = mp[st].mx;
				}
				q.mx = max(q.mx, q.bigs[j]);
				q.su += q.bigs[j];
			}
			q.su = q.mx * k;
			mp[s] = q;
			printf("%lld %lld\n", q.su, q.mx);
		}else if (opt == 2){
			string t, n1;
			cin >> t >> n1;
			mn = 1e18;
			if (mp.count(t)){
				string s1 = n1;
				dfs(t, mp[t].mx, s1);
			}else{
				long long idx = 0;
				if (t == "byte"){
					idx = 1;
				}
				if (t == "short"){
					idx = 2;
				}
				if (t == "int"){
					idx = 4;
				}
				if (t == "long"){
					idx = 8;
				}
				dfs(t, idx, n1);
			}
			printf("%lld\n", mn);
		}else if (opt == 3){
			string s;
			cin >> s;
			printf("%lld\n", mp2[s]);
		}else{
			long long x;
			scanf("%lld", &x);
			if (x > cnt){
				printf("ERR\n");
			}else{
				if (dizhi[x] == ""){
					printf("ERR\n");
				}else{
					cout << dizhi[x] << endl;
				}
			}
		}
	}
	return 0;
}
