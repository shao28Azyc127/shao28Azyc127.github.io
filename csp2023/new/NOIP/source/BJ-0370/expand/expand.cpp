// Now I am having a big meal.
// I'd like to call it, A Bite of NOIP.
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

int x[4000010], y[4000010];
int tx[4000010], ty[4000010];
int lx[4000010], ly[4000010];
bool flag = 0;
int len;
int c, n, m, Q;

void dfs2(int step, int now)
{
    if(flag) return;
    if(step == m)
    {
        for(int i = now+1;i <= len;i++) ly[i] = ty[step];
        return;
    }
    for(int i = 1;i <= n;i++)
    {
        ly[now+i] = ty[step];
        dfs2(step+1, now+i);
    }
}

void dfs(int step, int now)
{
    if(flag) return;
    if(step == n)
    {
        for(int i = now+1;i <= len;i++) lx[i] = tx[step];
        dfs2(1, 0);
        for(int i = 2;i <= len;i++)
        {
            if((lx[i]-ly[i]) * (lx[i-1]-ly[i-1]) < 0) return;
        }
        flag = 1;
        return;
    }
    for(int i = 1;i <= m;i++)
    {
        lx[now+i] = tx[step];
        dfs(step+1, now+i);
    }
}

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &Q);
    len = n*m;
    if(c == 1)
    {
        while(Q--) printf("1");
    }
    else if(c == 2)
    {
        for(int i = 1;i <= n;i++)
        {
            scanf("%d", &x[i]);
            tx[i] = x[i];
        }
        for(int i = 1;i <= m;i++)
        {
            scanf("%d", &y[i]);
            ty[i] = y[i];
        }
        if((tx[1]-ty[1]) * (tx[n]-ty[n]) >= 0) printf("1");
        else printf("0");
        while(Q--)
        {
            for(int i = 1;i <= n;i++)
                tx[i] = x[i];
            for(int i = 1;i <= m;i++)
                ty[i] = y[i];
            int a,b;
            scanf("%d%d", &a, &b);
            for(int i = 1;i <= a;i++)
            {
                int p,v;
                scanf("%d%d", &p, &v);
                tx[p] = v;
            }
            for(int i = 1;i <= b;i++)
            {
                int p,v;
                scanf("%d%d", &p, &v);
                ty[p] = v;
            }
            if((tx[1]-ty[1]) * (tx[n]-ty[n]) >= 0) printf("1");
            else printf("0");
        }
    }
    else
    {
        for(int i = 1;i <= n;i++)
        {
            scanf("%d", &x[i]);
            tx[i] = x[i];
        }
        for(int i = 1;i <= m;i++)
        {
            scanf("%d", &y[i]);
            ty[i] = y[i];
        }
        flag = 0;
        dfs(1, 0);
        if(flag) printf("1");
        else printf("0");
        while(Q--)
        {
            for(int i = 1;i <= n;i++)
                tx[i] = x[i];
            for(int i = 1;i <= m;i++)
                ty[i] = y[i];
            int a,b;
            scanf("%d%d", &a, &b);
            for(int i = 1;i <= a;i++)
            {
                int p,v;
                scanf("%d%d", &p, &v);
                tx[p] = v;
            }
            for(int i = 1;i <= b;i++)
            {
                int p,v;
                scanf("%d%d", &p, &v);
                ty[p] = v;
            }
            flag = 0;
            dfs(1, 0);
            if(flag) printf("1");
            else printf("0");
        }
    }
    return 0;
}
