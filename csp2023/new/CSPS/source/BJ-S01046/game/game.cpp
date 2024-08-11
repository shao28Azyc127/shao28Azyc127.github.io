#include <cstdio>
#include <iostream>
using namespace std;

struct node
{
    char c;
    int g = 0;
} a[2000005];

char stack[2000005];
int top = 0;

void push(char x)
{
    stack[top++] = x;
}

void pop()
{
    top--;
}

int f(int x)
{
    int sum = 0;
    for (int i = 1; i < x; i++) sum += i;
    return sum;
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int ans = 0, cur = 0;
    char l = 0;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == l)
        {
            a[cur].g++;
        }
        else
        {
            a[++cur].g = 1;
            a[cur].c = c;
            l = c;
        }
    }
    for (int i = 1; i <= cur; i++)
    {
        if (a[i].g % 2 == 0)
        {
            ans += a[i].g - 1;
            for (int j = 4; j <= a[i].g; j += 2)
            {
                ans += a[i].g / j + 1;
            }
            a[i].g = 0;
        }
        if (a[i].g % 2 == 1)
        {
            ans += a[i].g - 1;
            for (int j = 4; j <= a[i].g; j += 2)
            {
                ans += a[i].g / j + 1;
            }
            a[i].g = 1;
        }
    }
    for (int i = 1; i <= cur; i++)
    {
        if (a[i].g == 0) continue;
        if (top > 0 && stack[top - 1] == a[i].c)
        {
            pop();
            ans++;
        }
        else push(a[i].c);
    }
    if (top == 0) ans++;
    int t = 0;
    for (int i = 1; i <= cur; i++)
    {
        if (a[i].g == 0) t++;
        else t = 0, ans += f(t);
    }
    if (t == cur) ans += f(t) - 1;
    else ans += f(t);
    printf("%d", ans);
    return 0;
}
