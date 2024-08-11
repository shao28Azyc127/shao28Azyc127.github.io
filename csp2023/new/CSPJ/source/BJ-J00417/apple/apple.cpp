#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int n1=n;
    int cnt=0,ans=0;
    while(n!=0)
    {
        int n2=n;
        n-=ceil(1.0*n/3);
        cnt++;
    }
    if(n1%3==2)
    {
        ans=cnt;
    }
    else if(n1%3==1)
        ans=1;
    else
        ans=3;
    cout<<cnt<<" "<<ans<<endl;
    return 0;
}
