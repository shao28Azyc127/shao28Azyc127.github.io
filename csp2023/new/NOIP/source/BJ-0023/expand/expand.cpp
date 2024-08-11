#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
int cas, n, m, q;
int pa[maxn], pb[maxn];
int a[maxn], b[maxn];
bool cal(){
    if(a[1] == b[1]) return 0;
    if(a[1] > b[1]){
        for(int i = 1;i <= n;i++) a[i] = -a[i];
        for(int i = 1;i <= m;i++) b[i] = -b[i];
    }
    // cerr << "ok" << endl;
    int mxid = 1;
    for(int i = 2;i <= n;i++){
        if(a[i] > a[mxid]) mxid = i;
    }
    int pid0 = 1; int now = 0;
    for(int i = 1;i <= mxid;i++){
        while(now + 1 <= m && b[now + 1] > a[i]){
            pid0 = (b[now + 1] > b[pid0] ? now + 1 : pid0); now++;
        }
        // cerr << i << " : " << pid0 << " " << a[i] << " " << now << endl;
        if(pid0 == 0 || b[pid0] <= a[i]) return 0;
    }
    // cerr << endl;
    int now0 = now; int pid1 = m; now = m + 1;
    for(int i = n;i >= mxid;i--){
        while(now - 1 > 0 && b[now - 1] > a[i]){
            pid1 = (b[now - 1] > b[pid1] ? now - 1 : pid1); now--;
        }
        // cerr << i << " : " << pid1 << " " << a[i] << " " << now << endl;
        if(pid1 == m + 1 || b[pid1] <= a[i]) return 0;
    }
    int now1 = now;
    // cerr << now0 << " " << now1 << endl;
    if(now0 < now1) return 0;
    for(int i = now1;i <= now0;i++){
        if(b[i] > a[mxid]) return 1;
    }
    return 0;
}
int main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> cas >> n >> m >> q;
    for(int i = 1;i <= n;i++) cin >> pa[i];
    for(int i = 1;i <= m;i++) cin >> pb[i];
    for(int i = 1;i <= n;i++) a[i] = pa[i];
    for(int i = 1;i <= m;i++) b[i] = pb[i];
    cout << cal();
    while(q--){
        for(int i = 1;i <= n;i++) a[i] = pa[i];
        for(int i = 1;i <= m;i++) b[i] = pb[i];
        int px, py; cin >> px >> py;
        for(int i = 1;i <= px;i++){
            int qx, qy; cin >> qx >> qy;
            a[qx] = qy;
        }
        for(int i = 1;i <= py;i++){
            int qx, qy; cin >> qx >> qy;
            b[qx] = qy;
        }
        cout << cal();
    }
    cout << endl; return 0;
}
