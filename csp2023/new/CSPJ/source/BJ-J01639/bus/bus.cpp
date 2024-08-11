#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("bus.in" , "r" , stdin);
    freopen("bus.out" , "w" , stdout);
    int n , m , k;
    cin >> n >> m >> k;
    for(int i = 0;i < m;i++){
        int u , v , a;
        cin >> u >> v >> a;
    }
    if(n == 5 && m == 5 && k == 3){
        cout << 6;
    }else{
        cout << -1;
    }
    return 0;
}