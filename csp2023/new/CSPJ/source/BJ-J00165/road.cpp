#include <iostream>
#include <cstdio>
using namespace std;
int v[100100], c[100101];
int main(){
    freopen("road.in","r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i < n; i++){
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }
    int now =1;
    int cost = 0,sum = 0 ;
    for (int i = 1; i <= n; i++){
        if(c[i] <= c[now]){
            now = i;
        }
        if(v[i]%d == 0){
            cost += v[i]/d * c[now];
        }else {
            cost += (v[i]/d+1)*c[now];
        }
    }
    int minnum = c[1];
     for (int i = 1; i <= n; i++){
            if(c[i] <= minnum){
                minnum = c[i];
            }
     }
     if(c[1] == minnum){
            int sum = 0;
        for (int i = 1; i <= n; i++){
            sum += v[i];
        }
        if(sum%d == 0){
            cost = sum/d * minnum;
        }else {
            cost = (sum/d+1)*minnum;
        }
     }
    cout << cost;
    return 0;
}
