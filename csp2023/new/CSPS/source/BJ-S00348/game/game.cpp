#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

string str, s;

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    int length, len, cnt = 0;
    bool flag = true;
    cin >> length >> str;
    for (int l = 0; l < length; l++)
    {
        for (int r = l + 1; r < length; r += 2)
        {
            s = str.substr(l, r + 1);
            flag = true;
            len = r - l + 1;
            while (flag && len)
            {
                flag = false;
                for (int i = 0; i < len - 1; i++)
                {
                    if (s[i] == s[i + 1])
                    {
                        s = s.substr(0, i) + s.substr(i + 2, len);
                        len -= 2;
                        flag = true;
                    }
                }
            }
            if (len == 0)
                cnt++;
        }
    }
    cout << cnt;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
