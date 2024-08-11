#include <fstream>
using namespace std;
ifstream cin ("tribool.in");
ofstream cout ("tribool.out");
const int inf = 0x3f3f3f3f;
struct DSU
{
    int fa[200050];
    int siz[200050];

    void init(int n)
    {
        for (int i=0;i<=n;i++)
        {
            fa[i]=i;
            siz[i]=1;
        }
    }

    int find (int x)
    {
        if (fa[x]==x)
        {
            return fa[x];
        }
        return fa[x]=find(fa[x]);
    }

    void merge (int x,int y)
    {
        x=find(x),y=find(y);
        if (x==y)
        {
            return;
        }
        if (siz[x]>siz[y])
        {
            swap(x,y);
        }
        fa[x]=y;
        siz[y]+=siz[x];
    }

    bool query (int x,int y)
    {
        return find(x)==find(y);
    }
}D1,D2;
int ab (int x)
{
    if (x<0)
    {
        return -x;
    }
    return x;
}
int a[100010];
bool f1[100010];
int main ()
{
    int C,T;
    cin>>C>>T;
    while (T--)
    {
        int n,m;
        cin>>n>>m;
        for (int i=1;i<=n;i++)
        {
            a[i]=i+1;
            f1[i]=0;
        }
        while (m--)
        {
            char op;
            int i;
            cin>>op>>i;
            if (op=='T')
            {
                a[i]=1;
            }
            if (op=='F')
            {
                a[i]=-1;
            }
            if (op=='U')
            {
                a[i]=0;
            }
            if (op=='+')
            {
                int j;
                cin>>j;
                a[i]=a[j];
            }
            if (op=='-')
            {
                int j;
                cin>>j;
                a[i]=-a[j];
            }
        }
        D1.init(n);
        for (int i=1;i<=n;i++)
        {
            // cerr<<a[i]<<" ";
            if (ab(a[i])>1)
            {
                D1.merge(i,ab(a[i])-1);
            }
        }
        // cerr<<endl;
        int res=0;
        for (int i=1;i<=n;i++)
        {
            int t = D1.find(i);
            if (!f1[t] and a[i]==0)
            {
                res+=D1.siz[t];

            }
        }
        for (int i=1;i<=n;i++)
        {
            int t = D1.find(i);
            if (ab(a[i])<=1)
            {
                f1[t]=1;
            }
        }
        D2.init(n+n);
        for (int i=1;i<=n;i++)
        {
            int t = D1.find(i);
            if (!f1[t])
            {
                if (a[i]<0)
                {
                    D2.merge(i,-a[i]-1+n);
                    D2.merge(i+n,-a[i]-1);
                }
                else
                {
                    D2.merge(i,a[i]-1);
                    D2.merge(i+n,a[i]-1+n);
                }
            }
        }
        for (int i=1;i<=n;i++)
        {
            int t = D1.find(i);
            if (!f1[t] and D2.query(i,i+n))
            {
                f1[t]=1;
                res+=D1.siz[t];
            }
        }
        cout<<res<<endl;
    }
}