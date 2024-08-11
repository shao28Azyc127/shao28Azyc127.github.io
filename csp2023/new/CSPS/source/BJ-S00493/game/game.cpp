#include<bits/stdc++.h>
using namespace std;
string s;
int ans;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)
        for(int j=n-1;j>=i;j--)
        {
            stack<char> stk;
            int base=1;
            for(int k=i;k<=j;k++)
            {
                if(!stk.empty())
                if(s[k]!=stk.top())
                {
                    stk.push(s[k]);

                }
                else
                {
                    stk.pop();
                }
                else stk.push(s[k]);
            }
            if(stk.empty())
            {
                ans++;
            }
        }
    cout<<ans;
    return 0;
}
