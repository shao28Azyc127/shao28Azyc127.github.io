#include <bits/stdc++.h>
using namespace std;
int n, ans, turn;
bool f = true;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    while(n != 0){
        turn++;
        int t = n / 3;
        if(n % 3 >= 1){
            t++;
        }
        if(n % 3 == 1&&f){
            ans = turn;
            f = false;
        }
        n -= t;
    }
    cout << turn << " " << ans;
    return 0;
}
