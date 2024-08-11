#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0,t=0;
    while(n>0)
    {
        if((n-1)%3==0&&t==0)t=cnt+1;
        cnt++;
        n-=(n-1)/3+1;
    }
    cout<<cnt<<" "<<t<<endl;
    return 0;
}

