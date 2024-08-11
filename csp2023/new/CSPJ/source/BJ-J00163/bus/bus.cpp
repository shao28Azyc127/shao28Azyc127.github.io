#include<bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> u[10004];
queue<int> q;
queue<int> v;
int main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int t1 = 0;
        int t2 = 0, t3 = 0;
        cin >> t1 >> t2 >> t3;
        if(t3){
            cout << -1;
            return 0;
        }
        u[t1].push_back(t2);
    }
    q.push(1);
    v.push(0);
    while(!q.empty()){
        int q1 = q.front();
        int v1 = v.front();
        q.pop();
        v.pop();
        if(q1 == n && v1 % k == 0){
            cout << v1;
            return 0;
        }
        for(int i = 0; i <= u[q1].size(); i++){
            q.push(u[q1][i]);
            v.push(v1 + 1);
        }
    }
    cout << -1;
return 0;
}