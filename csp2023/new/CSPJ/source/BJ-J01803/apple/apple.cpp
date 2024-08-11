#include <iostream>
using namespace std;
long long n,d,ans,num,o;
bool a[100005];
void apple(int x)
{
    if (x==0)
    {
        return;
    }
    ++num;
    x -= (x+2)/3;
    apple(x);
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    if(n==1||n==2||n==3)
    {
        cout << n << n;
        return 0;
    }
    apple(n);
    o=n;
    for (int i=1; i<=n; ++i)
    {
        if(o%3==1)
        {
            ans=i;
            break;
        }
        o-=(o+2)/3;
    }
    cout << num << " " << ans;
    return 0;
}
