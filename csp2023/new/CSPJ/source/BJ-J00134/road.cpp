#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const int N = 1e5 + 5;
LL n,d,v[N],a[N],ans,r,sum;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i = 1; i <= n; ++i) cin >> v[i];
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1, cur = 0; i <= n-1; ++i){

        r = cur;
        if(cur > v[i]){
            cur -= v[i];
            continue;
        }
        cur = 0;
        cur += v[i];
        for(int j = i+1; j <= n; ++j){
            if(a[i] < a[j]){
                cur += v[j];
                //cout << j << ' ';
            }

            else break;
        }
        sum = cur;
        cur = (cur+2)/d*d;
        if((cur-d+r) >= sum) cur = cur - d + r;
        else cur += r;
        //cout << cur << endl;

        ans += cur/d*a[i];
        cur -= v[i];
    }
    cout << ans << endl;
    return 0;
}
