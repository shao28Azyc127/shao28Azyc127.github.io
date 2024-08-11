#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
const int maxn12=15;
int arr12[maxn12][4];int ans12=1e9;int d[maxn12];int a[maxn12];
const int maxn=1e5+5;
int p[maxn];
void dfs(int x,int n,int m)
{
    if(x>n)
    {
        int res=0;
        for(int i=1;i<=n;i++)
        {
            a[i]=d[i];
            if(a[i]==-1)res++;
        }
        for(int i=1;i<=m;i++)
        {
            if(arr12[i][1]==1)
            {
                a[arr12[i][2]]=arr12[i][3];
            }
            else if(arr12[i][1]==2)
            {
                a[arr12[i][2]]=a[arr12[i][3]];
            }
            else if(arr12[i][1]==3)
            {
                int nx=a[arr12[i][3]];
                if(nx!=-1)nx=!nx;
                a[arr12[i][2]]=nx;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=d[i])return;
        }
        if(res<ans12)
        {
            ans12=res;
        }
        return;
    }
    for(int i=-1;i<=1;i++)
    {
        d[x]=i;
        dfs(x+1,n,m);
    }
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;cin>>c>>t;
    if(c==1||c==2)
    {
        while(t--)
        {
            ans12=1e9;
            int n,m;cin>>n>>m;
            for(int i=1;i<=m;i++)
            {
                char x;cin>>x;
                if(x=='-')
                {
                    arr12[i][1]=3;
                    cin>>arr12[i][2]>>arr12[i][3];
                }else
                if(x=='+')
                {
                    arr12[i][1]=2;
                    cin>>arr12[i][2]>>arr12[i][3];
                }
                else
                {
                    arr12[i][1]=1;
                    cin>>arr12[i][2];
                    int xx=-1;
                    if(x=='U')xx=-1;
                    if(x=='T')xx=1;
                    if(x=='F')xx=0;
                    arr12[i][3]=xx;
                }
            }dfs(1,n,m);
            cout<<ans12<<endl;
        }
       
    }else
    if(c==3||c==4)
    {
        while(t--)
        {
            memset(p,0,sizeof(p));
            int n,m;cin>>n>>m;
            int ans=0;
            for(int i=1;i<=m;i++)
            {
                char x;int jiangyou;cin>>x>>jiangyou;
                if(x=='U')p[jiangyou]=1;
            }
            for(int i=1;i<=n;i++)if(p[i])ans++;
            cout<<ans<<endl;
        }
    }
    else
    {
        while(t--)
        {
            memset(p,0,sizeof(p));
            int n,m;cin>>n>>m;
            int ans=0;
            for(int i=1;i<=m;i++)
            {
                char x;int j;cin>>x>>j;
                if(x=='U')
                {
                    //if(!p[j])cout<<x<<" "<<j<<endl;
                    p[j]=1;
                }
                else 
                {   int y;cin>>y;
                    if(!p[y]&&!p[j])continue;
                    //if(j!=y)cout<<x<<" "<<j<<" "<<y<<endl;
                    if(p[y])p[j]=1;
                    else p[j]=0;
                }
            }
            for(int i=1;i<=n;i++)if(p[i]==1)ans++;
            cout<<ans<<endl;
        }
    }
    return 0;
}