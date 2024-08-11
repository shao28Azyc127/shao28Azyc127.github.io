#include <iostream>

using namespace std;
int n;
string s;
bool chk(int x,int y)
{
    int a[128]={};
    for(int i=x;i<=y;i++)
    {
        a[s[i]-1]++;
    }
    for (int i=0;i<128;i++)
    {
        if (a[i]%2==1)
        {
            return 0;
        }
    }
    bool f=0;
    for (int i=x+1;i<=y;i++)
    {
        if(s[i]==s[i-1])
        {
            f=1;
        }
    }
    if (f==0)
    {
        return 0;
    }
}
int check(int x)
{
    int ans=0;
    for (int i=x+1;i<n;i++)
    {
        if (chk(x,i))
        {
            ans++;
        }
    }
    return ans;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >>  n;
    cin >>  s;
    int ans=0;
    for (int i=0;i<n-2;i++)
    {
        ans+=check(i);
    }
    cout << ans;

    return 0;
}
