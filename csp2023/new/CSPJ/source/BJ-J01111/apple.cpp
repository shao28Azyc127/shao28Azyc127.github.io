#include<bits/stdc++.h>
using namespace std;
int n,a,b,f;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    b=n;
    while(n)
    {
        a++;
        if(n%3==1)
        {
            b=min(b,a);
        }
        if(n%3!=0)
        {
            f=1;
        }
        n=n-n/3-f;
        f=0;
        if(!n)
        {
            break;
        }
    }
    cout<<a<<" "<<b<<"\n";
    return 0;
}
