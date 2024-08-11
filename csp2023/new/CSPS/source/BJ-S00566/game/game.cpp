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

const int maxN = 2e6 + 10;

int main () {
    
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    
    int n;
    cin >>n;
    string s;
    cin >>s;
    
    int ans = 0;
    
    for (int l = 0; l < n; l ++){
		char stk[maxN] = {};
		int tot = 0;
		stk[++tot] = s[l];
		for (int len = 1; len + l < n; len ++) {
			int r = l + len;
			// for (int i = 0; i <= tot; i ++)
				//cout <<s[i];
			//cout <<endl;
			if (tot == 0){
				stk[++tot] = s[r];
				continue;
			}
			char opt = stk[tot];
			//printf (":::===:::l: %c, r: %c\r\n", opt, s[r]);
			if (opt == s[r]) {
				tot --;
				if (tot == 0) {
					ans ++;
					//printf ("l: %d, r: %d", l, r);
					//cout <<"===="<<s.substr(l, len + 1) <<endl;
				}
			} else {
				stk[++tot] = s[r];
			}
			//cout <<"-----------\r\n";
		}
	}
    
    cout <<ans;
    
    
    return 0;
    
}
