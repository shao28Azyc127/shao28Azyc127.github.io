#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5;
int t, m, a, b, c, s[N];
void init() {
    for(int i = 1; i <= sqrt(5 * m * m) + 5; i++) s[i] = i * i;
}
struct _frac {
    int p, q;
};
_frac operator!(_frac x) {
    int g = __gcd(x.p, x.q);
    return {x.p / g, x.q / g};
}
_frac operator+(_frac x, _frac y) {
    _frac r;
    if(x.q == y.q) r = (_frac){x.p + y.p, x.q};
    else {
        int g = x.q * y.q / __gcd(x.q, y.q);
        r = (_frac){x.p * g / x.q + y.p * g / y.q, g};
    }
    return !r;
}
struct _sqrt {
    int k, r;
};
_sqrt operator!(_sqrt x) {
    for(int i = 2; s[i] <= x.r; i++) 
        while(x.r % s[i] == 0) {
            x.r /= s[i];
            x.k *= i;
        }
    return x;
}
void printn(_frac x) {
    if(x.q == 1) cout<<x.p;
    else {
        if(x.p * x.q < 0) cout<<"-";
        cout<<abs(x.p)<<"/"<<abs(x.q);
    }
}
void printr(_frac x, _sqrt y) {
    if(x.p == 1 && x.q == 1) cout<<"sqrt("<<y.r<<")";
    else if(x.q == 1) cout<<x.p<<"*sqrt("<<y.r<<")";
    else if(x.p == 1) cout<<"sqrt("<<y.r<<")/"<<x.q;
    else cout<<x.p<<"*sqrt("<<y.r<<")/"<<x.q;
}
signed main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t>>m;
    init();
    while(t--) {
        cin>>a>>b>>c;
        int d = b * b - 4 * a * c;
        if(d < 0) cout<<"NO"<<endl;
        else {
            _frac q1 = {-b, 2 * a};
            q1 = !q1;
            _sqrt rt = {1, d};
            rt = !rt;
            if(rt.r == 1) {
                _frac q2 = {rt.k, abs(2 * a)};
                _frac ans = q1 + q2;
                printn(ans);
            } else if(!rt.r) {
                printn(q1);
            } else {
                if(q1.p) {
                    printn(q1);
                    cout<<"+";
                }
                _frac q2 = {rt.k, abs(2 * a)};
                q2 = !q2;
                printr(q2, rt);
            }
            cout<<endl;
        }
    }
    return 0;
}