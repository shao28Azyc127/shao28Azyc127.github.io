#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n,t=0,day=0,ans;
queue <int>q;
queue <int>p;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        q.push(i);
    }
    while (!q.empty() or !p.empty())
    {
        t=1;
        day++;
        while (!q.empty())
        {
            int temp=q.front();
            q.pop();
            if ((t-1)%3==0 and temp==n)
            {
                ans=day;
            }
            else if ((t-1)%3!=0)
            {
                p.push(temp);
            }
            t++;
        }
        while (!p.empty())
        {
            int temp=p.front();
            p.pop();
            q.push(temp);
        }
    }
    cout<<day<<" "<<ans<<endl;
    return 0;
}
