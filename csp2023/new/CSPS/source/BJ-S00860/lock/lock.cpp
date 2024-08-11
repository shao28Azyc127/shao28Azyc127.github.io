#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 8 + 5;
int n, cnt;
struct Lock {
    int a, b, c, d, e;
}l[N];
int _add(int k, int t) {
    k += t;
    if(k < 0) k += 9;
    if(k > 9) k -= 9;
    return k;
}
int _minus(int k, int t) {
    if(k < t) return k - t + 10;
    return k - t; 
}
bool check(int a, int b, int c, int d, int e) {
    for(int k = 1; k <= n; k++) {
        int f1 = 0;
        if(b == l[k].b && c == l[k].c && d == l[k].d && e == l[k].e) f1++;
        if(a == l[k].a && c == l[k].c && d == l[k].d && e == l[k].e) f1++;
        if(a == l[k].a && b == l[k].b && d == l[k].d && e == l[k].e) f1++;
        if(a == l[k].a && b == l[k].b && c == l[k].c && e == l[k].e) f1++;
        if(a == l[k].a && b == l[k].b && c == l[k].c && d == l[k].d) f1++;
        int f2 = 0;
        if(_minus(a, l[k].a) == _minus(b, l[k].b) && c == l[k].c && d == l[k].d && e == l[k].e) f2++;
        if(_minus(b, l[k].b) == _minus(c, l[k].c) && a == l[k].a && d == l[k].d && e == l[k].e) f2++;
        if(_minus(c, l[k].c) == _minus(d, l[k].d) && a == l[k].a && b == l[k].b && e == l[k].e) f2++;
        if(_minus(d, l[k].d) == _minus(e, l[k].e) && a == l[k].a && b == l[k].b && c == l[k].c) f2++;
        if(f1 != 1 && f2 != 1) return 0;
    }
    return 1;
}
signed main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++) 
        cin>>l[i].a>>l[i].b>>l[i].c>>l[i].d>>l[i].e;
    for(int a = 0; a <= 9; a++)
        for(int b = 0; b <= 9; b++)
            for(int c = 0; c <= 9; c++)
                for(int d = 0; d <= 9; d++)
                    for(int e = 0; e <= 9; e++)
                        if(check(a, b, c, d, e)) cnt++;
    cout<<cnt<<endl;
    return 0;
}
