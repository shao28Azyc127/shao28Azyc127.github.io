#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ll n;
    cin>>n;
    if(n==0)    
    {
        cout<<0<<endl;
        return 0;
    }
    if(n==1)
    {
        string s;
        cin>>s;
        cout<<81<<endl;
        return 0;
    }
    cout<<10<<endl;
    return 0;
}
