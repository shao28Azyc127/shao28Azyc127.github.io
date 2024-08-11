#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 100005;
int n,d,a[N],v[N];
int work(int a)
{
    int ret = 0;
    if(a%4 == 0) ret = a/4;
    else ret = (a/4)+1;
    return ret;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i = 1;i < n;++i) cin>>v[i];
    for(int i = 1;i <= n;++i) cin>>a[i];
    int minn = 0x3f3f3f3f;
    long long cost = 0;
    long long rest = 0;
    for(int i = 1;i <= n;++i)
    {

        minn = min(minn,a[i]);
        if(rest >= v[i])
        {
            rest -= v[i];
            continue;
        }
        int need = v[i]-rest;
        cost += minn*work(need);
        rest += 4*work(need);
        rest -= v[i];
    }
    cout<<cost<<endl;
    return 0;
}
