#include <iostream>
using namespace std;
const int N=1e6+5;
bool f[N];
int n,ans=0,ans1;
bool check()
{
    for(int i=1;i<=n;i++) if(!f[i]) return false;
    return true;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(true)
    {
        if(check()) break;
        ans++;
        int cur=1;
        for(int i=1;i<=n;i++)
        {
            if(cur==1 && !f[i])
            {
                if(i==n) ans1=ans;
                f[i]=true;
                cur++;
            }
            else if(!f[i]) cur++;
            if(cur>3) cur%=3;
        }
    }
    cout<<ans<<" "<<ans1;
    return 0;
}
