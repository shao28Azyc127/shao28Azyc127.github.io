#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int n, ans;
string s;
map<string, int> mp;


bool check(string x)
{
    if (x.length() == 0) return true;
    if (x.length() % 2 == 1) return false;
    if (mp[x] == 1) return true;
    if (mp[x] == -1) return false;
    for (int i = 1; i < x.length(); i++)
    {
        if (x[i] == x[i - 1])
        {
            string tmp = "";
            if (i > 1) tmp += x.substr(0, i - 1);
            if (i < x.length() - 1) tmp += x.substr(i + 1);
            if (check(tmp))
            {
                //cout << x << " " << i << " " << tmp << " true\n";
                mp[tmp] = 1;
                return true;
            }
            else
            {
                //cout << x << " " << i << " " << tmp << " false\n";
                mp[tmp] = -1;
            }
        }
    }
    return false;
}

void dfs()
{
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= n - i; j++)
        {
            if (s.substr(i, j).length() == 0) continue;
            //cout << s.substr(i, j) << endl;
            if (check(s.substr(i, j))) ans++;
            //cout << s.substr(i, j) << " " << ans << endl;
        }
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s;
    dfs();
    printf("%d\n", ans);
    return 0;
}
