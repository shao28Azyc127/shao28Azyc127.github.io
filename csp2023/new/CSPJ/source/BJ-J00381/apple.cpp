#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long i,j,n,m,k,s=0,x=-1,y,l,r,o;
    cin>>n;
    m=n;
    while(n)
    {
        s++;
        if(x==-1&&m%3==1)
        {
            x=s;
        }
        m-=(long long)(ceil(n*1.0/3));
        n-=(long long)(ceil(n*1.0/3));
    }
    cout<<s<<" "<<x;
    return 0;
}