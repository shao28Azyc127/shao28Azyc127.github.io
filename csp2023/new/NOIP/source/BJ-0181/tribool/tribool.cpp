#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

const int N = 1e5 + 5;
int c, T, n, m, inq[N], fa[N], ans, u, v, sz[N];
char opt, cnt[N];
bool tot[N], incir[N];
stack <int> st;
vector <int> e[N];

void find_circle(int x, int lyh)
{
    if(inq[x])
    {
        if(inq[x] == lyh)
        {
            incir[x] = true;
            while(!st.empty() && st.top() != x)
            {
                incir[st.top()] = true;
                st.pop();
            }
        }
        return ;
    }
    inq[x] = lyh;
    st.push(x);
    find_circle(fa[x], lyh);
    return ;
}

int dp(int x)
{
    sz[x] = 1;
    for(int i = 0;i < e[x].size();i++)
    {
        if(incir[e[x][i]])
            continue;
        sz[x] += dp(e[x][i]);
    }
    return sz[x];
}

void solve(int x)
{
    if(fa[x] == x)
    {
        if(cnt[x] == 'U' || tot[x])
            ans += sz[x];
        return ;
    }
    int y = fa[x];
    int wzx = tot[x];
    int lyh = sz[x];
    inq[x] = true;
    while(y != x)
    {
        wzx += tot[y];
        lyh += sz[y];
        inq[y] = true;
        y = fa[y];
    }
    if(wzx % 2)
        ans += lyh;
    return ;
}

char did(char lhx)
{
    if(lhx == 'U')
        return lhx;
    return lhx == 'T' ? 'F' : 'T';
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d %d", &c ,&T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0;i <= n;i++)
            fa[i] = i, inq[i] = false, tot[i] = false, cnt[i] = ' ', sz[i] = 0, incir[i] = false, e[i].clear();
        ans = 0;
        for(int i = 1;i <= m;i++)
        {
            cin >> opt;
            if(opt == '-')
            {
                scanf("%d %d", &u, &v);
                if(fa[v] == v)
                {
                    if(cnt[v] != ' ')
                    {
                        fa[u] = u;
                        tot[u] = false;
                        cnt[u] = did(cnt[v]);
                    }
                    else
                    {
                        fa[u] = fa[v];
                        tot[u] = !tot[v];
                        cnt[u] = ' ';
                    }
                }
                else
                {
                    fa[u] = fa[v];
                    tot[u] = !tot[v];
                    cnt[u] = ' ';
                }
            }
            else if(opt == '+')
            {
                scanf("%d %d", &u, &v);
                if(fa[v] == v)
                {
                    if(cnt[v] != ' ')
                    {
                        fa[u] = u;
                        tot[u] = false;
                        cnt[u] = cnt[v];
                    }
                    else
                    {
                        fa[u] = fa[v];
                        tot[u] = tot[v];
                        cnt[u] = ' ';
                    }
                }
                else
                {
                    fa[u] = fa[v];
                    tot[u] = tot[v];
                    cnt[u] = ' ';
                }
            }
            else
            {
                scanf("%d", &u);
                fa[u] = u;
                tot[u] = false;
                cnt[u] = opt;
            }
        }
        for(int i = 1;i <= n;i++)
            e[fa[i]].push_back(i);
        for(int i = 1;i <= n;i++)
        {
            if(inq[i])
                continue;
            while(!st.empty())  st.pop();
            find_circle(i, i);
        }
        for(int i = 1;i <= n;i++)
            if(incir[i])
                dp(i);
        for(int i = 1;i <= n;i++)   inq[i] = false;
        for(int i = 1;i <= n;i++)
        {
            if(incir[i] && !inq[i])
                solve(i);
        }
        /*
        for(int i = 1;i <= n;i++)
            printf("%d ", incir[i]);
        printf("\n");
        for(int i = 1;i <= n;i++)
            printf("%d ", sz[i]);
        printf("\n");
        */
        printf("%d\n", ans);
    }
    return 0;
}

