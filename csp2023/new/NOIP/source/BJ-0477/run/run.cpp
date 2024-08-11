#include <bits/stdc++.h>
#define int long long
using namespace std;

int const N = 1e5 + 10;

int n, m, k, d;
int c, t;


int f[N][2];

struct cxd{
    int x, y, v;
} q[N];

bool cmp(cxd a, cxd b){
    if (a.x != b.x) return a.x < b.x;
    return a.y > b.y;
}

void work(){
    memset(f, 0, sizeof f);
    f[1][0] = 0;
    f[1][1] = q[1].v - q[1].y * d;
    for (int i = 2;i <= m;++i){
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        for (int j = i - 1;j >= 1;--j){
            int r1 = q[i].x, l1 = q[i].x - q[i].y + 1, r2 = q[j].x, l2 = q[j].x - q[j].y + 1;
            //cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
            if (r2 >= l1 && r2 <= r1){
                if (r1 - l2 + 1 <= k){
                    f[i][1] = max(f[j][0], f[j][1]) + q[i].v - q[i].y * d;
                   break;
                }
            }
            else if (r2 < l1){
                f[i][1] = max(f[j][0], f[j][1]) + q[i].v - q[i].y * d;
                break;
            }
        }
    }
    for (int i = 1;i <= m;++i){
       //cout << f[i][0] << " " << f[i][1] << endl;
    }

   cout << max(f[m][1], f[m][0]) << endl;
}

signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin >> c >> t;
    while (t--){
        scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
        for (int i = 1;i <= m;++i) scanf("%lld%lld%lld", &q[i].x, &q[i].y, &q[i].v);
        sort(q + 1, q + m + 1, cmp);
        //for (int i = 1;i <= m;++i) cout << q[i].x << endl;
        work();
    }
    return 0;
}
