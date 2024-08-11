#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
int id[2],flag;
char s[N][N],bg[2][N],mi[N][N];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    if(n==1)
    {
        cout<<"1"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        sort(s[i]+1,s[i]+1+m);
        for(int j=1;j<=m;j++)mi[i][j]=s[i][j];
    }
    for(int i=1;i<=n;i++)reverse(s[i]+1,s[i]+1+m);
    for(int i=1;i<=n;i++)
    {
        if(!id[0])
        {
            for(int j=1;j<=m;j++)bg[0][j]=s[i][j];
            id[0]=i;
        }
        else if(!id[1])
        {
            for(int j=1;j<=m;j++)bg[1][j]=s[i][j];
            id[1]=i;
        }
        else
        {
            flag=0;
            for(int j=1;j<=m;j++)
            {
                if(bg[0][j]<s[i][j])break;
                if(bg[0][j]>s[i][j])
                {
                    for(int j=1;j<=m;j++)bg[0][j]=s[i][j];
                    id[0]=i;
                    flag=1;
                    break;
                }
            }
            if(flag)continue;
            for(int j=1;j<=m;j++)
            {
                if(bg[1][j]<s[i][j])break;
                if(bg[1][j]>s[i][j])
                {
                    for(int j=1;j<=m;j++)bg[1][j]=s[i][j];
                    id[1]=i;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        flag=0;
        if(i!=id[0])
        {
            for(int j=1;j<=m;j++)
            {
                if(mi[i][j]<bg[0][j])break;
                if(mi[i][j]>bg[0][j])
                {
                    flag=1;
                    break;
                }
            }
        }
        else
        {
            for(int j=1;j<=m;j++)
            {
                if(mi[i][j]<bg[1][j])break;
                if(mi[i][j]>bg[1][j])
                {
                    flag=1;
                    break;
                }
            }
        }
        printf("%d",!flag);
    }
    puts("");
    return 0;
}
