#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
ll v[100005], a[100005];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, d; cin >> n >> d;
    for (int i = 1; i < n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll ans = 0, rem = 0, Min = 1e18;
    for (int i = 1; i < n; i++){
        Min = min(Min, a[i]);
        rem -= v[i];
        ll c = (-rem + d - 1) / d;
        ans += c * Min;
        rem += c * d;
    }
    cout << ans;
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
char name[25];
int v[100005], a[100005];
int Rand(){
    if (RAND_MAX == 32767) return (rand() << 15) + rand();
    else return rand();
}
int main(){
    srand(time(0));
    for (int i = 1; i <= 20; i++){
        sprintf(name, "road%d.in", i);
        freopen(name, "w", stdout);
        int n;
        if (i <= 5) n = 8 - Rand() % 2;
        else if (i <= 10) n = 1000 - Rand() % 10;
        else n = 100000 - Rand() % 100;
        int d = Rand() % 10000 + 1;
        cout << n << ' ' << d << '\n';
        for (int j = 1; j < n; j++){
            if (i >= 11 && i <= 13) v[j] = (Rand() % ((int)9e4 / d) + 1) * d;
            else v[j] = Rand() % (int)1e5 + 1;
            cout << v[j] << " \n"[j == n - 1];
        }
        for (int j = 1; j <= n; j++){
            a[j] = Rand() % (int)1e5 + 1;
        }
        if (i >= 14 && i <= 16) nth_element(a + 1, a + 1, a + n + 1);
        for (int j = 1; j <= n; j++){
            cout << a[j] << " \n"[j == n];
        }
        fclose(stdout);
    }
}

*/
