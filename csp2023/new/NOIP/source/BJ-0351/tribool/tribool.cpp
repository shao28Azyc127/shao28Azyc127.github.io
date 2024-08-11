#include <bits/stdc++.h>
using namespace std;
struct cmd {
    int v, x, type, k;
}pool[10001];
struct var {
    int ff = 0, fv= 0;
    int fa, v, anti = 0;
}arr[10001];
int c, t;
int faisself(int x,int op) {
    int xx = x, anti = arr[xx].anti;
    bool flag = arr[xx].ff && !arr[xx].fv;
    while (arr[xx].fa != x && flag) {
        xx = arr[xx].fa;
        anti = (arr[xx].anti != anti);
        flag = arr[xx].ff && !arr[xx].fv;
    }
    if (arr[xx].fa == x) {
        if (op == 0) {
            return 1;
        } else {
            return anti;
        }
    }
    if(op == 0) {
        return 0;
    } else {
        return anti;
    }
    return -2;
}
int main() {
    ios::sync_with_stdio(false);
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        int n,m,m2,v,x,cnt=0,ans = 0;
        memset(pool,0,sizeof(pool));
        memset(arr,0,sizeof(arr));
        cin >> n >> m;
        m2=m;
        while (m2--) {
            char op;
            cin >> op;
            if (op == 'T' || op == 'F' || op == 'U') {
                cin >> v;
                pool[cnt].type = 0;
                pool[cnt].v = v;
                if (op=='T') {
                  pool[cnt].k = 1;
                } else if (op == 'F') {
                  pool[cnt].k = 0;
                } else {
                    pool[cnt].k = -1;
                }

            } else if (op == '+' ||op == '-') {
                cin >> v >> x;
                pool[cnt].v = v;
                pool[cnt].x = x;
                if (op=='+'){
                    pool[cnt].type = 1;
                }
                else {
                   pool[cnt].type = 2;
                }
            }
            cnt++;
        }

        for (int i = n; i >= 1; i--) {
            arr[i].fa=i;
        }
        for (int i = 0; i < m; i++) {

            if (pool[i].type == 0) {
                arr[pool[i].v].v = pool[i].k;
                arr[pool[i].v].fv =1;
                arr[pool[i].v].ff =0;
            } else {
                arr[pool[i].v].fa = pool[i].x;
                arr[pool[i].v].fv = 0;
                arr[pool[i].v].ff = 1;
                if (pool[i].type == 2) {
                    arr[pool[i].v].anti = 1;
                }
            }
        }
        for (int i = n; i >= 1; i--) {
            if(faisself(i,0) &&faisself(i,1)) {
                ans++;
            } else if (!arr[i].ff&&arr[i].fv && arr[i].v==-1) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
