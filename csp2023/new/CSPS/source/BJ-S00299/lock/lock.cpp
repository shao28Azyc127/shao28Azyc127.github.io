#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int n, a[N][6], b[6];
vector<int> p;

int M(int x) {return (x % 10 + 10) % 10;}

bool Chk(int x) {
    //a[x] and b
    int cnt = 0;
    for(int i = 1; i <= 5; i++) cnt += (a[x][i] != b[i]);
    if(cnt == 0 || cnt > 2) return false;
    if(cnt == 1) return true;
    // Now, cnt = 2
    p.clear();
    for(int i = 1; i <= 5; i++) if(a[x][i] != b[i]) p.push_back(i);
    if(abs(p[0] - p[1]) != 1) return false;
    if(M(a[x][p[0]] - b[p[0]]) == M(a[x][p[1]] - b[p[1]])) return true;
    return false;
}

bool chk(int x) {
    int cur = x;
    for(int t = 1; t <= 5; t++) b[t] = cur % 10, cur /= 10;
    for(int i = 1; i <= n; i++) if(!Chk(i)) return false;
    return true;
}

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= 5; j++) cin >> a[i][j];
    int ans = 0;
    for(int s = 0; s < 100000; s++) ans += chk(s);
    cout << ans << '\n';
    return 0;
}