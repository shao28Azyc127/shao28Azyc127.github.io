#include <bits/stdc++.h>
using namespace std;
int n,m,a[3010];
struct node
{
    string s;
    int id;
    bool operator < (const node nd) const { return s < nd.s; }
} p[3010];
string nw[3010],nm[3010],pre[3010],bac[3010];
char ch[3010][3010];
bool cmp(char c1,char c2) { return c1 < c2; }
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> p[i].s;
        for(int j = 0;j < m;j++) ch[i][j] = p[i].s[j];
        sort(ch[i],ch[i] + m,cmp);
        p[i].id = i;
        for(int j = 0;j < m;j++) nw[i] += ch[i][j];
        for(int j = m - 1;j >= 0;j--) nm[i] += ch[i][j];
    }
    pre[1] = nm[1];
    for(int i = 2;i <= n;i++)
    {
        if(pre[i - 1] > nm[i]) pre[i] = nm[i];
        else pre[i] = pre[i - 1];
    }
    bac[n] = nm[n];
    for(int i = n - 1;i >= 1;i--)
    {
        if(bac[i + 1] > nm[i]) bac[i] = nm[i];
        else bac[i] = bac[i + 1];
    }
    sort(p + 1,p + n + 1);
    for(int i = 1;i <= n;i++)
    {
        if(p[i].id == n)
        {
            if(nw[p[i].id] < pre[p[i].id - 1]) a[p[i].id] = 1;
        }
        else if(p[i].id == 1)
        {
            if(nw[p[i].id] < bac[p[i].id + 1]) a[p[i].id] = 1;
        }
        else
        {
            if(nw[p[i].id] < pre[p[i].id - 1] && nw[p[i].id] < bac[p[i].id + 1]) a[p[i].id] = 1;
        }
    }
    for(int i = 1;i <= n;i++) cout << a[i];
    return 0;
}
