#include <bits/stdc++.h>
using namespace std;
long long solve(long long n){
    if(n < 3){
        return n;
    }
    return solve(n-(n % 3 == 0?n / 3:n / 3 + 1)) + 1;
}

long long solve2(long long n){
    if(n % 3 == 1){
        return 1;
    }
    return solve(n-(n % 3 == 0?n / 3:n / 3 + 1)) + 1;
}




int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin >> n;
    long long ans = solve(n);
    long long ans2 = solve2(n);
    cout << ans << " " << ans2;
    return 0;
}
