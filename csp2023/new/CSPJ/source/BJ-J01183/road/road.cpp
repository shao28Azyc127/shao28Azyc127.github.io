#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010],s[100010],f[100010];
int zz(int l,int r,int cnt)
{
    if(l>r) return cnt-1;
    int maxn=1e9+7,k=0;
    for(int i=l;i<=r;i++)
    {
        if(maxn>=a[i])
        {
            maxn=a[i];
            k=i;
        }
    }
    f[cnt]=k;
    return zz(l,k-1,cnt+1);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >> n >> d;
    for(int i=1;i<=n-1;i++)
    {
        cin >> s[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int k=zz(1,n-1,1);
    cout << k << endl;
    /*for(int i=1;i<=k;i++)
    {
        cout << f[i] << endl;
    }*/
    f[k+1]=n;
    sort(f+1,f+k+1);
    int t=0,sum=0;
    for(int i=1;i<=k;i++)
    {
        int p=0;
        for(int j=f[i];j<=f[i+1]-1;j++)
        {
            p+=s[j];
        }
        p-=t;
        t=0;
        int x=(p+d-1)/d;
        t=x*d-p;
        sum+=x*a[f[i]];
        //cout << sum << " " << f[i] << endl;
    }
    cout << sum << endl;
    return 0;
}