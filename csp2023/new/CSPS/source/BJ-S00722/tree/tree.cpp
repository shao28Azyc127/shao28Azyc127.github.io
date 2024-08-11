#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int NR = 1e5+5;
long long a[NR], b[NR], c[NR];
vector<int> g[NR];
int dep[NR];
int n;
void dfs(int x, int f)
{
    dep[x] = dep[f] + 1;
    for(int i = 0; i < g[x].size(); i++)
    {
        if(f == g[x][i]) continue;
        dfs(g[x][i], x);
    }
}
int mn[NR];
int flag[NR];
void Init(int md)
{
//cout << "Init " << md << " is begin." << endl;
    for(int i = 1; i <= n; i++)
    {
//printf("\n%d: \n", i);
        long long sum = 0;
        int day;
        for(day = 1; day <= md; day++) sum += max(b[i] + day * c[i], 1LL);
        int ans = 1;
        for(; ans <= day; ans++)
        {
            if(sum - max(b[i] + ans * c[i], 1LL) < a[i]) break;
            sum -= max(b[i] + ans * c[i], 1LL);
        }
//printf("day = %d, ans = %d\n", day, ans);
        mn[i] = max(dep[i], ans);
        flag[i] = mn[i];
    }
    sort(flag + 1, flag + n + 1);
//cout << "Init " << md << " is end." << endl << endl;
}
bool check(int mid)
{
    Init(mid);
    for(int i = 1; i <= n; i++)
    {
        if(mn[i] > mid) return false;
        if(flag[i] < i) return false;
    }
    return true;
}
void workA();
void workB();
void workD();
int main()
{
    //freopen("tree2.in", "r", stdin);
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    bool A, B, C, D;
    A = B = C = D = true;
    for(int i = 1; i <= n; i++) scanf("%lld %lld %lld", &a[i], &b[i], &c[i]), A &= (c[i] == 0);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        B &= (u == i) && (v == i+1);
        D &= (u == 1);
    }
    for(int i = 1; i <= n; i++) C &= (g[i].size() <= 2);
    dfs(1, 0);
    if(B || C){workB();return 0;}
    //else if(A){workA();return 0;}
    //else if(D){workD();return 0;}
    int l = 1, r = 1e7 / n * 10 + 1;
    while(l < r)
    {
        int mid = l + ((r - l) >> 1);
        bool ck = check(mid);
//cout << l << " " << r << " " << mid <<endl;
        if(ck) r = mid-1;
        else l = mid + 1;
//printf("check(%d) = %d\n\n", mid, ck);
    }
//cout << l << " " << r << endl;
    cout << l + 1 << endl;
    return 0;
}
void workA()
{

}
void workB()
{
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int now = i-1;
        long long sum = 0;
        while(true)
        {
            if(sum >= a[i]) break;
            now++;
            sum += max(b[i] + now * c[i], 1LL);
        }
        ans = max(ans, now);
    }
    cout << ans << endl;
}
void workD()
{

}
