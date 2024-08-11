#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[3012][3010];
int cmp(int x,int y)
{
    for(int i=0;i<m;i++)
    {
        if(s[x][i]<s[y][i]) return 1;
        else if(s[x][i]>s[y][i]) return -1;
    }
    return 0;
}
bool ccMax(char a,char b)
{
    return a>b;
}
bool ccMin(char a,char b)
{
    return a<b;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    if(n==1)
    {
        printf("1");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]);
        sort(s[i],s[i]+m,ccMax);
    }
    int Min1,Min2;
    if(cmp(1,2)==1) Min1=1,Min2=2;
    else Min1=2,Min2=1;
    for(int i=3;i<=n;i++)
    {
        int x=cmp(i,Min1);
        if(x==1) Min2=Min1,Min1=i;
        else if(x==0) Min2=i;
        else if(cmp(i,Min2)==1) Min2=i;
    }
    for(int i=0;i<m;i++)
        s[n+1][i]=s[Min1][i],s[n+2][i]=s[Min2][i];
  //  printf("%d %d",Min1,Min2);
    for(int i=1;i<=n;i++)
        sort(s[i],s[i]+m,ccMin);
    for(int i=1;i<=n;i++)
    {
        if(i!=Min1)
        {
            if(cmp(i,n+1)==1) printf("1");
            else printf("0");
        }
        else
        {
            if(cmp(i,n+2)==1) printf("1");
            else printf("0");
        }
    }
    return 0;
}
