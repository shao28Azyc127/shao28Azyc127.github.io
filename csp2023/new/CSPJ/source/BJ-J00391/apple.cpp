#include<bits/stdc++.h>
using namespace std;
    queue<int> q;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,k=0,sum,w=1,t=1,ans;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        q.push(i);
    }
    while(q.size())
    {
        if(q.front()==n) ans=t;
        q.pop();
        for(int i=1;q.size()>=3;i++)
        {
            q.push(q.front());
            q.pop();
            if(q.front()<q.back())  break;
            q.push(q.front());
            q.pop();
            if(q.front()<q.back())  break;
            if(q.front()==n) ans=t;
            q.pop();
            if(q.front()<q.back())  break;
        }
        t++;
    }
    cout<<t-1<<" "<<ans;
    return 0;
}
