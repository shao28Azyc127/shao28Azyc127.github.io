#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int n;
vector<int> pk;
int cnt[maxn];
int getid(vector<int> pt){
    if(pt.size() < 5) return -1;
    int x = 0;
    for(auto t : pt) x = 10 * x + t;
    return x;
}
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n; pk.resize(5);
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 5;j++){
            cin >> pk[j];
        }
        vector<int> tmp = pk;
        for(int j = 0;j < 5;j++){
            pk = tmp;
            for(int k = 1;k <= 9;k++){
                pk[j] = (pk[j] + 1) % 10;
                cnt[getid(pk)]++;
            }
        }
        for(int j = 0;j < 4;j++){
            pk = tmp;
            for(int k = 1;k <= 9;k++){
                pk[j] = (pk[j] + 1) % 10; pk[j + 1] = (pk[j + 1] + 1) % 10;
                cnt[getid(pk)]++;
            }
        }
    }
    int ans = 0;
    for(int i = 0;i < 100000;i++){
        if(cnt[i] == n){
            ans++;
        }
    }
    cout << ans << endl; return 0;
}
