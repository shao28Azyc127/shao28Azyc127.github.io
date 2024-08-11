#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

struct node
{
    bool sign; // 0: !id, 1: id
    int id; // 1-n: position of x, 0:T, -1:F, -2:U
}a[100010];
bool vis[100010];
int st[100010];
int ans;
int n, m;

void dfs(int step, int cnt)
{
    if(cnt >= ans) return;
    if(step > n)
    {
        for(int i = 1;i <= n;i++)
        {
            if(vis[i]) continue;
            if(a[i].sign && st[i] != st[a[i].id]) return;
            else if(!a[i].sign)
            {
                if(st[a[i].id] == 0 && st[i] != -1) return;
                else if(st[a[i].id] == -1 && st[i] != 0) return;
                else if(st[a[i].id] == -2 && st[i] != -2) return;
            }
        }
        ans = cnt;
        return;
    }
    if(vis[step])
    {
        dfs(step+1, cnt);
        return;
    }
    st[step] = 0;
    dfs(step+1, cnt);
    st[step] = -1;
    dfs(step+1, cnt);
    st[step] = -2;
    dfs(step+1, cnt+1);
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c, Q;
    scanf("%d %d\n", &c, &Q);
    while(Q--)
    {
        scanf("%d %d\n", &n, &m);
        for(int i = 1;i <= n;i++)
        {
            a[i] = {1,i};
            vis[i] = 0;
        }
        for(int i = 1;i <= m;i++)
        {
            char op;
            scanf("%c ", &op);
            if(op == 'T'){
                int t;
                scanf("%d ", &t);
                a[t] = {1, 0};
            }
            else if(op == 'F'){
                int t;
                scanf("%d ", &t);
                a[t] = {1, -1};
            }
            else if(op == 'U'){
                int t;
                scanf("%d ", &t);
                a[t] = {1, -2};
            }
            else if(op == '+'){
                int u, v;
                scanf("%d %d ", &u, &v);
                a[u] = {a[v].sign, a[v].id};
            }
            else{
                int u, v;
                scanf("%d %d ", &u, &v);
                a[u] = {!a[v].sign, a[v].id};
            }
        }
        bool bl = 1;
        int cnt = 0;
        while(bl)
        {
            bl = 0;
            for(int i = 1;i <= n;i++)
            {
                if(vis[i]) continue;
                if(a[i].sign && a[i].id <= 0)
                {
                    bl = 1;
                    vis[i] = 1;
                    st[i] = a[i].id;
                }
                if(!a[i].sign && a[i].id <= 0)
                {
                    bl = 1;
                    vis[i] = 1;
                    if(a[i].id == 0) {a[i] = {1, -1};st[i] = -1;}
                    else if(a[i].id == -1) {a[i] = {1, 0};st[i] = 0;}
                    else if(a[i].id == -2) {a[i] = {1, -2};st[i] = -2;}
                }
                if(a[i].id > 0 && vis[a[i].id])
                {
                    bl = 1;
                    vis[i] = 1;
                    if(a[i].sign) {a[i] = {1, a[a[i].id].id}; st[i] = a[a[i].id].id;}
                    else
                    {
                        if(a[a[i].id].id == 0) {a[i] = {1, -1};st[i] = -1;}
                        else if(a[a[i].id].id == -1) {a[i] = {1, 0};st[i] = 0;}
                        else if(a[a[i].id].id == -2) {a[i] = {1, -2};st[i] = -2;}
                    }
                }
                if(a[i].id == -2) cnt++;
            }
        }
        ans = 1e9;
        dfs(1,0);
        printf("%d\n", cnt+ans);
    }
    return 0;
}
