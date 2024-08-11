#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=0;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    m=n;
    while(n!=1)
    {
        if(n%3==0) n-=n/3;
        else n=n-((n/3)+1);
        cnt++;
        //cout<<n<<" ";//test
    }
    cout<<cnt+1<<" ";
    if(m%3==1) cout<<1;
    else cout<<cnt+1;
    return 0;
}
