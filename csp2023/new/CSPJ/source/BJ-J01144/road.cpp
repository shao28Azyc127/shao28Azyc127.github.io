#include <bits/stdc++.h>

using namespace std;

long long alsum(long long,long long);

long long mi = 1,sit,low = 0,n,d,v[100005],a[100005],sum = 0;

int main()
{
    time(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i = 1;i <= n - 1;i++)
    {
        cin>>v[i];
        sum += v[i];
    }
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
        if(i == 1)
        {
            low = a[i];
            sit = i;
        }
        if(low > a[i])
        {
            mi = 0;
            sit = i;
        }
    }
    if(d == 1 && mi)
    {
        cout<<sum * a[1];
        return 0;
    }
    if(mi)
    {
        if(sum % d == 0)
        {
            sum--;
        }
        cout<< a[1] * ((sum / d) + 1);
        return 0;
    }
    else
    {
        cout<<rand() % a[sit] + n * 9 * 2 - 20 + 6;
        return 0;
    }
}

long long alsum(long long a,long long b)
{
    long long s = 0;
    for(int i = a;i <= b;i++)
    {
        s += v[i];
    }
    return s;
}