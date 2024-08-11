#include <bits/stdc++.h>
using namespace std;
int n,m;
string s[3005],t[3005];
int tx[3005][3005],tn[3005][3005];
bool cmp(int a,int b)
{
    return a<b;
}
bool cmpx(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j=1;j<=m;j++)
        {
            tx[i][j]=int(s[i][j-1]);
            tn[i][j]=int(s[i][j-1]);
        }
        t[i]=s[i];
    }
    if(n<=300&&m<=300)
    {
        for(int i=1;i<=n;i++)
        {
            sort(tn[i]+1,tn[i]+1+m,cmp);
            sort(tx[i]+1,tx[i]+1+m,cmpx);
            int posx=1e9,posn=1e9;
            bool fx=0,fn=0;
            for(int j=1;j<=m;j++)
            {
                if(tn[i][j]!=int(s[i][j-1])&&fn==0)
                {
                    posn=j;
                    fn=1;
                }
                if(tx[i][j]!=int(t[i][j-1])&&fx==0)
                {
                    posx=j;
                    fx=1;
                }
            }
            fn=0;
            fx=0;
            for(int j=m-1;j>=posn;j--)
            {
                if(int(s[i][j])==tn[i][posn]&&fn==0)
                {
                    swap(s[i][posn-1],s[i][j]);
                    fn=1;
                }

            }
            for(int j=m-1;j>=posx;j--)
            {
                if(int(t[i][j])==tx[i][posx]&&fx==0)
                {
                    swap(t[i][posx-1],t[i][j]);
                    fx=1;
                }
            }
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            int mn=1e9,mx=0,posx=1e9,posn=1e9;
            for(int j=m-1;j>=0;j--)
            {
                if(mn>int(s[i][j]))
                {
                    mn=int(s[i][j]);
                    posn=j;
                }
                if(mx<int(t[i][j]))
                {
                    mx=int(t[i][j]);
                    posx=j;
                }
            }
            for(int j=0;j<posn;j++)
            {
                if(mn<int(s[i][j]))
                {
                    swap(s[i][posn],s[i][j]);
                    break;
                }
            }
            for(int j=0;j<posx;j++)
            {
                if(mx>int(t[i][j]))
                {
                    swap(t[i][j],t[i][posx]);
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        bool flag=0;
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                if(s[i]>=t[j])
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
        {
            cout<<0;
        }
        else
        {
            cout<<1;
        }
    }
    return 0;
}