#include<bits/stdc++.h>
using namespace std;
string s[3005];
int a[3005][3005];
int b[3005][3005];
int wa[3005], wb[3005];
//ull w[3005];
signed main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        s[i] = " " + s[i];
        for(int j = 1; j <= m; j++){
            a[i][j] = s[i][j] - 'a';
        }
    }
    for(int i = 1; i <= n; i++){
        sort(a[i] + 1, a[i] + 1 + m);
        for(int j = m; j >= 1; j--){
            b[i][m - j + 1] = a[i][j];
        }
        wa[i] = 1;
        for(int j = 2; j <= m; j++){
            if(a[i][j] == a[i][j - 1]){
                wa[i] = j;
            } else break;
        }
        wb[i] = 1;
        for(int j = 2; j <= m; j++){
            if(b[i][j] == b[i][j - 1]){
                wb[i] = j;
            } else break;
        }
    }
    for(int i = 1; i <= n; i++){
        int flag = 1;
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(a[i][1] > b[j][1]){
                flag = 0;
                break;
            }
            if(a[i][1] < b[j][1]) continue;
            if(a[i][1] == b[j][1]){
                flag = 0;
                break;
            }
        }
        cout << flag;
    }
    return 0;
}
