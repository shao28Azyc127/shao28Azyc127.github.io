#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
long long a[100001];
int b[100001],c[100001],t[100001],ti[100001];
vector<int> v[100001];
long long SUM(int x,int y) {return 1ll*(x+y)*(y-x+1)/2;}
int ceil(int x,int y)
{
    if(x % y == 0) return x/y;
    return x/y+1;
}
long long f(int x,int p1,int p2)
{
    long long res = 0;
    if(p2 >= t[x])
    {
        res = p2-t[x]+1;
        p2 = t[x]-1;
    }
    if(c[x] && 1000000000000000000/c[x] < SUM(p1,p2)) return 1000000000000000000;
    return res+1ll*b[x]*(p2-p1+1)+SUM(p1,p2)*c[x];
}
int calc(int x,int p)
{
    int l = 1,r = p;
    while(l < r)
    {
        int mid = (l+r+1)/2;
        if(f(x,mid,p) >= a[x]) l = mid;
        else r = mid-1;
    }
    return l;
}
struct node
{
    int x,d;
};
bool operator <(node x,node y) {return x.d > y.d;}
bool vis[100001];
bool check()
{
    priority_queue<node> q;
    memset(vis,0,sizeof(vis));
    q.push((node){1,ti[1]});
    vis[1] = 1;
    int T = 1;
    while(!q.empty())
    {
        int u = q.top().x;
        q.pop();
        if(ti[u] < T) return 0;
        T++;
        for(int i = 0;i < v[u].size();i++)
            if(!vis[v[u][i]])
            {
                q.push((node){v[u][i],ti[v[u][i]]});
                vis[v[u][i]] = 1;
            }
    }
    return 1;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n,x,y;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld%d%d",&a[i],&b[i],&c[i]);
        if(c[i] >= 0) t[i] = 1000000001;
        else t[i] = ceil(1-b[i],c[i]);
    }
    //for(int i = 1;i <= n;i++) cout << t[i] << " ";
    //cout << endl;
    for(int i = 1;i < n;i++)
    {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int l = 1,r = 1000000000;
    while(l < r)
    {
        int mid = (l+r)/2;
        for(int i = 1;i <= n;i++) ti[i] = calc(i,mid);
        //for(int i = 1;i <= n;i++) cerr << ti[i] << " ";
        //cout << endl;
        //cout << check() << endl;
        if(check()) r = mid;
        else l = mid+1;
    }
    printf("%d",l);
    return 0;
}
