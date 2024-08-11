#include<bits/stdc++.h>
using namespace std;
int n;
struct mm
{
    int num[6];
}lis[10]={};
int ans[10][10][10][10][10]={};
int db(int a,int b)
{
    if(a<b)
    return b-a;
    return b+10-a;
}
int sum=0;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d ",&n);
    if(n==1)
    {
        printf("81");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        scanf("%d",&lis[i].num[j]);
    }
    for(int i=0;i<=9;i++)
    for(int j=0;j<=9;j++)
    for(int k=0;k<=9;k++)
    for(int l=0;l<=9;l++)
    for(int m=0;m<=9;m++)
    for(int t=1;t<=n;t++)
    {
        if(lis[t].num[1]!=i&&lis[t].num[2]==j&&lis[t].num[3]==k&&lis[t].num[4]==l&&lis[t].num[5]==m)
        ans[i][j][k][l][m]++;
        else if(lis[t].num[1]==i&&lis[t].num[2]!=j&&lis[t].num[3]==k&&lis[t].num[4]==l&&lis[t].num[5]==m)
        ans[i][j][k][l][m]++;
        else if(lis[t].num[1]==i&&lis[t].num[2]==j&&lis[t].num[3]!=k&&lis[t].num[4]==l&&lis[t].num[5]==m)
        ans[i][j][k][l][m]++;
        else if(lis[t].num[1]==i&&lis[t].num[2]==j&&lis[t].num[3]==k&&lis[t].num[4]!=l&&lis[t].num[5]==m)
        ans[i][j][k][l][m]++;
        else if(lis[t].num[1]==i&&lis[t].num[2]==j&&lis[t].num[3]==k&&lis[t].num[4]==l&&lis[t].num[5]!=m)
        ans[i][j][k][l][m]++;
        else if(lis[t].num[1]!=i&&lis[t].num[2]!=j&&lis[t].num[3]==k&&lis[t].num[4]==l&&lis[t].num[5]==m)
        {
            if(db(i,lis[t].num[1])==db(j,lis[t].num[2]))
            ans[i][j][k][l][m]++;
        }
        else if(lis[t].num[1]==i&&lis[t].num[2]!=j&&lis[t].num[3]!=k&&lis[t].num[4]==l&&lis[t].num[5]==m)
        {
            if(db(j,lis[t].num[2])==db(k,lis[t].num[3]))
            ans[i][j][k][l][m]++;
        }
        else if(lis[t].num[1]==i&&lis[t].num[2]==j&&lis[t].num[3]!=k&&lis[t].num[4]!=l&&lis[t].num[5]==m)
        {
            if(db(k,lis[t].num[3])==db(l,lis[t].num[4]))
            ans[i][j][k][l][m]++;
        }
        else if(lis[t].num[1]==i&&lis[t].num[2]==j&&lis[t].num[3]==k&&lis[t].num[4]!=l&&lis[t].num[5]!=m)
        {
            if(db(l,lis[t].num[4])==db(m,lis[t].num[5]))
            ans[i][j][k][l][m]++;
        }
    }
    for(int i=0;i<=9;i++)
    for(int j=0;j<=9;j++)
    for(int k=0;k<=9;k++)
    for(int l=0;l<=9;l++)
    for(int m=0;m<=9;m++)
    if(ans[i][j][k][l][m]==n)
    sum++;
    printf("%d",sum);
    return 0;
}
