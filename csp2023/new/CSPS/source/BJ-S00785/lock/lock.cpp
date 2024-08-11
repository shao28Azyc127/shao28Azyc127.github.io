#include <bits/stdc++.h>
using namespace std;
int a[10][6];
int g=0;
bool b[10];
bool p[1000000];
int ff(int a,int b,int c,int d,int e)
{
    return e+10*d+100*c+1000*b+10000*a;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=5; j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=1; i<=n; i++)
    {
        int p1[10];
        for(int k=1; k<=5; k++)
            p1[k]=a[i][k];
        for(int j=1; j<=5; j++)
        {
            for(int k=0; k<=9; k++)
            {
                p1[j]=k;
                p[ff(p1[1],p1[2],p1[3],p1[4],p1[5])]=true;
            }
            p1[j]=a[i][j];
        }
    }
    for(int i=1; i<=n; i++)
    {
        int p1[10];
        for(int k=1; k<=5; k++)
            p1[k]=a[i][k];
        for(int j=1; j<5; j++)
        {
            for(int k=0; k<=9; k++)
            {
                p1[j]=p1[j]+10-k;
                p1[j]%=10;

                p1[j+1]=p1[j+1]+10-k;
                p1[j+1]%=10;
                p[ff(p1[1],p1[2],p1[3],p1[4],p1[5])]=true;
                p1[j]=a[i][j];
                p1[j+1]=a[i][j+1];
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        p[ff(a[i][1],a[i][2],a[i][3],a[i][4],a[i][5])]=false;
    }
    int g=0;
    for(int i=0; i<=99999; i++)
    {
        if(p[i])
            g++;
    }
    cout<<g;
    return 0;
}
