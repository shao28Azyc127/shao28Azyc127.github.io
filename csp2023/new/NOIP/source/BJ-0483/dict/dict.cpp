#include<bits/stdc++.h>
using namespace std;
int n,m;
char c[3003][3003],cc[3003][3003],cm[3003][3003];
int sum[3003],sumc[3003];
int cmp(char a,char b)
{
    return a>b;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    if(n==1)cout<<1;
    else
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c[i][j];
                cc[i][j]=c[i][j];
                cm[i][j]=c[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            sort(cc[i]+1,cc[i]+1+m);
            sort(cm[i]+1,cm[i]+1+m,cmp);
        }
        /*
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)cout<<cc[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)cout<<cm[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;*/
        for(int x=1;x<=n;x++)
        {
            bool flag=true;
            for(int i=1;i<=n;i++)
            {
                if(i==x)continue ;
                if(!flag)break;
                for(int j=1;j<=m;j++)
                {
                    if(cc[x][j]<cm[i][j])break;
                    else if(cc[x][j]>cm[i][j])
                    {
                        flag=false;
                        break;
                    }
                    if(j==m)flag=false;
                }
            }
            if(flag)cout<<1;
            else cout<<0;
        }
    }
    return 0;
}
