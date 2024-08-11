#include <bits/stdc++.h>
using namespace std;

long long n, a, b, c, u, v, t[100010], x, ans, ever[100010], a1[100010], b1[100010], c1[100010];
priority_queue<pair<long long, long long>> q;
vector<int> e[100010];
int uv = 1;

int check1(long long x){
    if(c > 0){
        __int128 sum = (__int128)c * x * (x + 1) / 2 + x * b;
        return sum >= a;
    }else{
        long long p = (1 - b) / c;
        if(x <= p){
            __int128 sum = (__int128)c * x * (x + 1) / 2 + x * b;
            return sum >= a;
        }else{
            __int128 sum = (__int128)c * p * (p + 1) / 2 + p * b + (x - p);
            return sum >= a;
        }
    }
}

long long binary(){
    if(!c) return ceil((double)a / b);
    long long l = 1, r = 1e9;
    while(l < r){
        long long mid = l + r >> 1;
        if(check1(mid)) r = mid;
        else l = mid + 1;
    }
}

int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >> b >> c;
        a1[i] = a;
        b1[i] = b;
        c1[i] = c;
        t[i] = binary();
    }
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        if(u != i || v != i + 1) uv = 0;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(uv){
        for(int i = 1; i <= n; i++){
            a = check1(i) + a1[i];
            b = b1[i];
            c = c1[i];
            ans = max(ans, i + binary());
        }
        cout << ans << endl;
        return 0;
    }
    e[0].push_back(1);
    q.push({0, 0});
    while(!q.empty()){
        ++x;
        pair<long long, long long> p = q.top();
        q.pop();
        ans = max(ans, x + p.first);
        for(int i : e[p.second])
            if(!ever[i]){
                q.push({t[i], i});
                ever[i] = 1;
            }
    }
    cout << ans - 1 << endl;
    return 0;
}
