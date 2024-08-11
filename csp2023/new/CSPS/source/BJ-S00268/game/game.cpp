#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
#include<unordered_map>
#include<map>
using namespace std;
typedef unsigned long long ll;
int n;
char s[2000005];
int st[2000005], t;
pair<ll,ll> hs[2000005];
ll ans;
constexpr ll mod = 100000000000000021;
inline pair<ll,ll> ins(pair<ll,ll> hs, int c)
{
    return {(hs.first*29+c),(hs.second*29+c)%mod};
}
map<pair<ll,ll>,int> mp1;
// unordered_map<pair<ll,ll>,int,hs> mp1;
int cnt = 0;
void solve(int l, int r)
{
    cnt++;
    if(l == r) return;
    mp1.clear();
    int mid = (l+r)>>1;
    t = 0;
    for(int i = mid; i >= l; i--)
    {
        if(st[t] == s[i]) t--;
        else st[++t] = s[i], hs[t] = ins(hs[t-1], s[i]);
        mp1[hs[t]]++;
    }
    t = 0;
    for(int i = mid+1; i <= r; i++)
    {
        if(st[t] == s[i]) t--;
        else st[++t] = s[i], hs[t] = ins(hs[t-1], s[i]);
        if(mp1.find(hs[t]) != mp1.end()) ans += mp1[hs[t]];
    }
    solve(l, mid);
    solve(mid+1, r);
}
int main()
{
    ifstream cin("game.in");
    ofstream cout("game.out");
    st[0] = -1;
    cin >> n >> (s+1);
    for(int i = 1; i <= n; i++) s[i] -= 'a'-1;
    solve(1, n);
    cout << ans;
    return 0;
}