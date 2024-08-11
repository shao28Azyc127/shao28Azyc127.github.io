#include<bits/stdc++.h>
using namespace std;
int n;
char a[8005];
stack<char>s;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(!s.empty()&&s.top()==a[j])
            {
                s.pop();
            }
            else
            {
                s.push(a[j]);
            }
            if(s.empty())
            {
                ans++;
            }
        }
        while(!s.empty())
        {
            s.pop();
        }
    }
    cout<<ans;
}
