#include<bits/stdc++.h>
using namespace std;

int n,m;
char dict[3010][3010];
int min_number=1;
char try_char;

bool cmp(char a,char b)
{
    return(a>b);
}

bool cmpstr(int i,int j)
{
    for(int k=1;k<=m;k++)
    {
        if(dict[i][k]<dict[j][k])return false;
        if(dict[i][k]>dict[j][k])return true;
    }
    return false;
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%c",&try_char);
    if(try_char==10)
    {
        for(int i=1;i<=m;i++)scanf("%c",&dict[1][i]);
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<=m;j++)scanf("%c",&dict[i][j]);
        }
    }
    else
    {
        dict[1][1]=try_char;
        for(int i=2;i<=m;i++)scanf("%c",&dict[1][i]);
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=m;j++)scanf("%c",&dict[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        sort(dict[i]+1,dict[i]+m+1,cmp);
    }
    for(int i=2;i<=n;i++)
    {
        if(cmpstr(min_number,i))min_number=i;
    }
    for(int i=1;i<=m;i++)
    {
        dict[0][i]=dict[min_number][i];
    }
    for(int i=1;i<=n;i++)
    {
        if(i==min_number)printf("1");
        else
        {
            sort(dict[i]+1,dict[i]+1+m);
            if(cmpstr(0,i))printf("1");
            else printf("0");
        }
    }
    return 0;
}
