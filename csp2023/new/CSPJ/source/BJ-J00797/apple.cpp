#include<bits/stdc++.h>
using namespace std;
long long n,ans1,ans2,a[1000005];
int dfs(long long n)
{
    long long as=0;
    if(n%3==2)return ans1;
    if(n%3==1)return 1;
    else
    {
        n-=n/3;
        as++;
        return dfs(n)+as;
    }
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    if(n<=2)cout<<n<<" "<<n;
    else
    {
        long long cnt=0;
        while(n>2)
        {
            if(n%3==1)n-=n/3;
            else n-=n/3+1;
            cnt++;
        }
        if(n==2)ans1=cnt+2;
        else ans1=cnt+1;
        ans2=dfs(n);
        cout<<ans1<<" "<<ans2;
    }
    return 0;
}
