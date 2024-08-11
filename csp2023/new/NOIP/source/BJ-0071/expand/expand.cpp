#include <fstream>
using namespace std;
ifstream cin ("expand.in");
ofstream cout ("expand.out");
bool f[2020][2020];
int a[500020],b[500020];
int aa[500020],bb[500020];
int ma[500020],mi[500020];
bool solve (int n,int m)
{
    if (n<=2000 and m<=2000)
    {    
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                f[i][j]=0;
            }
        }
        f[1][1]=1;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if ((a[i]>b[j])==(a[1]>b[1]) and a[i]!=b[j])
                {
                    f[i][j]|=f[i-1][j];
                    f[i][j]|=f[i][j-1];
                    f[i][j]|=f[i-1][j-1];
                }
                // cerr<<((a[i]>b[j])==(a[1]>b[1]) and a[i]!=b[j])<<" ";
            }
            // cerr<<endl; 
        }
        return f[n][m];
    }
    else
    {
        mi[0]=0x7f7f7f7f;
        for (int i=1;i<=n;i++)
        {
            if (a[i]<a[mi[i-1]])
            {
                mi[i]=i;
            }
            else
            {
                mi[i]=mi[i-1];
            }
        }
        for (int i=1;i<=m;i++)
        {
            if (b[i]>b[ma[i-1]])
            {
                ma[i]=i;
            }
            else
            {
                ma[i]=ma[i-1];
            }
        }
        int i=n,j=m;
        bool f=0;
        bool gd=1;
        while (i!=1 and j!=1)
        {
            if (f)
            {
                for (int j=mi[i-1];j<=i;j++)
                {
                    if ((a[i]>b[j])==(a[1]>b[1]) and a[i]!=b[j])
                    {
                        continue;
                    }
                    else
                    {
                        gd=0;
                    }
                }
                i=mi[i-1];
            }
            else
            {
                for (int k=ma[j-1];k<=j;k++)
                {
                    if ((a[i]>b[k])==(a[1]>b[1]) and a[i]!=b[k])
                    {
                        continue;
                    }
                    else
                    {
                        gd=0;
                    }
                }
                j=ma[j-1];
            }
            f=1-f;
        }
        if (!gd)
        {
            f=1;
            gd=0;
            while (i!=1 and j!=1)
            {
                if (f)
                {
                    for (int j=mi[i-1];j<=i;j++)
                    {
                        if ((a[i]>b[j])==(a[1]>b[1]) and a[i]!=b[j])
                        {
                            continue;
                        }
                        else
                        {
                            gd=0;
                        }
                    }
                    i=mi[i-1];
                }
                else
                {
                    for (int k=ma[j-1];k<=j;k++)
                    {
                        if ((a[i]>b[k])==(a[1]>b[1]) and a[i]!=b[k])
                        {
                            continue;
                        }
                        else
                        {
                            gd=0;
                        }
                    }
                    j=ma[j-1];
                }
                f=1-f;
            }
        }
        if (!gd)
        {
            return false;
        }
        return true;
    }
}
int main ()
{
    int c,n,m,q;
    cin>>c>>n>>m>>q;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        aa[i]=a[i];
    }
    for (int i=1;i<=m;i++)
    {
        cin>>b[i];
        bb[i]=b[i];
    }
    cout<<solve(n,m);
    while (q--)
    {
        for (int i=1;i<=n;i++)
        {
            a[i]=aa[i];
        }
        for (int i=1;i<=m;i++)
        {
            b[i]=bb[i];
        }
        int kx,ky;
        cin>>kx>>ky;
        while (kx--)
        {
            int p,v;
            cin>>p>>v;
            a[p]=v;
        }
        while (ky--)
        {
            int p,v;
            cin>>p>>v;
            b[p]=v;
        }
        cout<<solve(n,m);
    }
}