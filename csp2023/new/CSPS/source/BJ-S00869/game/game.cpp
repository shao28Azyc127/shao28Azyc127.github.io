#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
typedef pair<int,int> pii;
struct Node
{
    int s, t, v;
};
bool operator>(const Node a, const Node b)
{
    return a.t>b.t;
}
priority_queue< Node, vector<Node>, greater<Node> > q;
int n, now;
int st;
int ans;
int has[512];
char input[N];
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d%s", &n, input+1);
    st = 1; has[input[1]] = 1;
    // q.push((Node){0,0,0});
    for (int i = 2; i <= n; i++)
    {
        

        char c = input[i];
        if (input[st] == input[i])
        {
            st--;
            ans++;
            now++;
            if (q.size()>0 && st == q.top().t)
            {
                // printf("t = %d\n", q.top().t);

                Node tmp=q.top();
                q.pop();
                
                ans += tmp.v;
                tmp.t=i;
                tmp.v*=2;
                q.push(tmp);
                now = 0;
                st = max(tmp.s-1, 0);
            }
        }
        else
        {
            q.push((Node){st+1, i-1, 1});
            st = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}