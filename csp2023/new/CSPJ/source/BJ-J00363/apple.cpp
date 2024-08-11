#include<bits/stdc++.h>
using namespace std;
long long n;
long long sum;
int b=0;
long long  m,s;
long long a[100000005];

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
    }
    long long x=n;
    long long  ans;
    for(int i=1;i<=n;i++)
    {
        int y=x;
        if(a[i])
        {
            a[i]=0;
            x--;
        if(n-i>=3)
        {
            for(int j=i;j<=n;j+=m)
            {
                for(s=0,m=0;s<3;m++)
                {   if(j+m>n)
                    break;
                    if(a[j+m])
                    s++;
                    if(s==3)
                    {
                        a[j+m]=0;
                        x--;
                    }
                }
            }
        }
        }
        if(y!=x)
        {
            sum++;
        }
        if(a[n]==0&&b==0)
        {
            ans=sum;
            b=1;
        }
        if(x==0)
        break;

    }
    cout<<sum<<" "<<ans;
    return 0;
}