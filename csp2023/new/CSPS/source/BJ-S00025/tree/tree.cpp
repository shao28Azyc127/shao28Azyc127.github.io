#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n;
int ans = 0;
int cnt1= 0;
bool bfskey = false;
queue<int> q;
struct edge
{
    int to[maxn];
    int cnt;
}edges[maxn];

struct newnode
{
    int a;
    int b;
    int c;
    int t = 0;
    bool flag = false;
}node[maxn];

int values(int i)
{
    return max(node[i].b + (node[i].t * node[i].c),1);
}

inline void days(int i)
{
    int day = 0;
    int now = 0;
    while (node[i].a > now)
    {
        day++;
        node[i].t++;
        now = now + values(i);
    }
    node[i].t = 0;
    node[i].a = day;
}

inline void bfs()
{
    int now[2][2];
    q.push(1);
    while(!q.empty())
    {
        if (bfskey == true) return;
        for (int i = 1;i <= edges[q.front()].cnt;i++)
        {
            int nnext = edges[q.front()].to[i];
            if (node[nnext].flag == false)
            {
                if (node[nnext].a > now[1][0])
                {
                    now[1][0] = node[nnext].a;
                    now[1][1] = i;
                }
            }
            else q.push(nnext);
        }
        q.pop();
    }
    node[now[1][1]].flag = true;
}


int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1;i <= n;i++)
    {
        scanf("%d%d%d",&node[i].a,&node[i].b,&node[i].c);
        days(i);
    }
    for (int i = 1;i <= n - 1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        edges[a].cnt++;
        edges[b].cnt++;
        edges[a].to[edges[a].cnt] = b;
        edges[b].to[edges[b].cnt] = a;

    }
    ans++;
    node[1].flag = true;
    int cnt = 0;
    bool out = false;
    while(!out)
    {
        bfs();
        ans++;
        for (int i = 1;i <= n;i++)
        {
            if (node[i].flag == true)
            {
                node[i].t++;
            }
            if (node[i].a == node[i].t)
            {
                cnt++;
            }
            if (node[i].flag == true)
            {
                cnt1++;
            }
        }
        if(cnt == n) out = true;
        else cnt = 0;
        if(cnt1 == n) bfskey = true;
        else cnt1 = 0;
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
