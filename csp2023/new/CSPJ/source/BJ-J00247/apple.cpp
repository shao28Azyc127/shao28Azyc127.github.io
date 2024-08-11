#include<bits/stdc++.h>
using namespace std;
int n,i=0,t=0;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n>0)
    {
        i++;
        if((n-1)%3==0)
        {
            if(!t)
                cout<<i<<" ";
            n-=(n-1)/3+1;
            t=1;
        }
        else
        {
            n-=(n-1)/3+1;
        }
    }
    cout<<i;
    return 0;
}
