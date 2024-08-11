#include<bits/stdc++.h>
using namespace std;


long long n,da,res;


int main()

{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    
    while(n!=0)
    {
        int m;
        if(n%3!=0)
        {
            m=n/3+1;
        }
        else
        {
            m=n/3;
        }
        if(n%3==1) da=res+1;
        n-=m;
        res++;
    }
    cout<<res<<" "<<da;
    return 0;
}