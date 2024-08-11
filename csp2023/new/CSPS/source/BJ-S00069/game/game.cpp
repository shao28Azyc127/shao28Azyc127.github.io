#include<bits/stdc++.h>
using namespace std;

const int N = 2000005;
char inc;
char s[N];
int n;
int lst[N][30], f[N];

int trs(char a){
    return a - 'a';
}
void checkF(){
    printf("::checking f: \n");
    for(int i = 1; i <= n; i++){
        printf("f[%d] = %d; \n", i, f[i]);
    }
    printf("::over\n");
    return ;
}
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    inc = getchar();
    while(inc < 'a' || inc > 'z'){
        inc = getchar();
    }
    s[1] = inc;
    for(int i = 2; i <= n; i++){
        s[i] = getchar();
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 25; j++){
            lst[i][j] = lst[i-1][j];
        }
        f[i] += f[i-1];
        if(lst[i-1][trs(s[i])] == 0){
            lst[i][trs(s[i])] = i;
            // f[i] = f[i-1];
            // printf("::mismatch at %d\n", i);
            continue;
        }
        if((i-lst[i][trs(s[i])])%2 == 0){
            // f[i] = f[i-1];
            lst[i][trs(s[i])] = i;
            continue;
        }
        int cur = i;
        f[i] += 1;
        // f[i] += max(f[cur-1]-f[lst[cur][trs(s[cur])]], 0);
        // lst[i][trs(s[i])] = lst[lst[i][trs(s[i])]-1][trs(s[i])];
        cur = lst[cur][trs(s[cur])]-1;
        while(cur >= 1){
            if(f[cur]-f[lst[cur][trs(s[cur])]-1] == 0){
                break;
            }
            f[i]++;
            // f[i] += max(f[cur]-f[lst[cur][trs(s[cur])]-1], 0);
            cur = lst[cur][trs(s[cur])]-1;
            // printf("::go back from %d\n", i);
        }
        lst[i][trs(s[i])] = lst[lst[i][trs(s[i])]-1][trs(s[i])];
    }
    // checkF();
    cout << f[n];
    return 0;
}
