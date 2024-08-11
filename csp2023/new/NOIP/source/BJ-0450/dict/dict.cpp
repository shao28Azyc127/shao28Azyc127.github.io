#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=4000;
int n, m;
string a[N];
bool cmp(string x, string y)
{
    for(int i=0; i<m; i++)
    {
        if(x[i]<y[i]) return 1;
        else return 0;
    }
    return 1;
}

int findmin()
{
    int minx=1;
    for(int i=1; i<n; i++)
    {
        if(cmp(a[i], a[minx]) || i==1)
            minx=i;
    }
    return minx;
}
namespace _40pts
{
    void mian()
    {
        int k=findmin();
        for(int i=1; i<=n; i++)
            if(i==k)
                cout << 1;
            else cout << 0;
        cout << '\n';
        return ;
    }
}

namespace _70pts
{
    int b[N];
    void mian()
    {
        b[findmin()]=1;
        for(int i=1; i<=n; i++)
        {
            // ziji budong
            if(b[i]==1) continue;
            bool flag=0;
            for(int j=1; j<=n; j++)
            {
                if(i==j) continue;
                if(a[i][0]>a[j][0] && a[i][1]>a[j][1])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0) b[i]=1;

            char c=a[i][0];
            a[i][0]=a[i][1];
            a[i][1]=c;

            flag=0;
            for(int j=1; j<=n; j++)
            {
                if(i==j) continue;
                if(a[i][0]>a[j][0] && a[i][1]>a[j][1])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0) b[i]=1;

        }
        for(int i=1; i<=n; i++)
            cout << b[i];
        cout << '\n';
    }
}


namespace _100pts
{
    int b[N];
    int mx[N];
    int mn[N];
    void mian()
    {
        b[findmin()]=1;
        for(int i=1; i<=n; i++)
        {
            int minx=0, maxx=0;
            for(int j=0; j<m; j++)
            {
                if(a[i][j]<a[i][minx]) minx=j;
                if(a[i][j]>a[i][maxx]) maxx=j;
            }

            mx[i]=maxx;
            mn[i]=minx;
        }

        for(int i=1; i<=n; i++)
        {
            if(b[i]==1) continue;
            bool flag=1;
            for(int j=1; j<=n; j++)
            {
                if(i==j) continue;
                if(a[j][mx[j]]<=a[i][mn[i]])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
                b[i]=1;
        }

        for(int i=1; i<=n; i++)
        {
            cout << b[i];
        }
        cout << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    if(n==1)
    {
        cout << 1 << '\n';
        return 0;
    }
    if(m==1)
        _40pts::mian();
    else if(m==2)
        _70pts::mian();
    else 
        _100pts::mian();
    return 0;
}
