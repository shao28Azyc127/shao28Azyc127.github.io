#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, ans;
ll a[10][10];
ll cd[10];
bool check(){
    bool flag = true;
    for(ll i = 0;i < n;i++){
        ll dif = 0, diff[5];
        for(ll j = 1;j <= 5;j++)
            if(a[i][j] != cd[j])
                diff[dif++] = j;
        if(dif == 0)
            return false;
        if(dif > 2)
            return false;
        if(dif == 2){
            ll x = diff[0], y = diff[1];
            if(y > x)
                swap(x, y);
            if(x - y != 1)
                return false;
            ll ax = a[i][x], ay = a[i][y], dx = cd[x], dy = cd[y];
            if(dx < ax)
                dx += 10;
            if(dy < ay)
                dy += 10;
            if(dx - ax != dy - ay)
                return false;
        }
    }
    return true;
}
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%lld", &n);
    for(ll i = 0;i < n;i++)
        for(ll j = 1;j <= 5;j++)
            scanf("%lld", &a[i][j]);
    for(ll a = 0;a <= 9;a++){
        for(ll b = 0;b <= 9;b++){
            for(ll c = 0;c <= 9;c++){
                for(ll d = 0;d <= 9;d++){
                    for(ll e = 0;e <= 9;e++){
                        cd[1] = a, cd[2] = b, cd[3] = c, cd[4] = d, cd[5] = e;
                        if(check())
                            ans++;
                    }
                }
            }
        }
    }
    printf("%lld", ans);
    return 0;
}
