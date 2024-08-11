#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

bool is_u[100010]; //3~4

int read()
{
    int ans = 0;
    char c = 'c';
    while(c > '9' || c < '0') c = getchar();
    while(c <= '9' && c >= '0')
    {
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans;
}
int n, m;

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c, t;
    c = read();
    t = read();
    for(int times = 1; times <= t; times++)
    {
        n = read();
        m = read();
        if(c == 3 || c == 4) // 20 pts
        {
            memset(is_u, false, sizeof(is_u));
            int a, b, ans = 0;
            char c;
            for(int i = 1; i <= m; i++)
            {
                c = getchar();
                a = read();
                if(c == 'U')
                {
                    if(!is_u[a])
                        is_u[a] = true, ans++;
                }
                else
                {
                    if(is_u[a])
                        is_u[a] = false, ans--;
                }
            }
            printf("%d\n",ans);
        }
        else if(c == 5 || c == 6) // 20 pts
        {
            
            int a, b;
            char c;
            for(int i = 1; i <= m; i++)
            {
                c = getchar();
                a = read();
                if(c == '+')
                {
                    // cout<<"+++\n";
                    b = read();
                    is_u[a] = is_u[b];
                }
                else
                {
                    // cout<<"uuu\n";
                    is_u[a] = true;
                }
            }
            int ans = 0;
            for(int i = 1; i <= n; i++)
            {
                if(is_u[i]) ans++;
            }
            printf("%d\n",ans);
        }
    }
}