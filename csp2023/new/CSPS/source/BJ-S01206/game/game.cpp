#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    string s;
    int n, ans = 0;
    cin >> n;
    for(int i = 0;i < n; i++)
    {
        cin >> s[i];
    }
    for(int i = 0; i < n; i++)
    {
        if(s[i] == s[i + 1])
        {
            ans+=2;
        }
    }
    if(ans != 0)
    {
        cout << ans + 1;
    }
    else
    {
        cout << ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
