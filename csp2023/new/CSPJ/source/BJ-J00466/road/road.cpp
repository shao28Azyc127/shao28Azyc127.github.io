#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n, d, k, u;
    unsigned long long sum = 0;
    cin >> n >> d;
    for(int i = 1;i <= n-1;i++){
        cin >> u;
        sum += u;
    }
    cin >> k;
    for(int i = 1;i <= n-1;i++){
        cin >> u;
    }
    int i = 1;
    while(true){
        if(k*d*i >= sum){
            cout << k*i << '\n';
            break;
        }
        i++;
    }
    return 0;
}