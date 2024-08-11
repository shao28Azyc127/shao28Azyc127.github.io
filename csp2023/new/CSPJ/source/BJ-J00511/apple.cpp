#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt=1,cnt2=0,t=0;
    cin>>n;
    //cout<<n;
    t=n;
    while((n-1)%3!=0)
    {
        n-=(n-1)/3+1;
        cnt++;
        //cout<<cnt;
    }
    n=t;
    while(n>0)
    {
        n=n-(n-1)/3-1;
        cnt2++;
        //cout<<n<<endl;
    }
    cout<<cnt2<<" "<<cnt;
    return 0;
}
