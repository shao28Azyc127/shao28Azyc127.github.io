#include<cstdio>
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,ans=0,cnt=0;
    scanf("%lld",&n);
    while(n)
    {
        ++ans;
        if((n-1)%3==0&&cnt==0) cnt=ans;
        n=n-1-(n-1)/3;
    }
    printf("%lld %lld\n",ans,cnt);
    return 0;
}