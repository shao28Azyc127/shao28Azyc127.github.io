#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[2000005], sum;
vector<ll> v[27];
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ll n;
    string s;
    cin >> n >> s;
    for(ll i = 0; i < s.size(); ++i)
    {
        for(ll j : v[s[i] - 'a'])
        {
            int f = 1;
            if((i - j) % 2 == 0)
                continue;
            for(ll l = j + 1, r = i - 1; l < r; ++l, --r)
            {
                if(s[l] != s[r])
                {
                    f = 0;
                    break;
                }
            }
            if(f)
            {
                a[i] = a[j - 1] + 1;
            }
        }
        v[s[i] - 'a'].push_back(i);
    }
    for(int i = 0; i < s.size(); ++i)
        sum += a[i];
    cout << sum << endl;
    return 0;
}
