#include <iostream>
#include <string>
#include <stack>
#include <cstdio>

using namespace std;

#define MAXN 2000005

/*
WISH
WISH
*/

struct node
{
    int num;
    char c;
};

int ans = 0, mem[MAXN];
stack<node> s;
stack<char> s1;
char c[MAXN];

bool okay(node a, node b)
{
    if(a.c == b.c)  return true;
    else  return false;
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;

    if(n > 8000)
    {
        for(int i = 1; i <= n; i ++)  cin >> c[i];

        int lat = 0;

        for(int i = 1; i <= n; i ++)
        {
            node t;
            t.num = i, t.c = c[i];

            if(!s.empty() && okay(s.top(), t))
            {
                lat = s.top().num;
                s.pop();
            }
            else  s.push(t);

            if(!s.empty() && s.top().num < lat)  mem[i] = 1, ans ++;
            if(s.empty() && lat != 0)
                mem[i] = 1 + mem[lat - 1], ans += mem[i];
        }

        cout << ans << endl;
    }
    else
    {
        for(int i = 1; i <= n; i ++)  cin >> c[i];

        for(int i = 1; i <= n; i ++)
        {
            for(int j = i; j <= n; j ++)
            {
                if(!s1.empty() && s1.top() == c[j])
                    s1.pop();
                else  s1.push(c[j]);

                if(s1.empty() && j != i)
                    ans ++;
            }

            while(!s1.empty())  s1.pop();
        }

        cout << ans << endl;
    }
    return 0;
}
