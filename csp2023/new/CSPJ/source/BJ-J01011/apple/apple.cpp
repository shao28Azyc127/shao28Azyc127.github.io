#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,cnt=0,cur=1e9+10;
    cin>>n;
    while(n!=0)
    {
        cnt++;
        if(n%3==1&&cur==1e9+10) cur=cnt;
        n=n-(n/3+min(1,n%3));
    }
    cout<<cnt<<" "<<cur;
    return 0;
}
