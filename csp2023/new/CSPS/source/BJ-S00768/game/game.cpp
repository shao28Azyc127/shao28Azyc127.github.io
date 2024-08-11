#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define ll long long
#define _mp make_pair
#define _pb push_back
#define _1 first
#define _2 second
#define MAX_N 2222222

using namespace std;

ll read(){ll x = 0;char c = 0, v = 0;do{c = getchar();if(c == '-')v = 1;} while(c < '0' || c > '9');do{x = (x << 3) + (x << 1) + c - '0';c = getchar();} while(c >= '0' && c <= '9');return v ? -x : x;}

int n;
char s[MAX_N];

struct node
{
    char c;
    int it;
    int t[26];
    node() { ; }
    node(char _c, int _it)
    {
        c = _c, it = _it;
        for(int i = 0; i < 26; i++)
            t[i] = -1;
    }
};

stack<node> emp, stk;
int bac[MAX_N][26], crk[MAX_N];
ll dp[MAX_N];

/*void init()
{
    s[0] = '%';
    stk.push(node('%', 0));
    for(int i = 1; i <= n; i++)
    {
        if(stk.top().c == s[i])
        {
            bac[i] = stk.top().it;
            stk.pop();
        }
        else
        {
            bac[i] = stk.top().t[s[i] - 'a'];
            stk.push(node(s[i], i));
        }
        node vr = stk.top();
        stk.pop();
        vr.t[s[i] - 'a'] = i;
        stk.push(vr);
    }
    stk = emp;
}*/

void init()
{
    for(int i = 2; i <= n; i++)
    {
        if(s[i - 1] == s[i])
            crk[i] = i - 1;
        else
            crk[i] = bac[i - 1][s[i] - 'a'];
        if(crk[i] <= 1)
            continue;
        for(int j = 0; j < 26; j++)
            bac[i][j] = bac[crk[i] - 1][j];
        bac[i][s[crk[i] - 1] - 'a'] = crk[i] - 1;
    }
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    n = read();
    scanf("%s", s + 1);
    init();
    ll ans = 0;
    /*for(int i = 1; i <= n; i++)
        printf("%d ", bac[i][0]);
    printf("\n");
    for(int i = 1; i <= n; i++)
        printf("%d ", bac[i][1]);
    printf("\n");
    for(int i = 1; i <= n; i++)
        printf("%d ", crk[i]);
    printf("\n");*/
    for(int i = 1; i <= n; i++)
    {
        if(!crk[i])
            dp[i] = 0;
        else
            dp[i] = dp[crk[i] - 1] + 1;
        ans += dp[i];
    }
    printf("%lld\n", ans);
    return 0;
}
