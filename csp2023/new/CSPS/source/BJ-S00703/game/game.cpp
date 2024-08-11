#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e6 + 5;
char s[maxn], ss[maxn];
int RL[maxn];
void manacher(int n){
    int pos = 0, R = 0;
    for (int i = 1; i <= n; i++){
        if (i <= R)
            RL[i] = min(RL[2 * pos - i], R - i + 1);
        else 
            RL[i] = 1;
        while (ss[i + RL[i]] == ss[i - RL[i]] && i - RL[i] > 0)
            RL[i]++;
        if (i + RL[i] - 1 >= R){
            R = i + RL[i] - 1;
            pos = i;
        }
    }
}
int a[maxn], b[maxn], f[maxn];
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;  
    cin >> s + 1;
    for (int i = 1; i <= 2 * n + 1; i++){
        if (i % 2)
            ss[i] = '#';
        else
            ss[i] = s[i / 2]; 
    }
    manacher(2 * n + 1);
    // memset(a, 0x3f, sizeof(a));
    // for (int i = 1; i <= 2 * n + 1; i += 2){
    //     if (RL[i] > 1)
    //         a[i - RL[i] + 1] = min(a[i - RL[i] + 1], RL[i] - 1);
    // }
    // for (int i = 1; i <= 2 * n + 1; i += 2){
    //     a[i] = min(a[i], (a[i - 2] - 2 > 0) ? a[i - 2] - 2 : 0x3f3f3f3f);
    // }
    // for (int i = 1; i <= n; i++)
    //     b[i] = a[i * 2 - 1];
    memset(b, 0x3f, sizeof(b));
    for (int i = 1; i <= 2 * n + 1; i += 2){
        while (RL[i] > 1){
            b[(i - RL[i] + 2) / 2] = min(b[(i - RL[i] + 2) / 2], RL[i] - 1);
            RL[i] -= 2;
        }
    }
    for (int i = n; i >= 1; i--){
        if (i + b[i] <= n + 1)
            f[i] = f[i + b[i]] + 1;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << f[i] << ' ';
    // cout << endl;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans += f[i];
    cout << ans << endl;
    return 0;
}