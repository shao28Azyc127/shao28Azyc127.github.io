#include<bits/stdc++.h>
using namespace std;
stack<char > q;
char s[2000005];
int main()
{
    int n;
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    int ans=0;
    for(int i=0;i<=n-1;i++)
    {
        for(int j=i;j<=n-1;j++)
        {
            if(!q.empty())
            {
                if(q.top()!=s[j]) q.push(s[j]);
                else
                {
                    q.pop();
                    if(q.empty()) ans++;
                }
            }
            else
            {
                q.push(s[j]);
            }
        }
        while(!q.empty()) q.pop();
    }
    cout<<ans<<endl;
    return 0;
}
