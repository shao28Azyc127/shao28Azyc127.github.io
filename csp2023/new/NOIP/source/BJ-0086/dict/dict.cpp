#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=3005;
char c1[MAXN][MAXN],c2[MAXN][MAXN];
bool cmp(char x,char y)
{
    return x>y;
}
bool check(char s1[],char s2[],int siz)
{
    for(int i=0;i<siz;i++)
    {
        if(s1[i]>s2[i]) return false;
        if(s1[i]<s2[i]) return true;
    }
    return false;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",&c1[i]);
        for(int j=0;j<m;j++) c2[i][j]=c1[i][j];
        sort(c1[i],c1[i]+m);
        sort(c2[i],c2[i]+m,cmp);
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++) printf("%c",c1[i][j]);
        printf("\n");
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++) printf("%c",c2[i][j]);
        printf("\n");
    }
    */
    for(int i=1;i<=n;i++)
    {
        int flag=1;
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(!check(c1[i],c2[j],m))
            {
                flag=0;
                break;
            }
        }
        printf("%d",flag);
    }
    printf("\n");
    return 0;
}