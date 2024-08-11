#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans=0,d=0,i=1,a,m,j;
    cin>>n;
    m=n;
    while(n>0)
    {
        if(n%3==0)
        {
            n=n-n/3;
            ans++;
        }
        else
        {
            n=n-floor(n/3)-1;
            ans++;
        }
    }
    cout<<ans<<" "<<"1";
    return 0;
}
