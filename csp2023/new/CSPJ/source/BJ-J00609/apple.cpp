#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;


int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    queue<int> q;
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        q.push(i);
    }
    int ans = 0, temp;
    while(!q.empty())
    {
        int s = q.size();
        int idx=1;
        for(int i=1;i<=s;i++)
        {
            if (idx%3==1)
            {
                int v = q.front();
                if (v == n)
                {
                    temp = ans + 1;
                }
                q.pop();
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
            idx++;
        }
        ans++;
    }
    cout << ans << " " << temp;
    fclose(stdin);
    fclose(stdout);
    return 0;
}