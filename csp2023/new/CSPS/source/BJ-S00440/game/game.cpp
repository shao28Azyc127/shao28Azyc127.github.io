#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
char a[200005];
stack<char> q;
#define int long long
signed main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    int i;
    int j;
    int ans=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            if(!q.empty())
            {
                if(q.top()==a[j])
                {
                    q.pop();
                }
                else
                {
                    q.push(a[j]);
                }
            }
            else
            {
                q.push(a[j]);
            }
            if(q.empty())
            {
                //cout<<i<<" "<<j<<endl;
                ans++;
            }
        }
        while(!q.empty())
        {
            q.pop();
        }
    }
    cout<<ans;
    return 0;
}
