#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e5+5;

int c,t,n,m,num[N],rct[N],ans = 2e9;

struct node
{
    char ch;
    int x,y;
} a[N];

void chk()
{
    for(int i=1;i<=n;i++) rct[i] = num[i];

    for(int i=1;i<=m;i++)
    {
        if(a[i].ch == '+') rct[a[i].x] = num[a[i].y];
        if(a[i].ch == '-') rct[a[i].x] = 2 - num[a[i].y];
        if(a[i].ch == 'T') rct[a[i].x] = 0;
        if(a[i].ch == 'F') rct[a[i].x] = 2;
        if(a[i].ch == 'U') rct[a[i].x] = 1;
    }

    int cnt = 0;
    bool flag = true;
    for(int i=1;i<=n;i++)
    {
        if(num[i] != rct[i])
        {
            flag = false;
            break;
        }
        if(rct[i] == 1) cnt++;
    }

    if(flag == true) ans = min(ans,cnt);
    return ;
}

void dfs(int step)
{
    if(step == n + 1)
    {
        chk();
        return ;
    }

    num[step] = 0;
    dfs(step + 1);
    num[step] = 1;
    dfs(step + 1);
    num[step] = 2;
    dfs(step + 1);
    num[step] = -1;
    return ;
}

void doans_2()
{
    ans = 0;
    for(int i=1;i<=m;i++)
    {
        if(a[i].ch == 'T') rct[a[i].x] = 0;
        if(a[i].ch == 'F') rct[a[i].x] = 2;
        if(a[i].ch == 'U') rct[a[i].x] = 1;
    }
    for(int i=1;i<=m;i++)
        if(rct[i] == 1) ans++;
    return ;
}

int f[N],sz[N];

int find(int x)
{
    if(f[x] == x) return x;
    else return f[x] = find(f[x]);
}

void merge(int x,int y)
{
    int root_x = find(x);
    int root_y = find(y);
    f[root_x] = root_y;
    sz[root_y] += sz[root_x];
    return ;
}

void doans_3()
{
    for(int i=0;i<=n;i++)
    {
        f[i] = i;
        sz[i] = 1;
    }

    for(int i=1;i<=m;i++)
    {
        if(a[i].ch == 'U' && find(a[i].x) != find(0)) merge(a[i].x,0);
        if(a[i].ch == '+' && find(a[i].x) != find(a[i].y)) merge(a[i].x,a[i].y);
    }

    cout << sz[find(0)] - 1 << endl;
    return ;
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        ans = 2e9;
        memset(num,-1,sizeof(num));
        cin >> n >> m;
        for(int i=1;i<=m;i++)
        {
            cin >> a[i].ch;
            if(a[i].ch == '+' || a[i].ch == '-')
                cin >> a[i].x >> a[i].y;
            else cin >> a[i].x;
        }
        if(c == 1 || c == 2)
        {
            dfs(1);
            cout << ans << endl;
        }
        else if(c == 3 || c == 4)
        {
            doans_2();
            cout << ans << endl;
        }
        else if(c == 5 || c == 6) doans_3();
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}
