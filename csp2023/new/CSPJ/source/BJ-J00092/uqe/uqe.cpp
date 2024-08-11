#include<bits/stdc++.h>
using namespace std;
#define int long long
const double eps = 0.000001;
const int inf = 1000000000;
int T, m;
signed main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T >> m;
    while(T--){
        int a, b, c;
        cin >> a >> b >> c;
        if(b == 0 && c == 0){
            cout << "0\n";
            continue;
        }
        if(b == 0){
            int x = 0 - c;
            //a*ans^2=x
            if(x % a != 0){
                cout << "NO\n";
                continue;
            }
            x /= a;
            if(x < 0){
                cout << "NO\n";
                continue;
            }
            double s = sqrt(x);
            if(fabs(s - round(s)) >= eps){
                cout << "sqrt(" << x << ")\n";
                continue;
            }
            cout << (int)round(s) << "\n";
        }else if(c == 0){
            int ans = 0;
            for(int i = 1;i <= 7500;i++){
                if(a * i * i + b * i == 0){
                    ans = i;
                    break;
                }
            }
            cout << ans << "\n";
        }else{
            int ans = -inf;
            for(int i = -7500;i <= 7500;i++)
                if(a * i * i + b * i + c == 0)ans = i;
            if(ans == -inf)cout << "NO\n";
            else cout << ans << "\n";
        }
    }
    return 0;
}
//1 5 4
//©\1
//
