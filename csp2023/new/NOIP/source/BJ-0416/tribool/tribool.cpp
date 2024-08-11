#include <bits/stdc++.h>
using namespace std;
int c,t,n,m,val[200010],f[200010];
int ox[200010];
vector <int> v[200010];
void init()
{
    for(int i = 1;i <= 2 * n;i++) f[i] = i;
}
int getf(int x) { return x == f[x] ? x : f[x] = getf(f[x]); }
void merge(int x,int y) { int t1 = getf(x),t2 = getf(y); f[t2] = t1; }
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    if(c == 3 || c == 4)
    {
        while(t--)
        {
            int ans = 0;
            scanf("%d%d",&n,&m);
            for(int i = 1;i <= n;i++) val[i] = -1;
            for(int i = 1;i <= m;i++)
            {
                char op;
                int x;
                cin >> op >> x;
                if(op == 'T') val[x] = 1;
                else if(op == 'F') val[x] = 0;
                else val[x] = -1;
            }
            for(int i = 1;i <= n;i++)
            {
                if(val[i] == -1) ans++;
            }
            cout << ans << "\n";
        }
        return 0;
    }
    if(c == 7 || c == 1 || c == 2)
    {
        while(t--)
        {
            int ans = 0;
            scanf("%d%d",&n,&m);
            for(int i = 1;i <= 2 * n;i++) ox[i] = i;
            for(int i = 1;i <= m;i++)
            {
                char op;
                int x,y;
                cin >> op;
                if(op == '+')
                {
                    cin >> x >> y;
                    vector <int> tmp;
                    for(int j = 0;j < v[ox[x]].size();j++)
                    {
                        if(v[ox[x]][j] == x) continue;
                        tmp.push_back(v[ox[x]][j]);
                    }
                    v[ox[x]].clear();
                    for(int j = 0;j < tmp.size();j++) v[ox[x]].push_back(tmp[j]);
                    if(ox[x] != x) for(int j = 0;j < v[x].size();j++) v[ox[x]].push_back(v[x][j]),ox[v[x][j]] = ox[x];
                    v[x].clear();
                    tmp.clear();
                    for(int j = 0;j < v[ox[x + n]].size();j++)
                    {
                        if(v[ox[x + n]][j] == x) continue;
                        tmp.push_back(v[ox[x + n]][j]);
                    }
                    v[ox[x]].clear();
                    for(int j = 0;j < tmp.size();j++) v[ox[x + n]].push_back(tmp[j]);
                    if(ox[x + n] != x + n) for(int j = 0;j < v[x + n].size();j++) v[ox[x + n]].push_back(v[x + n][j]),ox[v[x + n][j]] = ox[x + n];
                    v[x + n].clear();
                    ox[x] = y,ox[x + n] = ox[y + n];
                    v[ox[x]].push_back(x),v[ox[x + n]].push_back(x + n);
                }
                else
                {
                    cin >> x >> y;
                    vector <int> tmp;
                    for(int j = 0;j < v[ox[x]].size();j++)
                    {
                        if(v[ox[x]][j] == x) continue;
                        tmp.push_back(v[ox[x]][j]);
                    }
                    v[ox[x]].clear();
                    for(int j = 0;j < tmp.size();j++) v[ox[x]].push_back(tmp[j]);
                    if(ox[x] != x) for(int j = 0;j < v[x].size();j++) v[ox[x]].push_back(v[x][j]),ox[v[x][j]] = ox[x];
                    v[x].clear();
                    tmp.clear();
                    for(int j = 0;j < v[ox[x + n]].size();j++)
                    {
                        if(v[ox[x + n]][j] == x) continue;
                        tmp.push_back(v[ox[x + n]][j]);
                    }
                    v[ox[x + n]].clear();
                    for(int j = 0;j < tmp.size();j++) v[ox[x + n]].push_back(tmp[j]);
                    if(ox[x + n] != x + n) for(int j = 0;j < v[x + n].size();j++) v[ox[x + n]].push_back(v[x + n][j]),ox[v[x + n][j]] = ox[x + n];
                    v[x + n].clear();
                    ox[x] = y + n,ox[x + n] = y;
                    v[ox[x]].push_back(x),v[ox[x + n]].push_back(x + n);
                }
            }
            init();
            for(int i = 1;i <= 2 * n;i++) merge(i,ox[i]);
            for(int i = 1;i <= n;i++)
            {
                if(getf(i) == getf(i + n)) ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
