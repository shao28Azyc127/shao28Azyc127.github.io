#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e9 + 5;
bool a[maxn];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt = 2,ans=0,ans2;
    cin >> n;
    for (int cnt1 = 0; cnt1 < n; cnt1++){
        cnt = 2;
        ans++;
        bool stop=0;
        for (int i = 1;i <= n; i++){
            if(a[i]) continue;
            ++cnt%= 3;
            if (cnt) continue;
            a[i]=1;
            stop = 1;
            if(i==n) ans2 = ans;
        }
        if(!stop) break;
    }
    cout << ans-1 <<" "<<ans2;
    return 0;
}
