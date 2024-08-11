#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d", &n);
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if ((j - i + 1) % 2 == 1) continue;
            string tmp;
            for (int k = i; k <= j; k++) tmp += s[k];
            for (int k = 0; k < tmp.size() - 1; k++)
            {
                if (tmp[k] == tmp[k + 1])
                {
                    tmp.erase(k,2);
                    if (tmp.size() == 0)
                    {
                        ans++;
                        break;
                    }
                    k = -1;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}