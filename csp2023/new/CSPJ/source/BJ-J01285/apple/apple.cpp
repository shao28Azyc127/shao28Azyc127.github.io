#include <bits/stdc++.h>
using namespace std;
int n;
int last;
int ans;
int cnt;
bool f = false;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    last = n % 3;
    while(n){
        cnt++;
        if(last){
            if(last == 1 && !f){
                ans = cnt;
                f = true;
            }
            n -= n / 3 + 1;
        }
        else n -= n / 3;
        last = n % 3;
        //cout << n <<' ' << last << endl;
    }
    cout << cnt << ' ' << ans;
    return 0;
}
