#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int c,t,n,m;
int a[100010];
//1:T 2:F 3:U
int no(int x)
{
    if(x==1)return 2;
    if(x==2)return 1;
    if(x==3)return 3;
}
char ch[100010];
int num1[100010],num2[100010];
int b[100010],ans;
void dfs(int x,int cnt)
{
    if(x>n)
    {
        for(int i=1;i<=n;i++)
            b[i]=a[i];
        for(int i=1;i<=m;i++)
        {
            char op=ch[i];
            if(op=='T')b[num1[i]]=1;
            if(op=='F')b[num1[i]]=2;
            if(op=='U')b[num1[i]]=3;
            if(op=='+')b[num1[i]]=b[num2[i]];
            if(op=='-')b[num1[i]]=no(b[num2[i]]);
        }
        bool f=1;
        for(int i=1;i<=n;i++)
            if(b[i]!=a[i])return;
        ans=min(ans,cnt);
        return;
    }
    a[x]=1;
    dfs(x+1,cnt);
    a[x]=2;
    dfs(x+1,cnt);
    a[x]=3;
    dfs(x+1,cnt+1);
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    if(c==3||c==4)
    {
        while(t--)
        {
            memset(a,0,sizeof(a));
            int cnt=0;
            cin>>n>>m;
            for(int i=1;i<=m;i++)
            {
                char op;
                int x;
                cin>>op>>x;
                if(op=='T')a[x]=1;
                if(op=='F')a[x]=2;
                if(op=='U')a[x]=3;
            }
            for(int i=1;i<=n;i++)
                if(a[i]==3)cnt++;
            cout<<cnt<<endl;
        }
    }
    else if(c==1||c==2)
    {
        while(t--)
        {
            cin>>n>>m;
            for(int i=1;i<=m;i++)
            {
                char op;
                cin>>op;
                ch[i]=op;
                if(op=='T'||op=='F'||op=='U')
                    cin>>num1[i];
                else cin>>num1[i]>>num2[i];
            }
            ans=1e9;
            dfs(1,0);
            cout<<ans<<endl;
        }
    }
    return 0;
}