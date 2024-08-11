#include<bits/stdc++.h>
using namespace std;
int n,ans,cnt;
bool g=false;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(1)
    {
        ans++;
        if(!g && n%3==1)
        {
            cnt=ans;
            g=true;
        }
        if(n%3==0) n-=n/3;
        else n-=(n/3+1);
        if(n==0) break;
    }
    cout<<ans<<" "<<cnt;
    return 0;
}
