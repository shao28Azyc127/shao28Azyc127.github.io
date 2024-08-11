#include <bits/stdc++.h>
using namespace std;

int c, t, n, m, a[11], x[11], op[11][3], ans = 99999, tot[100010], op2, op3;
char ch;

bool check(){
    for(int i = 1; i <= n; i ++){
        x[i] = a[i];
    }
    for(int i = 1; i <= m; i ++){
        if(op[i][0] == -1){
            x[op[i][1]] = x[op[i][2]];
        }else if(op[i][0] == -2){
            x[op[i][1]] = -x[op[i][2]];
        }else if(op[i][0] == -3){
            x[op[i][1]] = 1;
        }else if(op[i][0] == -4){
            x[op[i][1]] = 0;
        }else if(op[i][0] == -5){
            x[op[i][1]] = -1;
        }
    }
    for(int i = 1; i <= n; i ++){
        if(x[i] != a[i]){
            return false;
        }
    }
    return true;
}

void dfs(int step){
    if(step > n){
        if(check()){
            int cnt = 0;
            for(int i = 1; i <= n; i ++){
                if(a[i] == 0){
                    cnt ++;
                }
            }
 //           cout << ans << " " << cnt << endl;
            ans = min(ans, cnt);
        }
        return;
    }
    for(int i = -1; i <= 1; i ++){
        a[step] = i;
        dfs(step + 1);
    }
}

int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d%d", &c, &t);
    if(c == 1 || c == 2){
        while(t --){
                ans = 99999;
            memset(a, 0, sizeof a);
            memset(x, 0, sizeof x);
            memset(op, 0, sizeof op);
            scanf("%d%d", &n, &m);
            for(int i = 1; i <= m; i ++){
                cin >> ch;
                if(ch == '+'){
                    op[i][0] = -1;
                    scanf("%d%d", &op[i][1], &op[i][2]);
                }else if(ch == '-'){
                    op[i][0] = -2;
                    scanf("%d%d", &op[i][1], &op[i][2]);
                }else if(ch == 'T'){
                    op[i][0] = -3;
                    scanf("%d", &op[i][1]);
                }else if(ch == 'U'){
                    op[i][0] = -4;
                    scanf("%d", &op[i][1]);
                }else if(ch == 'F'){
                    op[i][0] = -5;
                    scanf("%d", &op[i][1]);
                }
            }
            dfs(1);
            if(ans == 99999){
                printf("%d\n", n);
            }
            printf("%d\n", ans);
        }
    }else if(c == 3 || c == 4){
        while(t --){
            ans = 0;
            scanf("%d%d", &n, &m);
            op2 = 0;
            memset(tot, 0, sizeof tot);
            for(int i = 1; i <= m; i ++){
                cin >> ch;
                scanf("%d", &op2);
                if(ch == 'T'){
                    tot[op2] = 1;
                }else if(ch == 'U'){
                    tot[op2] = 2;
                }else if(ch == 'F'){
                    tot[op2] = 3;
                }
            }
            for(int i = 1; i <= n; i ++){
                if(tot[i] == 2){
                    ans ++;
                }
            }
            printf("%d\n", ans);
        }
    }else if(c == 5 || c == 6){
        while(t --){
            ans = 0;
            scanf("%d%d", &n, &m);
            memset(tot, 0, sizeof tot);
            for(int i = 1; i <= m; i ++){
                cin >> ch;
                if(ch == 'U'){
                    scanf("%d", &op2);
                    tot[op2] = 1;
                vis[op2] = true;
                }else if(ch == '+'){
                    scanf("%d%d", &op2, &op3);
                    tot[op2] = tot[op3];
                }
            }
            for(int i = 1; i <= n; i ++){
                if(tot[i] == 1){
                    ans ++;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
