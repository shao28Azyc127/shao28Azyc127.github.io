#include <bits/stdc++.h>
using namespace std;
int main()
{

    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long k,n,l=0,minn=-1;
    bool tr=true;
    cin>>n;
    while(n>3)
    {
        l++;
        if(n%3==1&&tr==true)
        {
            minn=l;
            tr=false;
        }
        int as=n/3*2+(n-1)%3;
        n=as;
    }
    if(minn=-1)
    {

        cout<<n+l<<" "<<n+l;
    }
    else
    {
        cout<<n+l<<" "<<minn;
    }
    return 0;
}