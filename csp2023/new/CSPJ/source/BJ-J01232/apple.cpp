#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans;

int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    scanf("%d", &n);
    m = n;

    while(m!=0){
        m = m - (m - 1) / 3 - 1;
        ans++;
    }

    printf("%d ", ans);

    ans = 0;

    while(n!=0){
        ans++;
        if(n%3==1) break;
        n = n - (n - 1) / 3 - 1;
    }

    printf("%d", ans);

    return 0;
}
