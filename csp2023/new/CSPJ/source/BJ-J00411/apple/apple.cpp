#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
ll n,m,i,j,k,ans1,ans2,day;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(1)
    {
        day++;
        if(n%3==1&&!ans1) ans1=day;
        n-=ceil(n*1.0/3);
        if(!n) break;
    }
    cout<<day<<" "<<ans1;
    return 0;
}
