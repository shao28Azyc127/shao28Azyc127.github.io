#include<bits/stdc++.h>
using namespace std;
int a[100000005];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,x,y;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
    }
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=n;j++)
        {
            if(j%3==1)
            {
                if(a[j]==n)
                {
                    x=i;
                }
                a[j]=0;
            }
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            a[i]=a[i+n/3+1];
        }
        if(a[1]==0)
        {
            y=i;
            break;
        }
    }

    cout<<y<<" "<<x;
    return 0;
}