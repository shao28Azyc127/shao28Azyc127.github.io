#include<iostream>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int a=n;
    int ans=0;
    while(a>0)
    {
        a-=(a-1)/3+1;
        ans++;
    }
    cout<<ans<<" ";
    ans=1;
    while(n%3!=1)
    {
        ans++;
        n-=(n-1)/3+1;
    }
    cout<<ans;
    return 0;
}