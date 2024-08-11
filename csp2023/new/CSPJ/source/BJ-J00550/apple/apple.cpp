#include<iostream>
using namespace std;

typedef long long ll;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ll n;cin>>n;
    ll ret1=0,ret2=0,isf=1;
    while(n)
    {
        ret1++;
        if(isf&&n%3==1) ret2=ret1,isf=0;
        n-=(n+2)/3;
    }
    cout<<ret1<<' '<<ret2<<endl;
    return 0;
}