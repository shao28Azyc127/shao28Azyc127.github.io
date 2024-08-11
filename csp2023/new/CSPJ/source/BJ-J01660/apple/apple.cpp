#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;
signed main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int a=n,b=0,c,t=0,o=0;
    while(a>0)
    {
        a-=b;
        b=(a+2)/3;
        c=(a+2)%3;
        t++;
        if(c==0&&o==0)
        {
            o=t;
        }
    }
    cout<<t-1<<" "<<o;
    return 0;
}
