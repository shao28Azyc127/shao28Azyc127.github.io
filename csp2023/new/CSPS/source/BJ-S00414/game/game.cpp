#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 8000;
ll n, ans;
string s;
void solve(ll x, ll y){
    if((y - x) % 2 == 0)
        return;
    ll con[maxn], sov = 0, pre = -1, len = y - x + 1;
    bool flag[maxn];
    for(ll i = x;i <= y;i++)
        con[i] = i, flag[i] = false;
    ll i = x;
    while(i < y){
        if(con[i] > y || con[i + 1] > y)
            break;
        if(s[con[i]] == s[con[i + 1]]){
            sov += 2, flag[con[i]] = flag[con[i + 1]] = true;
            for(ll j = i;j <= y;j++)
                while(flag[con[j]])
                    con[j] += 2;
            i = 0;
        }else
            i++;
    }
    if(sov == len)
        ans++;
}
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin>>n>>s;
    for(ll i = 0;i < n;i++)
        for(ll j = i + 1;j < n;j++)
            solve(i, j);
    cout<<ans;
    return 0;
}
