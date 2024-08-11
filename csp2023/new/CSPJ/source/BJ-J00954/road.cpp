#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,d;
    scanf("%lld%lld",&n,&d);
    vector<ll> v(n+1,0),a(n+1);
    v[1] = 0;
    for (ll i = 2; i <= n; i++){
        scanf("%lld",&v[i]);
    }
    for (ll i = 1; i <= n; i++){
        scanf("%lld",&a[i]);
    }
    /*
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    ll maxn = LLONG_MIN;
    for (ll i = n; i >= 1; i--){
        for (ll j = i+1;j <= n; j++){
            ll cm = 0;
            for (ll tt = i; tt <= j; tt++) cm += a[tt];
            //cout << cm << " ";
            if (cm % d == 0){
                dp[i][j] = a[i]*(cm / d);
                //cout << dp[i][k]+(a[k]*(cm / d)) << endl;
            } else {
                dp[i][j] = a[i]*(cm / d+1);
                //cout << dp[i][k]+(a[k]*(cm / d)) << endl;
            }
            for (ll k = i;k <j;k++){
                ll cm = 0;
                for (ll tt = k+1; tt <= j; tt++) cm += a[tt];
                //cout << cm << " ";
                if (cm % d == 0){
                    dp[i][j] = min(dp[i][j],dp[i][k]+(a[k+1]*(cm / d)));
                    //cout << dp[i][k+1]+(a[k]*(cm / d)) << endl;
                } else {
                    dp[i][j] = min(dp[i][j],dp[i][k]+(a[k+1]*((cm / d)+1)));
                    //cout << dp[i][k+1]+(a[k]*(cm / d)) << endl;
                }
                cout << dp[i][j] << endl;
            }
        }
    }
    cout <<dp[1][n];*/
    ll moy = 0;
    ll now = 1;
    ll you = 0;
    while (now < n){
        ll nowmoney = a[now];
        //ll maxn = INT_MIN;
        bool f = 1;
        for (ll i = now; i <= n; i++){
            //cout << a[i] << " ";
            if (a[i] < nowmoney){
                //cout << now << " ";
                ll am = 0;
                for (ll j = now+1; j <= i; j++) am += v[j];
                am -= you;
                //cout << am<<" ";
                you = 0;
                if (am % d == 0){
                    moy += nowmoney*(am/d);
                    //cout <<(am/d) << endl;
                } else {
                    moy += nowmoney*((am/d)+1);
                    you += ((am/d+1)*d)-am;
                    //cout << (am/d+1) <<" add "<<you<< endl;
                }
                now = i;
                f = 0;
                break;
            }
            //cout << endl;
        }
        if (f){
            ll am = 0;
            for (ll j = now+1; j <= n; j++) am += v[j];
            if (am % d == 0){
                moy += nowmoney*(am/d);
            } else {
                moy += nowmoney*((am/d)+1);
            }
            now = n;
            //cout << now;
        }
    }
    cout << moy;
return 0;
}
