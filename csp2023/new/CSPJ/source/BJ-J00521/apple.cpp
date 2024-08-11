#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#include<time.h>
#include<cstdio>
#include<map>
#include<set>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans=0,m,anss=-1;
ll cmp(ll m)
{
    if(m%3==0) return m/3;
    else return m/3+1;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    m=n;
    while(m)
    {
        ans++;
        if(n%3==1&&anss==-1) anss=ans;
        n-=cmp(m);
        m-=cmp(m);
    }
    cout<<ans<<" "<<anss;
    return 0;
}
