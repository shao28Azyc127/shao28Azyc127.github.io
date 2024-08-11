#include <iostream>
#include <cstdio>

using namespace std;

int n;
int a[10][10];
int b[10],c[10];
int ans=0;

bool func(int idx)
{
    int cnt=0,lst;
    for(int i=1;i<=5;i++) if(a[idx][i]!=b[i])
    {
        c[i]=1;
        cnt++;
        lst=i;
    }
    if(cnt>2) return 0;
    if(cnt==1) return 1;
    if(cnt==2&&c[lst-1])
    {
        if(b[lst]-a[idx][lst]==b[lst-1]-a[idx][lst-1]) return 1;
    }
    return 0;
}

bool f(int idx)
{
    for(int i=1;i<=5;i++) if(a[idx][i]!=b[i]) return 1;
    return 0;
}

void dfs(int level)
{
    if(level>5)
    {
        if(func(1)&&func(2)&&f(1)&&f(2)) ans++;
        return ;
    }
    for(int i=0;i<=9;i++)
    {
        b[level]=i;
        dfs(level+1);
    }
}

bool vis[20];

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    if(n==1)
    {
        printf("81");
        return 0;
    }
    if(n==2)
    {
        dfs(1);
        printf("%d",ans);
        return 0;
    }
    for(int j=1;j<=5;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i][j]!=a[1][j]) b[j]=1;
        }
    }
    bool flag=0;
    for(int i=1;i<=5;i++)
    {
        if(b[i]==1)
        {
            ans=10;
            for(int j=1;j<=n;j++)
            {
                if(!vis[a[j][i]])
                {
                    ans--;
                    vis[a[j][i]]=1;
                }
            }
            flag=1;
            break;
        }
    }
    if(!flag) ans=81;
    printf("%d",ans);
    return 0;
}
/*
if you are reading this, i'm probably afoed again
today is 202310211808
150~185
80+35~50+0+35
re-afo
*/