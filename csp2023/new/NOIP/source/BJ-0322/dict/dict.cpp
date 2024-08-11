#include<iostream>
#include<stdio.h>
#include<cstring>
#include<ctime>
using namespace std;
const int maxn=3e3+5;
char arr[maxn][maxn];
char ma[maxn][maxn];
char mi[maxn][maxn];
int tong[26];
int main()
{
    ios::sync_with_stdio(0);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    //define
    int n,m;
    //input
    scanf("%d%d",&n,&m);
    //n==1
    if(n==1)
    {
        printf("%d",1);
        exit(0);
    }
    if(m==1)
    {
        int x=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%c",&arr[i][1]);
            while(arr[i][1]>'z'||arr[i][1]<'a')scanf("%c",&arr[i][1]);
            if(arr[i][1]<arr[x][1])
            {
                x=i;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(i==x)printf("%d",1);
            else printf("%d",0);
        }
        exit(0);
    }
    for(int i=1;i<=n;i++)
    {
        memset(tong,0,sizeof(tong));
        for(int j=1;j<=m;j++)
        {
            scanf("%c",&arr[i][j]);
            while(arr[i][j]>'z'||arr[i][j]<'a')scanf("%c",&arr[i][j]);
            tong[arr[i][j]-'a']++;
        }
        int cnt=1;
        for(int j=0;j<26;j++)
        {
            for(int t=1;t<=tong[j];t++)mi[i][cnt++]=char('a'+j);
        }
        cnt=1;
        for(int j=25;j>=0;j--)
        {
            for(int t=1;t<=tong[j];t++)ma[i][cnt++]=char('a'+j);
        }
    }
    for(int i=1;i<=n;i++)
    {
        int ans=1;
        for(int j=1;j<=n;j++)
        {
            if(j==i)continue;
            int t=1;
            while(t<=m&&ma[j][t]==mi[i][t])t++;
            if(t>m||ma[j][t]<mi[i][t])
            {
                ans=0;
                break;
            }
        }
        printf("%d",ans);
    }
    return 0;
}