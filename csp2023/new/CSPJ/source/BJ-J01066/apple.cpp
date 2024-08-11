#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    int day = 0;
    int ans = 0;
    cin >> n;
    while (n > 3){
        if (n % 3 == 1){
            ans = day+1;
        }
        n -= n/3+1;
        day++;
    }
    day += n;
    if (ans == 0){
        ans = day;
    }
    cout << day << " " << ans << endl;
    return 0;
}