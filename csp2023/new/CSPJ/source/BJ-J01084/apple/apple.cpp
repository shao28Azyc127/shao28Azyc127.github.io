#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans = 0,cnt = 0;
    cin >> n;
    bool flag = true;
    while (n){
        cnt++;
        if ((n-1) % 3 == 0 && flag){
            ans = cnt;
            flag = false;
        }
        n -= (n + 2) / 3;
    }
    cout << cnt << " " << ans << endl;
    return 0;
}
