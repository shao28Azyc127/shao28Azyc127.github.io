#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans;
const int maxn = 2e6 + 3;
char a[maxn];
short mem[8003][8003];
bool del(int st, int len){
    if(mem[st][len] != -1){
        return mem[st][len];
    }
    if(len == 2){
        if(a[st] == a[st+1]){
            ans ++;
            mem[st][len] = 1;
            return true;
        }
        mem[st][len] = 0;
        return false;
    }
    if(len == 1){
        return false;
    }
    bool curans = false;
    for(int i = 1; i < len; i ++){
        if(del(st, i)){
            if(del(st + i, len - i)) curans = true;
        }
        else del(st + i, len - i);
    }
    if(a[st] == a[st + len - 1]){
        curans = curans || del(st+1, len - 2);
    }
    else{
        del(st+1, len - 2);
    }
    if(curans) ans ++;
    mem[st][len] = curans;
    return curans;
}
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    memset(mem, -1, sizeof(mem));
    scanf("%lld\n", &n);
    for(int i = 0; i < n; ++ i){
        scanf("%c", &a[i]);
    }
    del(0, n);
    printf("%lld", ans);
    fcloseall();
    return 0;
}
