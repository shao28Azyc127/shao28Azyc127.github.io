#include<bits/stdc++.h>
using namespace std;
stack<char> st;
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        for(int len = 1;len + i <= n;len++)
        {
            string t = s.substr(i, len);
            st.push('1');
            for(int i = 0;i < t.size();i++)
            {
                if(st.top() != t[i]) st.push(t[i]);
                else st.pop();
            }
            if(st.top() == '1')
            {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
