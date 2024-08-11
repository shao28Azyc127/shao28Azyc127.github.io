#include<iostream>
using namespace std;
const int maxn = 100000 + 10;
const long long INF = 1e9;
int n, d;
long long v[maxn], a[maxn], ans;
int main()
{
        freopen("road.in", "r", stdin);
        freopen("road.out", "w", stdout);
        cin >> n >> d;
        for(int i = 1; i < n; i++) cin >> v[i];
        for(int i = 1; i <= n; i++) cin >> a[i];
        long long mina = INF, used = 0, sum = 0;
        for(int i = 1; i < n; i++) {
                mina = min(mina, a[i]);
                sum += v[i];
                long long need = (sum + d - 1) / d;
                ans += (need - used) * mina;
                used = need;
        }
        cout << ans << endl;
        return 0;
}
