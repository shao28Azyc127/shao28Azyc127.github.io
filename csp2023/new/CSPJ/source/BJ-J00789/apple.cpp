#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, r, ans, t;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    r = n;
    ans = 0;
    t = 0;
    while(r){
        if(r % 3 == 0){
            r -= r / 3;
        }
        else if(r % 3 == 1){
            if(ans == 0){
                ans = t + 1;
            }
            r -= r / 3 + 1;
        }
        else{
            r -= r / 3 + 1;
        }
        t++;
    }
    cout << t << " " << ans;
    return 0;
}
