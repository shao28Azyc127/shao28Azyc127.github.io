#include<bits/stdc++.h>
using namespace std;
long long n,n1,ans1;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    n1=n;
    while(n1!=0)
    {
        ans1++;
        if(n1%3==0)
        {
            n1=n1-(n1/3);
        }
        else
        {
            n1=n1-(n1/3+1);
        }
    }
    int i=1;
    while(n%3!=1)
    {
        if(n%3==0)
        {
            n=n-(n/3);
        }
        else
        {
            n=n-(n/3+1);
        }
        i++;
    }
    cout<<ans1<<" "<<i;
    return 0;
}
