#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,ans,i;
    cin>>n;
    for(i=1;n;i++)
    {
        if(n%3==1)
        {
            ans=i;
            break;
        }
        for(long long j=1,k=n;j<=k;j++)if(j%3==1)n--;
    }
    for(;n;i++)for(long long j=1,k=n;j<=k;j++)if(j%3==1)n--;
    cout<<i-1<<' '<<ans;
    return 0;
}
