#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,a[10005]= {0},len,ans,j;
    scanf("%lld",&n);
    len=n;
    j=1;
    while(len!=0)
    {
        long long b=0,i=0;
        while(i!=n)
        {
        	i++;
            if(a[i]==0)
            {
                if(b==0)
                {
                    a[i]=1;
                    len--;
                    if(i==n)
                    {
                        ans=j;
                    }
                }
                b++;
                if(b==3)
                {
                    b=0;
                }
            }
        }
        j++;
        if(len==0)
        {
            j--;
            break;
        }
    }
    printf("%lld %lld",j,ans);
    return 0;
}