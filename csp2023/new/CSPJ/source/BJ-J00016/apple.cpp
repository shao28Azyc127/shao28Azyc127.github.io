#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    freopen("apple.in", r, stdin);
    freopen("apple.out", w, stdout);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        s += i + '0';
    }

    int x = 0;
    int day = 0;
    int ans = 0;
    while(!s.empty()){
        if(x == n) ans = day;
        s = s.substr(0, x) + s.substr(x);
        x++;
        if(x >= s.size()){
            x -= s.size();
            day++;
        }
    }

    cout << day << " " << ans;

    return 0;
}
