#include <bits/stdc++.h>

using namespace std;

string fan(string s)
{
    string result = "";
    int i, l;
    l = s.size();
    for(i=l-1; i>=0; i--)
    {
        result += s[i];
    }
    return result;
}

string ST[2000005];
int flag[2000005];

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int i, j, k;
    int n;
    string s;
    cin >> n >> s;

    for(i=0; i<n; i++)
    {
        ST[i] = s[i];
    }
    int x = 1;
    long long ans = 0;
    for(i=1; i*2<=n; i*=2)
    {
        for(j=0; j<=n-i*2; j++)
        {
            if((flag[j] != 0 && flag[j+i] != 0) || ST[j] == ST[j+i] || ST[j] == fan(ST[j+i]))
            {
                ans++;
                flag[j] = i;
            }
            ST[j] += ST[j+i];
            if(flag[j] != i) flag[j] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
