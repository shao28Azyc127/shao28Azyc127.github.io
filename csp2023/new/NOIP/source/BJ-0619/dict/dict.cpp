#include<bits/stdc++.h>
using namespace std;
string s[3005];
int smin[3005][3005],smax[3005][3005],a[3005][3005];
int n,m;
int check(int x,int y)
{
    for(int i=0;i<m;i++)
    {
        if(smin[x][i]>smin[y][m-1-i])
        {
            return 1;
        }
        if(smin[x][i]<smin[y][m-1-i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=n;i++)
    for(int j=0;j<m;j++)
    {
        a[i][j]=s[i][j];
        smin[i][j]=s[i][j];
        //smax[i][j]=s[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        sort(smin[i],smin[i]+m);
    }
   
    for(int i=1;i<=n;i++)
    {
         int flag=0;
        for(int j=1;j<=n;j++)
        {
            if(j==i)
            continue;
            if(check(i,j)==1)
            {
                flag=1;
               cout<<"0";
               break;
            }
        }
        if(flag==0)
        cout<<"1";
    }
    return 0;
}