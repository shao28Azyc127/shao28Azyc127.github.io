#include <iostream>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long n;
    long i=1;
    long t=99999999;
    cin>>n;
    while(n!=0)
    {
        if(n%3==1&&t>i)
        {
            t=i;
        }
        n--;
        n=n-n/3;
        i++;
    }
    i--;
    cout<<i<<" "<<t;
    return 0;
}
