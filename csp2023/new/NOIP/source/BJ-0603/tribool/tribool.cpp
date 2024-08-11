#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
int cvar[100005],var[100005];
int ans=0;
queue <int> que;
bool vis[100005];
int topo(int x,int num)
{
    que.push(x);
    int res=0;
    int tmp;
    while(!que.empty())
    {
        tmp=que.front();
        que.pop();
        vis[tmp]=true;
        res++;
        var[tmp]=0;
        for(int i=1;i<=num;i++)
        {
            if((var[i]==tmp || var[i]==-tmp) && vis[i]==false)
            {
                //cout<<i;
                que.push(i);
            }
        }
    }
    return res;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
//    for(int i=1;i<=100005;i++)
//    {
//        cvar[i]=i;
//    }
    char com;
    int p1,p2;
    while(t--)
    {
        cin>>n>>m;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            var[i]=i;
            vis[i]=false;
        }

        for(int i=1;i<=m;i++)
        {
            cin>>com;
            if(com=='T')
            {
                cin>>p1;
                var[p1]=p1;
            }
            if(com=='F')
            {
                cin>>p1;
                var[p1]=-p1;
            }
            if(com=='U')
            {
                cin>>p1;
                var[p1]=0;
            }
            if(com=='+')
            {
                cin>>p1>>p2;
                var[p1]=var[p2];
            }
            if(com=='-')
            {
                cin>>p1>>p2;
                var[p1]=-var[p2];
            }
        }

//        for(int i=1;i<=n;i++)
//        {
//            cout<<var[i]<<" ";
//        }
        for(int i=1;i<=n;i++)
        {
            if((var[i]==0 || var[i]==-i ) && vis[i]==false)
            {
                ans+=topo(i,n);
                var[i]=0;

            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
