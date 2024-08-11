#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int cnt=1;
    int ans=1e9;
    while(n>0)
    {
        if((n-1)%3==0)
        {
            ans=min(ans,cnt);
        }
        n-=ceil((n)*1.0/3);
        if(n!=0) cnt++;

        //cout<<n<<" ";
    }
    ans=min(ans,cnt);
    cout<<cnt<<" "<<ans;
    return 0;
}
