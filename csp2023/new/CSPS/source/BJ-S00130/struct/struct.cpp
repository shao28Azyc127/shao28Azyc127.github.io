#include <iostream>
#include <map>
using namespace std;
map<string, int> f, cnt;
map<int, string> S;
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cnt["byte"] = 1, cnt["short"] = 2, cnt["int"] = 4, cnt["long"] = 8;
    int n, tot = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int op;
        cin >> op;
        if (op == 2)
        {
            string s, x;
            cin >> s >> x;
            while (tot % cnt[s] != 0) tot++, S[tot] = "ERR";
            f[x] = tot;
            S[tot] = s;
            cout << tot << '\n';
            if (s == "byte") S[tot] = x, tot++;
            else if (s == "short") S[tot] = x, S[tot + 1] = x, tot += 2;
            else if (s == "int") S[tot] = x, S[tot + 1] = x, S[tot + 2] = x, S[tot + 3] = x, tot += 4;
            else S[tot] = x, S[tot + 1] = x, S[tot + 2] = x, S[tot + 3] = x, S[tot + 4] = x, S[tot + 5] = x, S[tot + 6] = x, S[tot + 7] = x, tot += 8;
        }
        else if (op == 3)
        {
            string s;
            cin >> s;
            cout << f[s] << '\n';
        }
        else
        {
            int x;
            cin >> x;
            cout << S[x] << '\n';
        }
    }
    return 0;
}
