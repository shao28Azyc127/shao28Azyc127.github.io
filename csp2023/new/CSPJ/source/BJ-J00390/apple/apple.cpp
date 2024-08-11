#include<iostream>
using namespace std;
long long check(long long n)
{
    int sum=0;
    while(n>0)
    {
        if(n%3==0)
        {
            n=n-n/3;
            sum++;
        }
        else
        {
            n=n-(n/3+1);
            sum++;
        }
    }
    return sum;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,ans;
    cin>>n;
    if((n-1)%3==0)
    {
        ans=1;
    }
    else if((n-1)%3==1)
    {
        ans=check(n);
    }
    else
    {
        ans=n/3;
    }
    cout<<check(n)<<" "<<ans;
}
