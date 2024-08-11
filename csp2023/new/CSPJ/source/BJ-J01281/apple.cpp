#include<bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    long long i=3;
    while(i<=1e9)
    {
        if(n%3==2)
        {
            cout<<n/3+3;
            break;
        }
        if(n%i==0)i++;
        else
        {
            cout<<n%i;
            break;
        }
    }
    cout<<" ";
    int sum=0;
    while(n>=0)
    {
        sum++;
        n-=n/3+1;
    }
    cout<<sum;
    return 0;
}
