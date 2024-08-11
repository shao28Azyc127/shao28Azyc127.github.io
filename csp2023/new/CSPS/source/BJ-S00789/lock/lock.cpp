#include<bits/stdc++.h>
using namespace std;
int n, a[10][10], b[10], ans, sum1, sum;
int check(){
    for(int j = 1; j < 5; j++){
        if(a[1][j] != b[j] && a[1][j + 1] == b[j + 1]) return 2;
        if(a[1][j] != b[j] && a[1][j + 1] != b[j + 1]){
            if((a[1][j] + 10 - b[j]) % 10 != (a[1][j + 1] + 10 - b[j + 1]) % 10) return 0;
            break;
        }
    }return 1;
}void dfs(int x){
    if(x > 5){
        for(int i = 1; i <= n; i++)
            if(a[i][1] == b[1] && a[i][2] == b[2] && a[i][3] == b[3] && a[i][4] == b[4] && a[i][5] == b[5]) return;
        for(int i = 1; i <= n; i++){
            sum = 0;
            for(int j = 1; j <= 5; j++) if(a[i][j] != b[j]) sum++;
            if(sum == 2) sum1++;
            if(sum >= 3) return;
            else if(sum == 2)
                for(int j = 1; j < 5; j++){
                    if(a[i][j] != b[j] && a[i][j + 1] == b[j + 1]) return;
                    if(a[i][j] != b[j] && a[i][j + 1] != b[j + 1]){
                        if((a[i][j] + 10 - b[j]) % 10 != (a[i][j + 1] + 10 - b[j + 1]) % 10) return;
                        break;
                    }
                }
        }ans++; return;
    }for(int i = 0; i < 10; i++) b[x] = i, dfs(x + 1);
}int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= 5; j++) scanf("%d", &a[i][j]);
    dfs(1);
    b[1] = 0; b[2] = 0; b[3] = 0; b[4] = 0; b[5] = 5;
    printf("%d", ans);
    return 0;
}
