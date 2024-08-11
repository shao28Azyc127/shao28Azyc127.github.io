#include <bits/stdc++.h>
using namespace std;
int vis[100000005],n;
int f(){
    for (int i = 1;i <= n;i++){
        if (vis[i] == 0) return i;
    }
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    int cnt=0,ans1=0,ans2;
    while (cnt < n){
        ans1++;
        int x = f(),cnt1=0;
        for (int i = x;i <= n;i++){
            if (vis[i] == 0){
                cnt1++;
                if (i == n) ans2 = ans1;
                if (cnt1%3==1){
                    cnt++;
                    vis[i] = 1;
                }
            }
        }
    }
    cout << ans1 << " " << ans2;
    return 0;
}
