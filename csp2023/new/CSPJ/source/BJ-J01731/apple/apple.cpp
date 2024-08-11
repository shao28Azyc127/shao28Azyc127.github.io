#include <iostream>
using namespace std;
bool a[1000000001];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0;
    int day=0;
    int ans=0;
    bool b=0;
    while(cnt!=n)
    {
        day++;
        if((n-1-cnt)%3==0 && b==0)
        {
            ans=day;
            b=1;
        }
        cnt+=(n-cnt-1)/3+1;
    }
    cout<<day<<" "<<ans;
    return 0;
}