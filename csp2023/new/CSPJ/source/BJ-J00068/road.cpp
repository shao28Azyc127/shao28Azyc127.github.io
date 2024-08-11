#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const ll N = 2E5 + 10;

ll n, d, ans = 2147483647, sum;
ll u[N], a[N], f[2][N];

int main(){

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    memset(f, 0x3f, sizeof(f));

    cin >> n >> d;
    for(ll i = 1; i <= n - 1; i++){
        cin >> u[i];
        sum += u[i];
    }
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }

    f[1][0] = 0;
    for(int i = 1; i < d; i++){
        f[1][i] = a[1];
    }
    for(ll i = 1; i <= n; i++){
        for(ll j = 0; j <= sum; j++){
            if(i != 1 && j + u[i - 1] <= sum){
                f[i % 2][j] = f[(i + 1) % 2][j + u[i - 1]];
            }
            if(j >= d) f[i % 2][j] = min(f[i % 2][j], f[i % 2][j - d] + a[i]);
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j <= sum; j++){
    //         cout << f[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for(int i = 0; i <= d; i++){
        ans = min(ans, f[n % 2][i]);
    }
    cout << ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}