#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int N=1e6+10;
vector <int> s[2];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int i,j,k,n,cnt=0,ans=0,w=0;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        s[0].push_back(i);
    }
    while (s[0].size()>0)
    {
        cnt++;
        for(i=0;i<s[0].size();i++)
        {
            if (i%3!=0)
                s[1].push_back(s[0][i]);
            else
            {
                if (s[0][i]==n)
                    ans=cnt;
            }
        }
        s[0].clear();
        for (i=0;i<s[1].size();i++)
            s[0].push_back(s[1][i]);
        s[1].clear();
    }
    cout<<cnt<<' '<<ans<<endl;
    return 0;
}
