#include<bits/stdc++.h>
using namespace std;
long long n,ans1,ans2;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    while(n)
    {
        ans1++;
        if(n%3==1&&ans2==0)
        {
            ans2=ans1;
        }
        n-=ceil(n/3.0);
    }
    printf("%lld %lld\n",ans1,ans2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
