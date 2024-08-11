#include<iostream>

using namespace std;

int c,t,n,m,ans;
int fa[100005];
char val[100005];

int getf(int x)
{
    if(x==fa[x] || x==-fa[x])
        return fa[x];
    if(fa[x]<0)
        return fa[x]=-getf(-fa[x]);
    return fa[x]=getf(fa[x]);
}

char f(char x)
{
    if(x=='T')
        return 'F';
    if(x=='F')
        return 'T';
    return x;
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin >> c >> t ;
    int i,x,y;
    char opt;
    while(t--)
    {
        ans=0;
        cin >> n >> m ;
        for(i=0;i<=n;i++)
        {
            fa[i]=i;
            val[i]='0';
        }
        for(i=1;i<=m;i++)
        {
            cin >> opt ;
            if(opt=='+')
            {
                cin >> x >> y ;
                fa[x]=getf(y);
                val[x]=val[y];
                continue;
            }
            if(opt=='-')
            {
                cin >> x >> y ;
                fa[x]=-getf(y);
                val[x]=f(val[y]);
                continue;
            }
            cin >> x ;
            val[x]=opt;
        }
        for(i=1;i<=n;i++)
        {
            getf(i);
            if(fa[i]==-i)
                val[i]='U';
        }
        for(i=1;i<=n;i++)
        {
            if(fa[i]<0)
                val[i]=f(val[-fa[i]]);
            else
                val[i]=val[fa[i]];
            if(val[i]=='U')
                ans++;
        }
        cout << ans << endl ;
    }
    return 0;
}
