#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 2000002;

int n;
ll ans;
string s;
int tot;
char sta[MAXN];

/*
bool Check(string str)
{
    for(int i = 0;i < str.length();i++)
    {
        char top = sta.top();
        if(str[i] == top)
            sta.pop();
        else
            sta.push(str[i]);
    }

    int len = sta.size();
    while(!sta.empty())
        sta.pop();
    return len == 0;
}
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    cin >> n >> s;
    for(register int i = 0;i < s.length() - 1;++i)
    {
        tot = 1;
        sta[tot] = s[i];
        for(register int j = i + 1;j < s.length();++j)
        {
            if(tot == 0)
            {
                sta[++tot] = s[j];
                continue;
            }
            char tp = sta[tot];
            if(s[j] == tp)
                tot--;
            else
                sta[++tot] = s[j];
            if(tot == 0)
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}