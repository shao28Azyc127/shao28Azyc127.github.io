#include<bits/stdc++.h>
using namespace std;
long long n,a[200000005]={0},k,s=0,ans1;
bool f=false;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            s++;
            if(i==n) ans1=s;
            int ss=0;
            for(long long j=i+1;j<=n;j++)
            {
                if(a[j]==0)
                {
                    ss++;
                    if(ss==3)
                    {
                        a[j]=1;
                        if(j==n) ans1=s;
                        ss=0;
                    }
                }
            }
            a[i]=1;
        }
    }
    printf("%lld %lld",s,ans1);
    return 0;
}
