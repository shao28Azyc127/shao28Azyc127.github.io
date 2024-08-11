#include<bits/stdc++.h>
using namespace std;
int n,sum,tian,a,ans=1;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    a=n;
    while(a>0)
    {
        sum+=a/3;
        if(a%3!=0)
        {
            sum++;
        }
        a-=sum;
        sum=0;
        tian++;
    }
    cout<<tian<<" ";
    while(n>0)
    {
        if(n%3==1)
        {
            cout<<ans;
            return 0;
        }
        sum+=n/3;
        if(n%3!=0)
        {
            sum++;
        }
        n-=sum;
        sum=0;
        ans++;
    }
    return 0;
}