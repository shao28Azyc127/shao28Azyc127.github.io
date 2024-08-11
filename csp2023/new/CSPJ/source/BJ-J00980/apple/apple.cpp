#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0,ans=1,flag=true;
    int m=n;
    while(m>0)
    {
        cnt++;
        if(m%3==1 && flag==true)
        {
            ans=cnt;
            flag=false;
        }
        m=m-ceil((m+0.0)/3);
    }
    cout<<cnt<<" "<<ans<<endl;
    return 0;
}
