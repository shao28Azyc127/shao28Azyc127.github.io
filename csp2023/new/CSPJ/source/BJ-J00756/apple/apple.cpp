#include<bits/stdc++.h>
using namespace std;
long long a[100000000];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,cnt=0,f=0;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        f=0;
        for(long long j=1;j<=cnt;j++)
        {
            if(a[j]>=2)
            {
                a[j]-=2;
                f=j;
                break;
            }
        }
        if(f)
        {
            for(long long j=1;j<f;j++)
                a[j]++;
        }
        else
        {
            cnt++;
            for(long long j=1;j<cnt;j++)
                a[j]++;
        }
        if(i==n)
        {
            cout<<cnt<<" ";
            if(f)
                cout<<f;
            else
                cout<<cnt;
        }
    }
    return 0;
}
