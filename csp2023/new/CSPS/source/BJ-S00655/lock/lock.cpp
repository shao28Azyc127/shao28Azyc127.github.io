#include<cstdio>
#include<iostream>
using namespace  std;
typedef long long ll;
const int N = 1e6 + 5;
int bucket[N];
int n;
int a[10];
int get() {
    int res = 0;
    for(int i = 1; i <= 5; i++) {
        res = res * 10 + a[i];
    }
    return res;
}
void dfs1( int p, bool c ) {
    if(p > 5  || c) {
        if(c) {
            bucket[get()]++;
        }
        return ;
    }
    dfs1(p + 1, false);
    int t = a[p];
    for(int i = 0; i <= 9; i++) {
        if(i == t) continue;
        a[p] = i;
        dfs1(p + 1, true);
        a[p] = t;
    }
}

void dfs2( int p, bool c ) {
    if(p > 4  || c) {
        if(c) {
            bucket[get()]++;
        }
        return ;
    }
    dfs2(p + 1, false);
    int t1 = a[p];
    int t2 = a[p + 1];
    for(int i = 1; i <= 9; i++) {
        int x1 = a[p] + i;
        int x2 = a[p+1] + i;
        if(x1 > 9) x1 -= 10;
        if(x2 > 9) x2 -= 10;
        a[p] = x1;
        a[p+1] = x2;
        dfs2(p + 1, true);
        a[p] = t1;
        a[p+1] = t2;
    }
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    if(n == 1) {
        cout << 81 << endl;
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 5; j++) {
            cin >> a[j];
        }
        dfs1(1, false);
        dfs2(1, false);
        
    }
    ll ans = 0;
    for(int i = 0 ; i < 100000; i++) {
    if(bucket[i] == n) {
            ans++;
        }
    }
    cout << ans;
    
    return 0;
} 
