#include<bits/stdc++.h>
int n, cnt, sum, f, ans;
using namespace std;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    while(n){
        if(n % 3 == 1 && f == 0) f = 1, ans = cnt+1;
        cnt++, n -= (n-1)/3+1;
    }
    printf("%d %d", cnt, ans);
    return 0;
}
