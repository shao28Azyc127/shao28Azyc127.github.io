#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define M 3004
char a[M][M],b[M][M];
int n,m;

bool cmp(int x,int y)
{
    return x>y;
}

bool scmp(int i,int j)
{
    for(int k=0;k<m;k++)
    {
        if(a[i][k]<b[j][k])return 1;
        if(a[i][k]>b[j][k])return 0;
    }
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=0;j<m;j++)
        {
            b[i][j]=a[i][j];
        }
        sort(a[i],a[i]+m);
        sort(b[i],b[i]+m,cmp);
    }
    for(int i=1;i<=n;i++)
    {
        bool flag=true;
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            if(scmp(i,j)==0)
            {
                flag=false;
                break;
            }
        }
        if(flag)cout<<"1";
        else cout<<"0";
    }
    return 0;
}
