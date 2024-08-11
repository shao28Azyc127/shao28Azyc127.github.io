#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n, p[1001], ans;
string s;

string read()
{
    string an = "";
    char c = getchar();
    while (c < 'a' || c > 'z') c = getchar();
    while (c >= 'a' && c <= 'z')
    {
        an = an + c;
        c = getchar();
    }
    return an;
}

bool kxc2(int le, int ri)
{
    //int l = le, r = ri, cnt = 0;
    stack<char> sta;
    sta.push(s[le]);
    for (int i = le + 1; i <= ri; ++i)
    {
        if (sta.size() && sta.top() == s[i])
        {
            sta.pop();
        }
        else sta.push(s[i]);
    }
    return !sta.size();
}


bool kxc(int le, int ri)
{
    //printf("%d %d\n", le, ri);
    int l = le, r = ri, cnt = 0;
    string t = s;
    while (cnt * 2 < ri - le + 1 && l < r)
    {
        //while (t[l] == '0')
        int cx = 0;
        while (l - cx >= le && l + cx + 1 <= ri && t[l - cx] != '0' && t[l - cx] == t[l + cx + 1])
        {
            t[l - cx] = '0', t[l + cx + 1] = '0';
            //p[l - cx] =
            cx++;
        }
        cnt += cx;
        l = l + cx + 1;
    }
    return cnt * 2 == ri - le + 1;
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    s = read();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j <= n - 1; j += 2)
        {
            if (kxc2(i, j)) ans++;
        }
    }
    printf("%d", ans);
    return 0;
}