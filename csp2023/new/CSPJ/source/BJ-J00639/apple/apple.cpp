#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,m,cnt=0,ans=0;
bool flag=false;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    m=n;
    while(m)
    {
        cnt++;
        if(m%3==1 and flag==0)
        {
            flag=1;
            ans=cnt;
        }
        if(m%3==0)
        {
            m-=(m/3);
        }
        else
        {
            m-=(m/3+1);
        }
    }
    cout<<cnt<<" "<<ans<<endl;
    return 0;
}
