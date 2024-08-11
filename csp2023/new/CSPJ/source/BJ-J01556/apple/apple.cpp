#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,ans=0,last,temp=0,ans2=0;
    cin>>n;
    last=n;
    while(n!=0)
    {
        n=n-(n-1)/3-1;
        ans++;
        if(last%3==1&&temp==0)
        {
            ans2=ans;
            temp++;
        }
        last=n;
    }
    cout<<ans<<" "<<ans2;
    return 0;
}
