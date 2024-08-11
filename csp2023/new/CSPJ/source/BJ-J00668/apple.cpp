#include<bits/stdc++.h>
using namespace std;
long long n,cnt,num;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int a=n;
    while(n!=0)
    {
        cnt++;
        if((n-1)%3==0&&num==0)
        {
            num=cnt;
        }
        n-=1;
        n-=n/3;
    }
    cout<<cnt<<" "<<num;
    return 0;
}
