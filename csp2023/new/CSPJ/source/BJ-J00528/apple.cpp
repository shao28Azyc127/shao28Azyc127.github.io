#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,ans,cnt=0;
    bool flag=true;
    cin>>n;
    while (n)
    {
        cnt++;
        long long sum=n/3;
        if (n%3==1)
            if (flag)
            {
                ans=cnt;
                flag=false;
            }
        sum+=(n%3!=0);
        n-=sum;
    }
    cout<<cnt<<" "<<ans;
    return 0;
}