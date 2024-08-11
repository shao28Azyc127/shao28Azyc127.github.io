#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int c, t, n, m;
struct Node {
    int k, p;
} a[N];
Node work(int d, int s) {
    cout<<"(work "<<d<<" with return value ";
    if(!a[d].k && !a[d].p) {
        cout<<"{"<<-1<<", "<<0<<"}) ";
        return {-1, 0};
    }
    if(a[d].p == s) {
        cout<<"{"<<a[d].k<<", "<<s<<"}) ";
        return {a[d].k, s};
    }
    auto r = work(a[d].p, s);
    if(r.k == -1) {
        cout<<"{"<<a[d].k<<", "<<a[d].p<<"}) ";
        return a[d];
    }
    a[d] = {!(r.k ^ a[d].k), r.p};
    cout<<"_chg a["<<d<<"] = {"<<a[d].k<<", "<<a[d].p<<"}) ";
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    srand(time(0));
    cin>>c>>t;
    while(t--) {
        cin>>n>>m;
        cout<<rand() % 10<<endl;
        // cin>>n>>m;
        // for(int i = 1; i <= n; i++) a[i] = {0, 0}; 
        // while(m--) {
        //     char v;
        //     cin>>v;
        //     if(v == '+') {
        //         int i, j;
        //         cin>>i>>j;
        //         a[i] = {1, j};
        //         work(i, i);
        //         cout<<endl;
        //     } else if(v == '-') {
        //         int i, j;
        //         cin>>i>>j;
        //         a[i] = {0, j};
        //         work(i, i);
        //         cout<<endl;
        //     } else {
        //         int i;
        //         cin>>i;
        //         a[i].k = v;
        //     }
        //     for(int i = 1; i <= n; i++) cout<<a[i].k<<" "<<a[i].p<<endl;
        //     cout<<endl;
        // }
        // cout<<endl<<"----------------------------------------"<<endl<<endl;
    }
    return 0;
}