# include <vector>
# include <iostream>
# include <algorithm>
typedef long long ll;
using namespace std;

vector <ll> v;
struct Ach{
    ll x, y, d;
    bool operator < (Ach k){
        if (x != k.x)
            return x < k.x;
        return y < k.y;
    }
};
vector <Ach> a;

int main(){
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--){
        ll n, m, k, d;
        cin >> n >> m >> k >> d;
        a.clear();
        a.resize(m + 2);
        for (int i = 1; i <= m; i++)
            cin >> a[i].x >> a[i].y >> a[i].d;
        sort(a.begin(), a.end() - 1);
        if (c <= 14){
            v.clear();
            v.resize(k + 1);
            for (int i = 1; i <= k; i++)
                v[i] = -1e18;
            int pos = 1;
            for (int i = 1; i <= n + 1; i++){
                ll maxn = -1e18;
                for (int j = k; j > 0; j--){
                    maxn = max(maxn, v[j]);
                    v[j] = v[j - 1] - d;
                }
                v[0] = max(maxn, v[0]);
                ll sum = 0;
                while (pos <= m && a[pos].x == i){
                    sum += a[pos].d;
                    if (a[pos + 1].x == i)
                        for (int i = a[pos].y; i < a[pos + 1].y; i++)
                            v[i] += sum;
                    else
                        for (int i = a[pos].y; i <= k; i++)
                            v[i] += sum;
                    pos++;
                }
            }
            cout << v[0] << endl;
        }
    }
    return 0;
}