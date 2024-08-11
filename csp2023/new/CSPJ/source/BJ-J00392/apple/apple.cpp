#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    long long ans1,ans2,s=n,f=0;
    long long i;
    for(i=1;s>0;i++)
    {
        if((s%3)==1&&f==0)
        {
            f=1;
            ans2=i;
        }
        s-=(s-1)/3+1;
    }
    ans1=i-1;
    cout<<ans1<<" "<<ans2;
    return 0;
}
