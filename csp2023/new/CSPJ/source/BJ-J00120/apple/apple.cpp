#include <iostream>
using namespace std;
const int N=1e9+2;
long long n;
int cnt=0,ans=0,m=0;
bool flag=0,flag2=0;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(ans<=n)
    {
        if(ans==n)
        {
            flag=1;
            cout<<cnt;
            break;
        }
        int x=n-ans;
        int y;
        if(x%3==0)
        {
            y=x/3;
        }
        else if(x%3==1)
        {
            y=x/3+1;
            if(flag2==0)
            {
                m=cnt+1;
                flag2=1;
            }
        }
        else if(x%3==2)
        {
            y=x/3+1;
        }
        ans+=y;
        cnt++;
    }
    if(flag==0)
    {
        cout<<cnt+1;
    }
    cout<<" "<<m;
    return 0;
}