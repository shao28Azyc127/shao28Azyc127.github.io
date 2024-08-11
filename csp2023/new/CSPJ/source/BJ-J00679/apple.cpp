#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,nn,sum=0,day=0;
    cin>>n;
    nn=n;
    while(nn)
    {
        sum++;
        if((nn+2)%3==0&&day==0)
        {
            day=sum;
        }
        nn=nn-nn/3-bool(nn%3);
    }
    cout<<sum<<' '<<day;
    return 0;
}
