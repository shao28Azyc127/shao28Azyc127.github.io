#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,cnt,cntt;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    cnt=1;
    cntt=1;
    while(n%3!=1)
    {
        cnt++;
        cntt++;
        n=n-ceil(n/3.0);
        //cout<<"n="<<n<<'\n';
    }
    while(n)
    {
        cntt++;
        n=n-ceil(n/3.0);
        //cout<<"n="<<n<<'\n';
    }
    //if(n)
    //    cout<<cntt<<' '<<cnt;
    //else
    cout<<cntt-1<<' '<<cnt;
    return 0;
}
