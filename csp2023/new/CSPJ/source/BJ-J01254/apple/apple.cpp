#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    long long ans1 = 0, ans2 = -1;
    while(n > 0){
        if(n%3 == 0){
            if(n > 3){
                if(ans2 == -1) ans2 = ans1+1;
                n-=n/3;
            }else{
                n--;
            }
        }else{
            if(n % 3 == 1){
                if(ans2 == -1) ans2 = ans1+1;
            }
            n-=(n/3+1);
        }
        ans1 ++;
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}