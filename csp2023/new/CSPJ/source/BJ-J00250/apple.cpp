#include <bits/stdc++.h>
using namespace std;
int n,i = 1,res = 0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    int t = n;
    for(i = 1;i <= t;i++){
        if(n % 3 == 0) n -= n / 3;
        else if(n % 3 == 1){
            n -= (n / 3 + 1);
            if(res == 0) res = i;
        }
        else if(n % 3 == 2) n -= (n / 3 + 1);
        if(n == 0) break;
    }
    cout << i << ' ' << res << endl;;
    return 0;
}
