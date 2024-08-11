#include <bits/stdc++.h>
using namespace std;
int n;
int t;
int arr[1000000];
int ans;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int num=n;
    bool temp=1;
    while(num)
    {
        if((num-1)%3==0&&temp)
        {
               ans=t+1;
               temp=0;
        }

        num-=(num+2)/3;

        t++;
    }
    cout<<t<<" "<<ans;
    return 0;
}
