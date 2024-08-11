#include <bits/stdc++.h>

#define ff(i, a, b) for(int i = (a); i <= (b); i++)

#define ull unsigned long long

using namespace std;

inline int Read () {
    char c = getchar();
    while (c != '-' && (c > '9' || c < '0'))  c = getchar();
    int res = 0;
    int sign = (c == '-')? -1 : 1;
    if (c != '-')
        res += c - '0', res = (res << 3) + (res << 1);
    c = getchar ();
    while (c <= '9' && c >= '0'){
        res += c - '0';
        res = (res << 3) + (res << 1);
        c = getchar ();
    }
    return res * sign / 10;
}

struct Plants{
	int a;
	int b;
	int c;
} p[1000];


vector<int> Edge[1000];

bool vis[1000] = {};

int work (int u, int d) {
	vis[u] = true;
	int res = 1e9;
	for (int x : Edge[u]){
		res = min(res, work(x, d + 1));
	}
	vis[u] = false;
	return res;
}


int main () {
    
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    
    int n;
    cin >>n;
    
    for (int i = 1; i <= n; i ++) {
		cin >>p[i].a >>p[i].b >>p[i].c;
	}
	
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >>u >>v;
		Edge[u].push_back(v);
		Edge[v].push_back(u);
	}
    
    cout <<work(1, 1);
    
    return 0;
}
