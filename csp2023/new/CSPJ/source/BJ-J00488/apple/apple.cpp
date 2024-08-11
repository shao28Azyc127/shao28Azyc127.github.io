#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans1,ans2;
    cin>>n;
    ans1=(n-2)/3+2;
    if(n%3==0)
        ans2=n%3;
    else if(n%3==1)
        ans2=1;
    else if(a%3==2)
        ans2=n;
    cout<<ans1<<" "<<ans2;
    return 0;
}