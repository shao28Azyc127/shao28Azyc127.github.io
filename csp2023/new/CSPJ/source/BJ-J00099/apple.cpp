#include<bits/stdc++.h>
using namespace std;

int n,ans;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int cnt=0;
    bool flag=true;
    while(n>0)
    {
        cnt++;
        if(n%3==1 && flag)
        {
            ans=cnt;
            flag=false;
        }
        n-=(n+2)/3;
    }
    cout<<cnt<<" "<<ans<<endl;

    return 0;
}
