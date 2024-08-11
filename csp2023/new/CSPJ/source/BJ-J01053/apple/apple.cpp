#include <bits/stdc++.h>
using namespace std;

int a[100000001];
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, sum, ans = 0, day = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        a[i] = i;
    }
    while(n > 0){
        day++;
        int x = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] == 0){
                continue;
            }
            x++;
            x %= 3;
            if(a[i] % 3 == x){
                if(i == n){
                    ans = day;
                }
                a[i] = 0;
                n--;
            }
        }
    }
    cout << day << ' ' << ans;
    return 0;
}