#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("rode.in" , "r" , stdin);
    freopen("rode.out" , "w" , stdout);
    int n , d;
    cin >> n >> d;
    int a[n] , b[n - 1];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }int sum = 0;
    for(int i = 0;i < n - 1;i++){
        cin >> b[i];
        sum += b[i];
    }if(sum % d == 0){
        cout << (sum / d) * a[0];
    }else{
        cout << (sum / d + 1) * a[0];
    }
    return 0;
}