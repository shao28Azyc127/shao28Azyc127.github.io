# include <bits/stdc++.h>
# define maxn 3005
# define int long long
using namespace std;
char a[maxn][maxn];
char s[maxn][maxn];
char b[maxn][maxn];
bool ans[maxn];
int n, m, pos;
string zuixiao, cixiao;
bool cmp1(char a, char b)
{
    return (a < b);
}
bool cmp2(char a, char b)
{
    return (a > b);
}
signed main()
{
    freopen("dict.in","r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            s[i][j] = a[i][j];
            b[i][j] = a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        sort(s[i] + 1, s[i] + m + 1, cmp1);
        sort(b[i] + 1, b[i] + m + 1, cmp2);
    }
    for(int i = 1; i <= m; i++) zuixiao += 'z';
    for(int i = 1; i <= n; i++){
        string a = "";
        for(int j = 1; j <= m; j++) a += b[i][j];
        if(a < zuixiao) zuixiao = a, pos = i;
    }
    for(int i = 1; i <= m; i++) cixiao += 'z';
    for(int i = 1; i <= n; i++){
        if(i == pos) continue;
        string a = "";
        for(int j = 1; j <= m; j++) a += b[i][j];
        if(a < cixiao) cixiao = a;
    }
    for(int i = 1; i <= n; i++){
        string a;
        for(int j = 1; j <= m; j++) a += s[i][j];
        if(i == pos) ans[i] = (a < cixiao);
        else ans[i] = (a < zuixiao);
    }
    for(int i = 1; i <= n; i++) cout << ans[i];
    cout << endl;
    return 0;
}
