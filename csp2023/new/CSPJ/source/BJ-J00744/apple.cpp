#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans=0,j=0,cnt=0,l,a,b;
    cin>>n;
    j=n;
    l=n;
    b=n;
    for(int i=1;i<=j;i++)
    {
        n=(n/3*2)+max(n%3-1,0);
        ans++;
        if(n==0)
        {
            break;
        }
    }
    for(int i=1;i<=ans;i++)
    {
        cnt++;
        if(b%3==1)
        {
            break;
        }
        a=(l/3)+min(l%3,1);
        l=(l/3*2)+max(l%3-1,0);
        b=b-a;
    }
    cout<<ans<<" "<<cnt;
    return 0;
}
