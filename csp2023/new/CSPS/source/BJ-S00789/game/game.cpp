#include<bits/stdc++.h>
using namespace std;
int n, ans; char s[100];
bool check(int l, int r){
    char a[100]; int len = r - l + 1;
    for(int i = l; i <= r; i++) a[i - l + 1] = s[i];
    while(len){
        bool f = 0;
        for(int i = 1; i < len; i++){
            if(a[i] == a[i + 1]){
                f = 1;
                for(int j = i; j <= len - 2; j++) a[j] = a[j + 2];
                len -= 2;
            }
        }if(!f) return 0;
    }return 1;
}int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d%s", &n, s + 1);
    for(int l = 1; l < n; l++)
        for(int r = l + 1; r <= n; r++)
            if(check(l, r)) ans++;
    printf("%d", ans);
    return 0;
}
