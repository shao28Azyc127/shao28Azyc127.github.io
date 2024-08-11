#include<bits/stdc++.h>
using namespace std;
int n, m;
int s1[100010];
int s2[100010];
int t1[100010];
int t2[100010];
int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    int opt, T;
    cin >> opt >> n >> m >> T;
    for(int i=1; i<=n; ++i) cin >> s1[i];
    for(int i=1; i<=m; ++i) cin >> s2[i];
    if(n==1 && m==1) {
        cout << ((s1[1]==s2[1])?0:1);
        //cout << s1[1] << "  " << s2[1];
        while(T--) {
            int k1, k2;
            for(int i=1; i<=n; ++i) t1[i] = s1[i];
            for(int i=1; i<=m; ++i) t2[i] = s2[i];
            cin >> k1 >> k2;
            for(int i=1; i<=k1; ++i) {
                int p, v;
                cin >> p >> v;
                t1[p] = v;
            }
            for(int i=1; i<=k2; ++i) {
                int p, v;
                cin >> p >> v;
                t2[p] = v;
            }
            cout << ((t1[1]==t2[1])?0:1);
        }
        return 0;
    }
    if(n<=2 && m<=2) {
        if(n==1) s1[2] = s1[1];
        if(m==1) s2[2] = s2[1];
        if((s1[1]-s2[2])*(s1[2]-s2[1])>0) cout << 1;
        else cout << 0;
        while(T--) {
            int k1, k2;
            for(int i=1; i<=2; ++i) t1[i] = s1[i];
            for(int i=1; i<=2; ++i) t2[i] = s2[i];
            cin >> k1 >> k2;
            for(int i=1; i<=k1; ++i) {
                int p, v;
                cin >> p >> v;
                t1[p] = v;
            }
            for(int i=1; i<=k2; ++i) {
                int p, v;
                cin >> p >> v;
                t2[p] = v;
            }
            if((t1[1]-t2[2])*(t1[2]-t2[1])>0) cout << 1;
            else cout << 0;
        }
        return 0;
    }
    return 0;
}
