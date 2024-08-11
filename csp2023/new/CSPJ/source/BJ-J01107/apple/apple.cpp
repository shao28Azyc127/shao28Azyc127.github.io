#include<bits/stdc++.h>
using namespace std;
int n, ans, cnt;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    while(n != 0){
        cnt++;
        if(n % 3 == 1 && !ans) ans = cnt;
        n -= (n - 1) / 3 + 1;
    }printf("%d %d", cnt, ans);
    return 0;
}
