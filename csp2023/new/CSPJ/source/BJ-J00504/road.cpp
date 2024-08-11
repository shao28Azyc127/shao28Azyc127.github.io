#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

const int N = 1e5+5;
int n;
ll d, ld, v[N], a[N], ans;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++){
        ll dis = 0;
        for (int j = i+1; j <= n; j++){
            dis += v[j-1];
            if (a[j] < a[i]) break;
        }
        dis -= ld;
        ll tmp = dis / d;
        if (dis % d != 0) tmp++;
        cout << tmp * a[i] << " ";
        ans += tmp*a[i];
        ld = tmp*d - dis;
    }
    cout << ans;
    return 0;
}
