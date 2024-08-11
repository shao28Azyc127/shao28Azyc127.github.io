#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    int cnt=0,ans=0;
    while(n)
    {
        cnt++;
        if(n%3==1&&(ans==0))
        {
            ans=cnt;
        }
        n-=(n+2)/3;

    }
    cout<<cnt<<" "<<ans;
    return 0;
}
