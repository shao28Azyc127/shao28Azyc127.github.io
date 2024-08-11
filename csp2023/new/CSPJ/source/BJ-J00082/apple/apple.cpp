#include <bits/stdc++.h>
using namespace std;
long long n,num,n1,num1,cnt=1;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    n1=n;
    num1=n;
    while(n>0)
    {
        n=n-ceil(n*1.0/3);
        num++;
    }
    cout<<num<<" ";
    while(n1>0)
    {
        if(num1%3==1)
        {
            cout<<cnt;
            return 0;
        }
        else
        {
            cnt++;
        }
        num1=num1-ceil(n1*1.0/3);
        n1=n1-ceil(n1*1.0/3);
    }
    return 0;
}
