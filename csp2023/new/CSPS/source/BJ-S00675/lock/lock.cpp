#include <bits/stdc++.h>

using namespace std;
int n, x[10][6];
int now[6], ans = 0;
int t[6];
bool check1(int a[], int b[]){
    int cnt = 0;
    for (int i = 1; i <= 5; i++)
        if (a[i] != b[i]) cnt++;
    return cnt == 1;
}
bool judge(int p1, int p2, int q1, int q2){
    if (p1 <= q1){
        int d = q1 - p1;
        return ((p2 + d) % 10 == q2);
    }
    else{
        int d = p1 - q1;
        return ((q2 + d) % 10 == p2);
    }
}
bool check2(int a[], int b[]){
    int f = 0, g = 0, p1 = 0, p2 = 0, q1 = 0, q2 = 0;
    for (int i = 1; i <= 5; i++)
        if (a[i] != b[i]) f++;
    for (int i = 1; i < 5; i++)
        if (a[i] != b[i] && a[i + 1] != b[i + 1]){
            g++;
            p1 = a[i], p2 = a[i + 1];
            q1 = b[i], q2 = b[i + 1];
        }
    if (!(f == 2 && g == 1)) return false;
    return judge(p1, p2, q1, q2);
}
void dfs(int step){
    if (step > 5){
        bool flag = true;
        for (int i = 1; i <= n; i++){
            flag &= (check2(now, x[i])||check1(now, x[i]));
        }
        ans += (int)flag;
        return;
    }
    for (int i = 0; i <= 9; i++){
        now[step] = i;
        dfs(step + 1);
    }
}
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 5; j++)
            scanf("%d", &x[i][j]);
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
