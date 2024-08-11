// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 115
int n, tpi, memi;
long long addri;

struct tp {
	string id, na[N];
	long long addrd[N], addrs;
	int t[N], fx;
};
tp tps[N];

inline int tad(string c) {
	for (int i=1;i<=tpi;i++) {
		if (tps[i].id == c) {
			return i;
		}
	}
	return 0;
}

struct mem {
	string id;
	int t;
	long long addr;
};
mem memo[N];

int main() {
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	tps[++tpi].id = "byte";
	tps[tpi].addrs = tps[tpi].fx = 1;
	tps[++tpi].id = "short";
	tps[tpi].addrs = tps[tpi].fx = 2;
	tps[++tpi].id = "int";
	tps[tpi].addrs = tps[tpi].fx = 4;
	tps[++tpi].id = "long";
	tps[tpi].addrs = tps[tpi].fx = 8;
	
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		int op, k;
		string s;
		scanf("%d", &op);
		if (op == 1) {
			cin >> tps[++tpi].id;
			scanf("%d", &k);
			for (int j=0;j<k;j++) {
				cin >> s >> tps[tpi].na[j];
				int ta = tps[tpi].t[j] = tad(s);
				if (tps[tpi].addrs % tps[ta].fx) tps[tpi].addrs = (tps[tpi].addrs / tps[ta].fx + 1) * tps[ta].fx;
				tps[tpi].fx = max(tps[tpi].fx, tps[ta].fx);
				tps[tpi].addrd[j] = tps[tpi].addrs;
				tps[tpi].addrs += tps[ta].addrs;
			}
			if (tps[tpi].addrs % tps[tpi].fx) tps[tpi].addrs = (tps[tpi].addrs / tps[tpi].fx + 1) * tps[tpi].fx;
			printf("%lld %d\n", tps[tpi].addrs, tps[tpi].fx);
		} else if (op == 2) {
			cin >> s >> memo[++memi].id;
			int ta = memo[memi].t = tad(s);
			if (addri % tps[ta].fx) addri = (addri / tps[ta].fx + 1) * tps[ta].fx;
			memo[memi].addr = addri;
			printf("%lld\n", addri);
			addri += tps[ta].addrs;
		} else if (op == 3) {
			cin >> s;
			long long addr=-1;
			int l=0, ma=0;
			string mm;
			for (;s[l] && s[l] != '.';l++) {
				 mm.append(1, s[l]);
			}
			for (int j=1;j<=memi;j++) {
				if (mm == memo[j].id) {
					ma = memo[j].t;
					addr = memo[j].addr;
					break;
				}
			}
			while (s[l]) {
				mm.clear();
				l++;
				for (int j=0;s[l] && s[l] != '.';l++, j++) {
					mm.append(1, s[l]);
				}
				for (int j=0;tps[ma].t[j];j++) {
					if (tps[ma].na[j] == mm) {
						addr += tps[ma].addrd[j];
						ma = tps[ma].t[j];
						break;
					}
				}
			}
			printf("%lld\n", addr);
		} else if (op == 4) {
			long long addr;
			scanf("%lld", &addr);
			int ma=0, flag=0;
			string mm;
			for (int j=1;j<=memi;j++) {
				if (addr < memo[j].addr + tps[memo[j].t].addrs) {
					if (addr < memo[j].addr) {
						flag=1;
						break;
					}
					ma = memo[j].t;
					addr -= memo[j].addr;
					for (int ii=0;memo[j].id[ii];ii++) {
						mm.append(1, memo[j].id[ii]);
					}
					break;
				}
			}
			if (!ma) flag=1;
			while (addr) {
				if (!tps[ma].t[0]) break;
				flag=1;
				for (int j=0;tps[ma].t[j];j++) {
					if (addr < tps[ma].addrd[j] + tps[tps[ma].t[j]].addrs) {
						if (addr < tps[ma].addrd[j]) {
							flag=1;
							break;
						}
						addr -= tps[ma].addrd[j];
						mm.append(1, '.');
						for (int ii=0;tps[ma].na[j][ii];ii++) {
							mm.append(1, tps[ma].na[j][ii]);
						}
						ma = tps[ma].t[j];
						flag=0;
						break;
					}
				}
				if (flag) break;
			}
			if (flag) {
				printf("ERR\n");
				continue;
			}
			cout << mm << endl;
		}
	}
	return 0;
}

