#include <bits/stdc++.h>
using namespace std;
int a[10][10],n,ans=81;
int b[90][10],t[10],tot;
vector <int> e;
void dfs(int x,int flag)
{
    if(flag)
    {
        tot++;
        for(int i=1;i<x;i++)
            b[tot][i]=t[i];
        for(int i=x;i<=5;i++)
            b[tot][i]=a[1][i];
        return;
    }
    if(x>5) return;
    for(int i=0;i<=9;i++)
    {
        if(i==a[1][x]) continue;
        t[x]=i;
        dfs(x+1,1);
    }
    t[x]=a[1][x];
    dfs(x+1,0);
    if(x!=5)
    {
        for(int i=1;i<=9;i++)
        {
            t[x]=(a[1][x]+i)%10;
            t[x+1]=(a[1][x+1]+i)%10;
            dfs(x+2,1);
        }
    }
}
int cs(int x,int y)
{
    return (y+10-x)%10;
}
bool pd(int x,int y)
{
/*    printf("\n");
    for(int i=1;i<=5;i++)
        printf("%d ",b[x][i]);
        printf("\n");
    for(int i=1;i<=5;i++)
        printf("%d ",a[y][i]);
    printf("\n");*/
    int flag=0;
    for(int i=1;i<=5;i++)
    {
        if(b[x][i]!=a[y][i])
        {
            flag+=1;
            if(flag>1) return 0;
            if(i<5&&cs(b[x][i],a[y][i])==cs(b[x][i+1],a[y][i+1]))
            {
                i++;
            }
        }
    }
    if(flag==0)
    return 0;
    return 1;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
            scanf("%d",&a[i][j]);
    }
    if(n==1)
    {
        printf("%d",ans);
        return 0;
    }
    dfs(1,0);
/*    printf("%d\n",tot);
    for(int i=1;i<=81;i++)
    {
        for(int j=1;j<6;j++)
            printf("%d ",b[i][j]);
        printf("\n");
    }*/
    for(int i=1;i<=81;i++)
        e.push_back(i);
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<e.size();j++)
        {
            //printf("%d ",e[j]);
            if(!pd(e[j],i))
            {
                ans--;
                //printf("%d\n",j);
                e.erase(e.begin()+j);
                j--;
            }
            //else printf("\n");
        }
    }
    printf("%d",ans);
    return 0;
}
