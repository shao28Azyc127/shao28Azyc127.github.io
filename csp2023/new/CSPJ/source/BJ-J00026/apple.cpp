#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,sa,f=0,i;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    m=n;
    for(i=1;m!=0;i++)
    {

        if((m%3)==1&&f==0)
        {
            f=1;
            sa=i;
        }
        if(m%3==0)
        {
            m-=(m/3);
        }
        else
        {
            m-=(m/3)+1;
        }
        if(m==0)
        {
            break;
        }
    }
    cout<<i<<" "<<sa;
    return 0;
}
