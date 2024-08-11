#include <iostream>
#include <cstdio>
using namespace std;

int n,a[10][10],b[10][10];

bool cmp(int x,int y)
{
    for(int i=1;i<=5;i++)
        if(b[x][i]!=b[y][i]) return false;
    return true;
}

bool chang1(int id,int pos)
{
        b[id][pos]=b[1][pos];
        if(cmp(1,id))
        {
            b[id][pos]=a[id][pos];
            return true;
        }
        b[id][pos]=a[id][pos];
    return false;
}

bool chang2(int id,int pos)
{
        b[id][pos]=b[1][pos];
        b[id][pos+1]=b[1][pos+1];
        if(cmp(1,id))
        {
            b[id][pos]=a[id][pos];
            b[id][pos+1]=a[id][pos+1];
            return true;
        }
        b[id][pos]=a[id][pos];
        b[id][pos+1]=a[id][pos+1];
    return false;
}

bool chck()
{
    bool flag;
    for(int i=2;i<=n;i++)
    {
        flag=false;
        for(int j=1;j<=5&&!flag;j++)
            if(b[1][j]!=b[i][j])
                if(chang1(i,j)) flag=true;
        for(int j=1;j<=4&&!flag;j++)
            if(b[1][j]!=b[i][j]&&b[1][j]-b[i][j]==b[1][j+1]-b[i][j+1])
                if(chang2(i,j)) flag=true;
        if(!flag) return false;
    }
    return true;
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            scanf("%d",&a[i][j]),b[i][j]=a[i][j];
    if(n==1)
    {
        printf("81");
        return 0;
    }
    int ans=0;
    for(int i=1;i<=5;i++)
        for(int j=1;j<=9;j++)
        {
            b[1][i]=(a[1][i]+j)%10;
            if(chck()) ans++;
            b[1][i]=a[1][i];
        }
    for(int i=1;i<=4;i++)
        for(int j=1;j<=9;j++)
        {
            b[1][i]=(a[1][i]+j)%10;
            b[1][i+1]=(a[1][i+1]+j)%10;
            if(chck()) ans++;
            b[1][i]=a[1][i];
            b[1][i]=a[1][i];
        }
    printf("%d",ans);
    return 0;
}
