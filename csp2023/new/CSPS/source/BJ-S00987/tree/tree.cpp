#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n , a , b , c , sum;

void PraseIn(){
    cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> a >> b >> c;
        sum = max(sum , a / b);
    }
    for(ll i = 1; i < n; i++){
        cin >> a >> b;
    }
}
void Core(){

}
void WriteOut(){
    cout << sum;
}
int main(){
    freopen("tree.in" , "r" , stdin);
    freopen("tree.out" , "w" , stdout);
    PraseIn();
    Core();
    WriteOut();
    return 0;
}
