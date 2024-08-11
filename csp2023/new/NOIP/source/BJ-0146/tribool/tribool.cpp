# include <bits/stdc++.h>
# define int long long
# define maxn 100005
using namespace std;
int c, t, n, m, ans;
char a[maxn], b[maxn];
map <char, char> fan;
struct operate{
    char ty; int i, j;
}opt[maxn];
bool check()
{
    for(int i = 1; i <= n; i++){
        b[i] = a[i];
    }
    for(int i = 1; i <= m; i++){
        if(opt[i].ty == 'U' || opt[i].ty == 'T' || opt[i].ty == 'F'){
            b[opt[i].i] = opt[i].ty;
        }
        if(opt[i].ty == '+'){
            b[opt[i].i] = b[opt[i].j];
        }
        if(opt[i].ty == '-'){
            b[opt[i].i] = fan[b[opt[i].j]];
        }
    }
    for(int i = 1; i <= n; i++){
        if(b[i] != a[i]) return 0;
    }
    return 1;
}
void dfs(int i, int cnt)
{
    if(i == n + 1){
        if(check()) ans = min(ans, cnt);
        return;
    }
    a[i] = 'T';
    dfs(i + 1, cnt);
    a[i] = 'F';
    dfs(i + 1, cnt);
    a[i] = 'U';
    dfs(i + 1, cnt + 1);
}
void sol1()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> opt[i].ty;
        if(opt[i].ty == 'U' || opt[i].ty == 'T' || opt[i].ty == 'F') cin >> opt[i].i;
        if(opt[i].ty == '+' || opt[i].ty == '-') cin >> opt[i].i >> opt[i].j;
    }
    ans = n;
    dfs(1, 0);
    cout << ans << endl;
}
void sol2()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) a[i] = 'T';
    for(int i = 1; i <= m; i++){
        cin >> opt[i].ty >> opt[i].i;
        a[opt[i].i] = opt[i].ty;
    }
    ans = 0;
    for(int i = 1; i <= n; i++)
        if(a[i] == 'U') ans++;
    cout << ans << endl;
}
void sol3()
{
    cin >> n >> m; ans = 0;
    for(int i = 1; i <= m; i++){
        cin >> opt[i].ty;
        if(opt[i].ty == 'U') cin >> opt[i].i;
        if(opt[i].ty == '+') cin >> opt[i].i >> opt[i].j;
    }
    for(int i = 1; i <= n; i++) a[i] = 'T', b[i] = 'T';
    while(1){
        int cnt = 0;
        for(int i = 1; i <= m; i++) {
            if(opt[i].ty == '+') {
                b[opt[i].i] = b[opt[i].j];
            }
            if(opt[i].ty == 'U'){
                b[opt[i].i] = opt[i].ty;
            }
        }
        for(int i = 1; i <= n; i++){
            if(a[i] != b[i]) cnt++;
            a[i] = b[i];
        }
        if(!cnt) break;
    }
    for(int i = 1; i <= n; i++) if(a[i] == 'U') ans++;
    cout << ans << endl;
}
signed main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    fan['U'] = 'U';
    fan['T'] = 'F';
    fan['F'] = 'T';
    ios::sync_with_stdio(0);
    cin >> c >> t;
    if(c == 1 || c == 2){
        while(t--)sol1();
    }
    if(c == 3 || c == 4){
        while(t--)sol2();
    }
    if(c == 5 || c == 6){
        while(t--)sol3();
    }
    return 0;
}
/*
dalao field_and_forest must have already aked noip.

luogu uid:760445.

*/
