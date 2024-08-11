#include<bits/stdc++.h>
using namespace std;
struct node
{
    char c;
    int u,v;
}op[100005];
int tc,T,n,m,ans=0x3f3f3f3f;
int res[1005],res1[1005];
void check()
{
    for(int i=1;i<=n;i++)
        res1[i]=res[i];
    for(int i=1;i<=m;i++)
    {
        if(op[i].c=='T')
            res1[op[i].u]=1;
        else if(op[i].c=='F')
            res1[op[i].u]=0;
        else if(op[i].c=='U')
            res1[op[i].u]=2;
        else if(op[i].c=='+')
            res1[op[i].u]=res1[op[i].v];
        else if(op[i].c=='-')
        {
            if(res1[op[i].v]==2)
                res1[op[i].u]=2;
            else
                res1[op[i].u]=(!(res1[op[i].v]));
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(res1[i]!=res[i])
            return;
        else
            if(res1[i]==2)
                cnt++;
    ans=min(ans,cnt);
    return;
}
void fz(int cur)
{
    if(cur==n+1)
    {
        check();
        return;
    }
    res[cur]=0;
    fz(cur+1);
    res[cur]=1;
    fz(cur+1);
    res[cur]=2;
    fz(cur+1);
    return;
}
//3,4
int fin[100005];
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>tc>>T;
    if(tc==1 || tc==2)
    {
        while(T--)
        {
            ans=0x3f3f3f3f;
            cin>>n>>m;
            for(int i=1;i<=m;i++)
            {
                cin>>op[i].c;
                if(op[i].c=='T' || op[i].c=='F' || op[i].c=='U')
                    cin>>op[i].u;
                else
                    cin>>op[i].u>>op[i].v;
            }
            fz(1);
            cout<<ans<<endl;
        }
    }
    else if(tc==3 || tc==4)
    {
        while(T--)
        {
            for(int i=1;i<=n;i++)
                fin[i]=0;
            cin>>n>>m;
            for(int i=1;i<=m;i++)
            {
                cin>>op[i].c>>op[i].u;
                if(op[i].c=='T')
                    fin[op[i].u]=1;
                else if(op[i].c=='F')
                    fin[op[i].u]=0;
                else if(op[i].c=='U')
                    fin[op[i].u]=2;
            }
            int cnt=0;
            for(int i=1;i<=n;i++)
                cnt+=(fin[i]==2);
            cout<<cnt<<endl;
        }
    }
    else if(tc==5 || tc==6)
    {
        while(T--)
        {
            for(int i=1;i<=n;i++)
                fin[i]=0;
            cin>>n>>m;
            for(int i=1;i<=m;i++)
            {
                cin>>op[i].c;
                if(op[i].c=='+')
                    cin>>op[i].u>>op[i].v;
                else if(op[i].c=='U')
                    cin>>op[i].u;
                if(op[i].c=='+')
                    fin[op[i].u]=fin[op[i].v];
                else if(op[i].c=='U')
                    fin[op[i].u]=2;
            }
            int cnt=0;
            for(int i=1;i<=n;i++)
                cnt+=(fin[i]==2);
            cout<<cnt<<endl;
        }
    }
    return 0;
}
