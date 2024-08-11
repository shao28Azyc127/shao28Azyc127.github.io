#include<iostream>
#include<cstring>
using namespace std;
int n,a[200005],sz,ans,col;
bool d[200005],vis[200005],l[400001],flag;
int cnt,nxt[400001],to[400001],head[200005];
void add(int x,int y,int z)
{
    //cout << "add " << x << " " << y << endl;
    to[++cnt] = y;
    l[cnt] = z;
    nxt[cnt] = head[x];
    head[x] = cnt;
}
void work(int x)
{
    //cout << x << " " << head[x] << endl;
    if(x <= n) sz++;
    vis[x] = 1;
    for(int i = head[x];i;i = nxt[i])
        if(!vis[to[i]])
        {
            //cout << to[i] << endl;
            if(l[i]) d[to[i]] = !d[x];
            else d[to[i]] = d[x];
            work(to[i]);
        }
        else
        {
            bool nxtd;
            if(l[i]) nxtd = !d[x];
            else nxtd = d[x];
            if(nxtd != d[to[i]]) flag = 1;
        }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--)
    {
        cnt = 0;
        memset(head,0,sizeof(head));
        memset(vis,0,sizeof(vis));
        memset(d,0,sizeof(d));
        int m,x = 0,y = 0;
        char op;
        cin >> n >> m;
        for(int i = 1;i <= n;i++) a[i] = i;
        for(int i = 1;i <= m;i++)
        {
            //cout << i << endl;
            cin >> op;
            if(op == '+')
            {
                cin >> x >> y;
                a[x] = a[y];
            }
            else if(op == '-')
            {
                cin >> x >> y;
                a[x] = (a[y]>n ? a[y]-n : a[y]+n);
            }
            else
            {
                cin >> x;
                if(op == 'T') a[x] = 2*n+1;
                else if(op == 'F') a[x] = 2*n+2;
                else a[x] = 2*n+3;
            }
        }
        for(int i = 1;i <= n;i++)
        {
            //cout << i << " " << a[i] << endl;
            add(i,a[i],0); add(a[i],i,0);
            add(i,n+i,1); add(n+i,i,1);
        }
        ans = sz = 0;
        work(2*n+3);
        ans += sz;
        for(int i = 1;i <= n;i++)
            if(!vis[i])
            {
                flag = sz = 0;
                work(i);
                ans += flag*sz;
            }
        cout << ans << endl;
    }
    return 0;
}
