#include <iostream>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
ll a[N];
ll b[N], c[N];
int u[N], v[N];
ll t[N];
ll n;
bool flag = true;
ll workB(){
    for(int i = 1; i <= n; i ++){
        ll x = i;
        if(c[i] < 0){
            while(b[i] + c[i] * x >= 1){
                a[i] -= (b[i] + c[i] * x);
                t[i] ++;
                x ++;
            }
            t[i] += a[i];
            t[i] -= 1;
        }
        if(c[i] == 0){
            if(a[i] % b[i] != 0){
                t[i] = a[i] / b[i] + 1;
            }
            else{
                t[i] = a[i] / b[i];
            }
            t[i] -= 1;
        }
        if(c[i] > 0){
            ll s = 0, e = 1000000000;
            while(s < e){
                ll mid = (s + e) / 2;
                if((2 * i + mid) * (mid + 1) / 2 * c[i] + (mid + 1) * b[i] >= a[i]){
                    e = mid;
                }
                else{
                    s = mid + 1;
                }
            }
            t[i] = e;
        }
    }
    ll T = 0;
    for(int i = 1; i <= n; i ++){
        T = max(T, t[i] + i);
    }
    return max(T, n);
}
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 1; i <= n - 1; i ++){
        cin >> u[i] >> v[i];
        if(u[i] != v[i] - 1)flag = false;
    }
    if(flag){
        cout << workB();
        return 0;
    }
    return 0;
}
