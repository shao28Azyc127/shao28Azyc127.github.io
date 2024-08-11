#include<cstdio>
#include<iostream>
using namespace std;

int n,ans;
int a[10][10],b[10];

bool check(int a[],int b[])//判断是否可以变成一个状态
{
    int r[10],sz=0;
    for(int i=1;i<=5;i++)if(a[i]!=b[i])r[++sz]=i;
    if(sz==0||sz>2)return false;
    if(sz==1)return true;
    if(r[1]+1!=r[2])return false;
    int x=(a[r[1]]+10-b[r[1]])%10,y=(a[r[2]]+10-b[r[2]])%10;
    return x==y;

}

void dfs(int x)
{
    if(x>5)
    {
        bool f=1;
        for(int i=1;i<=n;i++)
            if(!check(a[i],b))f=0;
        if(f)ans++;
        return;
    }
    for(int i=0;i<=9;i++)
    {
        b[x]=i;
        dfs(x+1);
    }
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)cin>>a[i][j];
    dfs(1);
    cout<<ans;
    return 0;
}
