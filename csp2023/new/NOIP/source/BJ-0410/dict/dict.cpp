#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m;
char c[3005][3005];

bool cmp(char x,char y)
{
    return x>y;
}
bool cmp1(char x,char y)
{
    return x<y;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>c[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        sort(c[i]+1,c[i]+m+1,cmp1);
        bool flag=true;
        if(i==1)
        {
            for(int j=1;j<=n;j++)
            {
                if(j==i)
                    continue;
                sort(c[j]+1,c[j]+m+1,cmp);
                for(int k=1;k<=m;k++)
                {
                    if(c[i][k]<c[j][k])
                        break;
                    if(c[i][k]>c[j][k])
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag==false)
                    break;
            }
        }
        else
        {
            sort(c[i-1]+1,c[i-1]+m+1,cmp);
            for(int j=1;j<=n;j++)
            {
                if(j==i)
                    continue;

                for(int k=1;k<=m;k++)
                {
                    if(c[i][k]<c[j][k])
                        break;
                    if(c[i][k]>c[j][k])
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag==false)
                    break;
            }
        }
        if(flag==false)
            cout<<0;
        else
            cout<<1;

    }


    return 0;
}
