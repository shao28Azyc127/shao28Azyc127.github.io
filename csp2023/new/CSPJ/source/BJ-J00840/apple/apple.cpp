#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,d,num,k;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    d=n;
    if(n%3==1) k=1;
    while(d!=0)
    {
        num=0;
        if(d%3==2) num=1;
        if(d%3==1)
        {
            if(k==0)
            {
                k = sum+1;
            }
        }
        d=d/3*2;
        d+=num;
        sum++;
    }
    cout<<sum<<" "<<k;
    return 0;
}