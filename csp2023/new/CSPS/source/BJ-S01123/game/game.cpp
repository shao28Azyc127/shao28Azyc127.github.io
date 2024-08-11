#include<bits/stdc++.h>
using namespace std;

#define file(filename) freopen(filename ".in", "r", stdin); freopen(filename ".out", "w", stdout)
#define cppio ios::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define rep(i, b, e) for(register int i(b); i<=(e); ++i)
#define re(i, b, e) for(register int i(b); i<(e); ++i)

constexpr int maxn = 2e6 + 17;

stack<int> stks[maxn];
string str;
int cnt = 0, n;

signed main()
{
    file("game");
    cppio;
    cin >> n >> str;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=i; ++j)
        {
            if(stks[j].empty())
            {
                stks[j].push(str[i-1]-'a');
            }
            else if(stks[j].top() == str[i-1]-'a')
            {
                stks[j].pop();
                if(stks[j].empty()) ++cnt;
            }else stks[j].push(str[i-1] - 'a');
        }
    }
    cout << cnt << endl;
    return 0;
}
