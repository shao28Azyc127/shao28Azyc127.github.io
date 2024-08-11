#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,mn[3005],mx[3005];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int i;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        mn[i]=1000;
        for(int j=0;j<m;j++)
        {
            mn[i]=min((int)s[j],mn[i]);
            mx[i]=max((int)s[j],mx[i]);
        }
    }
    for(i=1;i<=n;i++)
    {
        int fl=1;
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            if(mn[i]>=mx[j])
            {
                fl=0;
                break;
            }
        }
        cout<<fl;
    }
    return 0;
}
