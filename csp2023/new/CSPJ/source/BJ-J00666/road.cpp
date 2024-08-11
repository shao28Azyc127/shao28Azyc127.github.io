#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int v[100001];
int a[100001];
int premn[100001];
int pre[100001];

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    pre[0] = 0;
    for (int i = 1; i <= n-1; i++){
        cin >> v[i];
        pre[i] = pre[i-1] + v[i];
    }
    set <int> s;
    int curmin = 1e9;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] < curmin){
            s.insert(i);
            curmin = a[i];
        }
    }
    int fuel = 0;
    int cost = 0;
    for (int i = 1; i <= n-1; i++){
        if (s.count(i) == 1){
            s.erase(i);
            int dis;
            if (s.empty() == true){
                dis = pre[n-1] - pre[i-1] - fuel;
            }else{
                dis = pre[*s.begin()-1] - pre[i-1] - fuel;
            }
            if (dis % d == 0){
                fuel += dis;
                cost += a[i]*(dis/d);
            } else{
                fuel += (dis/d + 1)*d;
                cost += a[i]*(dis/d+1);
            }
        }
        fuel = fuel - v[i];
    }
    cout << cost;
    return 0;
}
