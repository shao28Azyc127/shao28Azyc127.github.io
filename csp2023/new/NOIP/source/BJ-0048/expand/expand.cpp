#include<bits/stdc++.h>
using namespace std;

const int NR = 5e5;

int sid, n, m, n2, m2, q, sn, pf, pe;
int a[NR + 5], b[NR + 5], a2[NR + 5], b2[NR + 5], stk[NR + 5], mxb[NR + 5], mnb[NR + 5], mns[NR + 5], id[NR + 5], r[NR + 5];

bool cmp(int x, int y) {
    return a[x] < a[y];
}

void work() {
    if(a[1] < b[1]) {
        for(int i = 1; i <= max(n, m); i++) {
            swap(a[i], b[i]);
        }
        swap(n, m);
    }
    mnb[1] = b[1];
    mxb[1] = b[1];
    for(int i = 2; i <= m; i++) {
        mxb[i] = max(b[i], mxb[i - 1]);
        mnb[i] = min(b[i], mnb[i - 1]);
    }
    mns[m] = b[m];
    for(int i = m - 1; i >= 1; i--) {
        mns[i] = min(b[i], mns[i + 1]);
    }
    sn = 0;
    for(int i = n; i >= 1; i--) {
        while(sn && a[stk[sn]] < a[i]) {
            sn--;
        }
        stk[++sn] = i;
    }
    int mpa = stk[1];
    if(a[mpa] <= mxb[m]) {
        cout << "0";
        return;
    }
    for(int i = 1; i <= n; i++) {
        id[i] = i;
    }
    sort(id + 1, id + mpa, cmp);
    sort(id + mpa + 1, id + n + 1, cmp);
    for(int t = 1, rn = 0; t < mpa; t++) {
        int i = id[t];
        while(rn < m && a[i] > b[rn + 1]) {
            rn++;
        }
        r[i] = rn;
    }
    for(int t = mpa + 1, rn = m + 1; t <= n; t++) {
        int i = id[t];
        while(rn > 1 && a[i] > b[rn - 1]) {
            rn--;
        }
        r[i] = rn;
    }
    if(a[1] <= b[1] || a[n] <= b[m]) {
        cout << "0";
        return;
    }
    pf = 1;
    for(int t = sn; t >= 2; t--) {
        int i = stk[t], j = stk[t - 1], mn = a[i];
        for(int k = i + 1; k < j; k++) {
            mn = min(mn, a[k]);
        }
        int L = 1, R = r[i];
        while(L < R) {
            int M = L + R >> 1;
            if(mnb[M] < mn) {
                R = M;
            }
            else {
                L = M + 1;
            }
        }
        if(mn <= mnb[L]) {
            cout << "0";
            return;
        }
        pf = L;
    }
    sn = 0;
    for(int i = 1; i <= n; i++) {
        while(sn && a[stk[sn]] <= a[i]) {
            sn--;
        }
        stk[++sn] = i;
    }
    pe = m;
    for(int t = sn; t >= 2; t--) {
        int i = stk[t], j = stk[t - 1], mn = a[i];
        for(int k = j + 1; k < i; k++) {
            mn = min(mn, a[k]);
        }
        int L = r[i], R = m;
        while(L < R) {
            int M = L + R + 1 >> 1;
            if(mns[M] < mn) {
                L = M;
            }
            else {
                R = M - 1;
            }
        }
        if(mn <= mns[L]) {
            cout << "0";
            return;
        }
        pe = L;
    }
    if(pf <= pe) {
        cout << "1";
    }
    else {
        cout << "0";
    }
}

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> sid >> n2 >> m2 >> q;
    n = n2, m = m2;
    for(int i = 1; i <= n2; i++) {
        cin >> a2[i];
        a[i] = a2[i];
    }
    for(int i = 1; i <= m2; i++) {
        cin >> b2[i];
        b[i] = b2[i];
    }
    work();
    for(int i = 1; i <= q; i++) {
        n = n2, m = m2;
        for(int j = 1; j <= n; j++) {
            a[j] = a2[j];
        }
        for(int j = 1; j <= m; j++) {
            b[j] = b2[j];
        }
        int kx, ky;
        cin >> kx >> ky;
        for(int j = 1; j <= kx; j++) {
            int x, y;
            cin >> x >> y;
            a[x] = y;
        }
        for(int j = 1; j <= ky; j++) {
            int x, y;
            cin >> x >> y;
            b[x] = y;
        }
        work();
    }
    cout << '\n';

    return 0;
}