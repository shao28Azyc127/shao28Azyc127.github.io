#include<iostream>
#define int long long
using namespace std;

int v[100005], a[100005];
int plan[100005];
int pland[100005];

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for(int i = 1; i < n; i++)
        cin >> v[i];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int minn = 1e9;
    for(int i = 1; i <= n; i++)
        minn = min(minn, a[i]);
    if(minn == a[1])
    {
        int sum = 0;
        for(int i = 1; i <= n; i++)
            sum += v[i];
        if(sum % d == 0) cout << sum / d * a[1] << endl;
        else cout << (sum / d + 1) * a[1] << endl;
        return 0;
    }
    bool f = true;
    for(int i = 1; i <= n; i++)
        if(v[i] % d != 0) f = false;
    if(f)
    {
        int t = 1;
        int ans = 0;
        for(int i = 1; i < n; i++)
        {
            if(a[t] > a[i])
                t = i;
            int l = v[i] / d;
            ans += l * a[t];
        }
        cout << ans << endl;
        return 0;
    }
    int t = 1;
    int yu = 0, ans = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[t] > a[i])
            t = i;
        int l = (v[i] - yu) / d;
        if(l * d == v[i] - yu) ans += l * a[t];
        else ans += (l + 1) * a[t];
        yu = (v[i] - yu) % d;
    }
    cout << ans << endl;
    return 0;
}
