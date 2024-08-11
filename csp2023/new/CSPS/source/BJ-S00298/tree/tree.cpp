#include <fstream>
#include <queue>
#include <vector>
using namespace std;
ifstream cin ("tree.in");
ofstream cout ("tree.out");
long long int a[100010];
int b[100010],c[100010];
int ned[100010];
struct Node
{
    int i;
};
bool operator < (Node a,Node b)
{
    return ned[a.i]<ned[b.i];
}
priority_queue <Node> q;
vector <int> edges[100010];
bool vis[100010];
int main ()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        if (a[i]%b[i]==0)
        {
            ned[i]=a[i]/b[i];
        }
        else
        {
            ned[i]=a[i]/b[i]+1;
        }
    }
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    Node u;
    u.i=1;
    q.push(u);
    int d=0,ans=0;
    while (!q.empty())
    {
        Node u=q.top();
        q.pop();
        ans=max(ans,d+ned[u.i]);
        d++;
        vis[u.i]=1;
        for (auto i:edges[u.i])
        {
            if (!vis[i])
            {
                Node t;
                t.i=i;
                q.push(t);
            }
        }
    }
    cout<<ans<<endl;
}