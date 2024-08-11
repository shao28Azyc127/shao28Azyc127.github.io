#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int ans1=0,ans2=0,flag=1;
    int k=n;
    while(k>0)
    {
        ans1++;
        if((k+2)%3==0&&flag==1)
        {
            ans2=ans1;
            flag=0;
        }
        k=k-(k+2)/3;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
