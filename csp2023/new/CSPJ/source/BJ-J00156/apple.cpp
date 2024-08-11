#include <iostream>
using namespace std;
#define IO_ON_FILE
int n;
int main()
{
    #ifdef IO_ON_FILE
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    #endif // IO_ON_FILE
    cin>>n;
    int m=n,ans=0;
    while(m>=1)
    {
        m-=m/3+(m%3>=1);
        ans++;
    }
    cout<<ans<<" ";
    m=n;
    ans=1;
    while(m%3!=1)
    {
        m-=m/3+(m%3>=1);
        ans++;
    }
    cout<<ans;
    return 0;
}
