#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int sum,ans;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        q.push(i);
    }
    while(q.size())
    {
        sum++;
        int m=q.size();
        for(int i=0;i<m;i++)
        {
            int x=q.front();
            q.pop();
            if(i%3==0&&x==n)
            {
                ans=sum;
            }
            if(i%3!=0)
            {
                q.push(x);
            }
        }
    }
    cout << sum << " " << ans;
    return 0;
}
