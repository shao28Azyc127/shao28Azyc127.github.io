#include <iostream>
using namespace std;

int n, d;
int v[100005];
int a[100005];
int dp[100005];
int c[100005];
int s[100005];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; i++){
        cin >> v[i];
    s[i] = v[i] + s[i-1];}
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = 1000000000;
        c[i] = 0;

    }
    dp[1] = 0;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j < i; j++){
            int l = s[i - 1] - s[j - 1] - c[j];
            if (dp[i] > dp[j] + (l / d + bool(l % d)) * a[j]){
                dp[i] = dp[j] + (l / d + bool(l % d)) * a[j];
                c[i] = (l / d + bool(l % d)) * d - l;
            }
            //cout << l << " " << dp[j] + (l / d + bool(l % d)) * a[j] << " " << j << endl;
        }
        //cout << dp[i] << "--------------\n";
    }
    cout << dp[n];
    return 0;
}
