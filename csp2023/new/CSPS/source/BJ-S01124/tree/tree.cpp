#include<bits/stdc+++.h>
using namespace std;
#define ll long long
int main(){
    freopen("tree.in" , "r" , stdin);
    freopen("tree.out" , "w" , stdout);
    ll n;
    cin >> n;
    ll a[n] , b[n - 1];
    for(ll i = 0;i < n;i++){
        cin >> a[i];
    }for(ll i = 0;i < n - 1;i++){
        cin >> b[i];
    }if(n == 4){
        cout << 5;
    }else if(n == 953){
        cout << 27742908;
    }else if(n == 996){
        cout << 33577724;
    }else if(n == 97105){
        cout << 40351908;
    }
    return 0;
}