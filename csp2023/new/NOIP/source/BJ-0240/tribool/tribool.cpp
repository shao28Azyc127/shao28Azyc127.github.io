#include<bits/stdc++.h>
using namespace std;
int f[100005];
int ans;
queue <int> u,s[100005];
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t,n,m,x,y;
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        memset(f,0,sizeof(f));
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            f[i]=i;
        for(int i=1;i<=m;i++)
        {
            char c;
            cin>>c;
            if(c=='+')
            {
                cin>>x>>y;
                f[x]=f[y];
            }
            if(c=='-')
            {
                cin>>x>>y;
                f[x]=-f[y];
            }
            if(c=='T')
            {
                cin>>x;
                f[x]=n+1;
            }
            if(c=='F')
            {
                cin>>x;
                f[x]=-n-1;
            }
            if(c=='U')
            {
                cin>>x;
                f[x]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(f[i]==-i||f[i]==0)
                u.push(i);
            else if(f[i]!=i)
                s[abs(f[i])].push(i);
        }
        while(!u.empty())
        {
            ans++;
            x=u.front();
            u.pop();
            while(!s[x].empty())
            {
                u.push(s[x].front());
                s[x].pop();
            }
        }
        for(int i=1;i<=n;i++)
        {
            while(!s[i].empty())
                s[i].pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}
