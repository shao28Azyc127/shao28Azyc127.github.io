#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0,day=0;
    while(n)
    {
        cnt++;
        if(n%3==1&&!day)day=cnt;
        if(n%3==0)n-=n/3;
        else n-=n/3+1;
    }
    cout<<cnt<<" "<<day<<endl;
    return 0;
}