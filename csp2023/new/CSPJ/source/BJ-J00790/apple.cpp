#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

int n,t,cnt,ans;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    t = n;
    if(t % 3 == 1) ans = 1;
    while(1){
        int x = int(ceil(t * 1.0 / 3));
        if(t <= 3) x = 1;
        t -= x;
        ++cnt;
        if(t % 3 == 1 && ans == 0) ans = cnt + 1;
        if(t == 0){
            cout << cnt << ' ' << ans << endl;
            return 0;
        }
    }
    return 0;
}
