#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int ans1,ans2;
queue<int>q,q1;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) q.push(i);
    while(!q.empty())
    {
        cnt=0;
        while(!q.empty())
        {
            while(!q.empty())
            {
                if(cnt!=0)
                {
                    int t=q.front();
                    q.pop();
                    q1.push(t);
                }else
                {
                    if(q.front()==n) ans2=ans1+1;
                    q.pop();
                }
                cnt++;
                cnt%=3;
            }
            ans1++;
        }
        while(!q1.empty())
        {
            q.push(q1.front());
            q1.pop();
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
