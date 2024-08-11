#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ll i,j;
    ll n;
    cin>>n;
    ll ansn,js=0;
    bool pd=0;
    while(n)
    {
        js++;
        if(n%3==1)
        {
            if(!pd)
            {
                ansn=js;
                pd=1;
            }
            n-=(n/3+1);
        }
        else if(n%3==0)
        {
            n-=(n/3);
        }
        else if(n%3==2)
        {
            n-=(n/3+1);
        }
    }
    cout<<js<<" "<<ansn;
    return 0;
}
