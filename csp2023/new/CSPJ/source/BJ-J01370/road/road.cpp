#include<bits/stdc++.h>
using namespace std;
long long s[100005];
long long v[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i = 1;i < n;i++){
        cin >> s[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> v[i];
    }
    long long cnt = v[1],ans = 0,now = 0,x = 0;
    for(int i = 1;i < n;i++){
        x += s[i];
        if(v[i + 1] < cnt){
            if(x >= now){
                x -= now;
            }
            else{
                now -= x;
                x = 0;
            }
            if(x){
                ans += cnt * (x / m);
                if(x % m != 0){
                    ans += cnt;
                    now = m * (x / m + 1) - x;
                }
                else{
                    now = 0;
                }
            }
            x = 0;
            cnt = v[i + 1];
        }
    }
    x = max((long long)0,x - now);
    ans += cnt * (x / m);
    if(x % m != 0){
        ans += cnt;
        now = m * (x / m + 1) - x;
    }
    else{
        now = 0;
    }
    cout << ans;
    return 0;
}
