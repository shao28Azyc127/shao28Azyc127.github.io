#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
int n, m, box[N][26]; string s[N]; bool have[N][26];
// bool ans, vis[N];
// void dfs(int x, string p) {
//     if(x == n) {
//         for(int i = 1; i <= n; i++)
//     }
// }
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> s[i];
    // for(int i = 1; i <= n; i++)
    //     for(int j = 0; j < m; j++)
    //         box[i][s[j]-'a']++;
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j < 26; j++) {
    //         if(!box[i][j]) continue ;
    //         for(int k = 0; k < j; k++)
    //             have[i][k] = true;       
    //     }
    // }
    // for(int i = 1; i <= n; i++) {
    //     bool 
    //     for(int j = 1; j <= n; j++) {
    //         if(i == j) continue ;
    //     }
    // }
    if(n == 1 && m == 1) printf("1\n");
    else if(m == 1) {
        string t[N];
        for(int i = 1; i <= n; i++) t[i] = s[i];
        sort(t + 1, t + n + 1);
        char p = t[1][0];
        if(t[2][0] == p) {
            for(int i = 1; i <= n; i++) printf("0");
            printf("\n");
            return 0;
        }
        for(int i = 1; i <= n; i++)
            if(s[i][0] == p) printf("1");
            else printf("0");
    }
    else if(m == 2) {
        for(int i = 1; i <= n; i++) {
            bool flag = true;
            string s1 = s[i];
            for(int j = 1; j <= n; j++) {
                if(i == j) continue ;
                string t1 = s[j], t2 = s[j]; swap(t2[0], t2[1]);
                if(s1 >= t1 && s1 >= t2) {
                    flag = false;
                    break;
                }
            }
            bool flag2 = true; swap(s1[0], s1[1]);
            for(int j = 1; j <= n; j++) {
                if(i == j) continue ;
                string t1 = s[j], t2 = s[j]; swap(t2[0], t2[1]);
                if(s1 >= t1 && s1 >= t2) {
                    flag2 = false;
                    break;
                }
            }
            if(flag || flag2) printf("1");
            else printf("0");
        }
    }
    else {
        string t[N];
        for(int i = 1; i <= n; i++) t[i] = s[i];
        for(int i = 1; i <= n; i++) sort(s[i].begin(), s[i].end());
        for(int i = 1; i <= n; i++) sort(t[i].begin(), t[i].end(), greater <char> ());
        for(int i = 1; i <= n; i++) {
            bool flag = true;
            for(int j = 1; j <= n; j++) {
                if(i == j) continue ;
                if(s[i] >= t[j]) {
                    flag = false;
                    break ;
                }
            }
            if(flag) printf("1");
            else printf("0");
        }
    }
    return 0;
}