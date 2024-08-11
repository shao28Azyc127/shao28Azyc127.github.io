#include<bits/stdc++.h>
#define ll long long
using namespace std;

int _;
int n,m,ans;
int fa[200005];
int x[100005];

inline int root(int p){return fa[p]==p?p:fa[p]=root(fa[p]);}

inline void sol()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        x[i]=i;

    for(int i=1;i<=2*n+3;i++)
        fa[i]=i;

    ans=0;

    while(m--)
    {
        char op;
        int a,b;
        cin>>op;

        if(op=='+')
        {
            cin>>a>>b;

            x[a]=x[b];
        }
        else if(op=='-')
        {
            cin>>a>>b;

            if(x[b]==2*n+3)
                x[a]=x[b];
            else if(x[b]>n+1)
                x[a]=x[b]-n-1;
            else
                x[a]=x[b]+n+1;
        }
        else
        {
            cin>>a;

            if(op=='T')
                x[a]=n+1;
            if(op=='F')
                x[a]=2*n+2;
            if(op=='U')
                x[a]=2*n+3;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(x[i]==2*n+3)
        {
            fa[root(i)]=root(x[i]);
            fa[root(i+n+1)]=root(x[i]);
        }
        else if(x[i]>n+1)
        {
            fa[root(i)]=root(x[i]);
            fa[root(i+n+1)]=root(x[i]-n-1);
        }
        else
        {
            fa[root(i)]=root(x[i]);
            fa[root(i+n+1)]=root(x[i]+n+1);
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(root(i)==root(i+n+1))
            ans++;
    }

    cout<<ans<<'\n';
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>_;
    cin>>_;

    while(_--)
        sol();

    return 0;
}
