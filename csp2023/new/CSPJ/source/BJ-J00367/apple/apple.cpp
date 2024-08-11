#include <iostream>

using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    bool flag=0;int ans,i;
    cin>>n;
    for(i=1;;i++)
    {
        if((n-1)%3==0 && !flag)
        {
            flag=1;ans=i;
        }
        if(n==1)break;
        n-=(n-1)/3+1;
    }
    cout<<i<<" "<<ans;
    return 0;
}
