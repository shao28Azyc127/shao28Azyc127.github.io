#include <cstdio>
#include <iostream>
using namespace std;

int cnt=0;
int a=0;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n=0;
    cin>>n;
    while(n>0)
    {
        if(n%3==1)
        {
            a=cnt+1;
            break;
        }
        int q=n-1;
        n=n-q/3-1;
        cnt++;
    }
    while(n>0)
    {
        int q=n-1;
        n=n-q/3-1;
        cnt++;
    }
    cout<<cnt<<" "<<a;
    return 0;
}
