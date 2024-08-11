#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,sum=0,p=0,q=0;
    cin>>n;
    while(n>0)
    {
        sum++;
        if((n-1)%3==0 and q==0)
        {
            p=sum;
            q++;
        }
        int t;
        t=(n-1)/3;
        n=n-t-1;

    }
    cout<<sum<<" "<<p;
    return 0;
}
