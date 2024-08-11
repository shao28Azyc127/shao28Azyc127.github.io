#include <bits/stdc++.h>
using namespace std;

int n, m, t[3100][30];
int check(int* s1, int* s2) {
    for(int i = 1; i <= m; i++) {
        if(s1[i] != s2[i]) return s1[i] < s2[i];
    } return 0;
}
int mins[3100], mins2[2100], ks1, ks2;
int now[3100], tot;
int main() {
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d", &n, &m);
    if(n == 1) { printf("1"); return 0; }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            char ch; scanf(" %c", &ch);
            t[i][ch - 'a' + 1]++;
        }
    for(int i = 1; i <= m; i++) mins[i] = mins2[i] = 30;
    for(int i = 1; i <= n; i++) {
        tot = 0; int flag1 = 1, flag2 = 1;
        for(int j = 26; j >= 1; j--)
            for(int k = 1; k <= t[i][j]; k++)
                now[++tot] = j;
        if(check(now, mins)) {
            for(int j = 1; j <= m; j++)
                mins2[j] = mins[j], mins[j] = now[j];
            ks2 = ks1, ks1 = i;
        }else if(check(now, mins2)) {
            for(int j = 1; j <= m; j++)
                mins2[j] = now[j];
            ks2 = i;
        }
    }
    for(int i = 1; i <= n; i++) {
        tot = 0;
        for(int j = 1; j <= 26; j++)
            for(int k = 1; k <= t[i][j]; k++)
                now[++tot] = j;
        int flag = (i == ks1) ? check(now, mins2) : check(now, mins);
        printf("%d", flag);
    } putchar('\n');
    return 0;
}
