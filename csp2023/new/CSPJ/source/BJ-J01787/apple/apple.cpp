#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    long long c=n;
    long long time=0;
    while(c)
    {
        c-=(c+2)/3;
        time++;
    }
    cout<<time<<" ";
    if(n%3==1)
    {
        cout<<1;
    }
    else
    {
        cout<<time<<"\n";
    }
    return 0;
}
