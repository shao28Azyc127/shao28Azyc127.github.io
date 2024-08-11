#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
using namespace std;

stack<char> st;

bool removeable(string s)
{
    while (!st.empty()) st.pop();
    for (int i = 0; i < s.size(); i++)
    {
        if (!st.empty())
        {
            if (st.top() == s[i]) st.pop();
            else st.push(s[i]);
        }
        else st.push(s[i]);
    }
    return st.empty();
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 1; j <= s.size() - i; j++)
        {
            if (removeable(s.substr(i, j))) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
