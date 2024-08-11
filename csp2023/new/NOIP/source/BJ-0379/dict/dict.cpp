#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m;
char ch[N],mx[N],mn[N][N];
int id;
inline bool cmp1(char x,char y)
{
    return x>y;
}
inline bool cmp2(char x,char y)
{
    return x<y;
}
inline bool com(int x)
{
    for(int i=1;i<=m;i++)
    {
        if(mn[x][i]<mx[i])return true;
        if(mn[x][i]>mx[i])return false;
    }
    return false;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)mx[i]=127;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf(" %c",&ch[j]);
        }
        sort(ch+1,ch+m+1,cmp1);
        bool flag=0;
        for(int j=1;j<=m;j++)
        {
            if(ch[j]>mx[j])
            {
                flag=1;
                break;
            }
            if(ch[j]<mx[j])
            {
                flag=0;
                break;
            }
        }
        if(!flag)
        {
            id=i;
            for(int j=1;j<=m;j++)
            {
                mx[j]=ch[j];
            }
        }
        sort(ch+1,ch+m+1,cmp2);
        for(int j=1;j<=m;j++)
        {
            mn[i][j]=ch[j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        bool flag=com(i)||(i==id);
        printf("%d",flag);
    }
    return 0;
}
