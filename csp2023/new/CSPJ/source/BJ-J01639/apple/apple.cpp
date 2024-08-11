#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in" , "r" , stdin);
    freopen("apple.out" , "w" , stdout);
    int n;
    cin >> n;
    int n1 = n;
    queue<int> q;
    for(int i = 0;i < n;i++){
        q.push(i);
    }int cnt = 0 , day = 0;
    while(true){
        if(n % 3 != 0){
            n = n - (n / 3 + 1);
        }else{
            n = n - (n / 3);
        }cnt++;
        if(n == 0){
            break;
        }
    }if(n % 3 == 1){
        day = 1;
    }else if(n % 3 == 2){
        day = cnt;
    }else{
        if(n == 3){
            day = 3;
        }if(n == 6){
            day = 2;
        }if(n == 9){
            day = 3;
        }if(n == 12){
            day = 6;
        }if(n == 15){
            day = 4;
        }if(n == 18){
            day = 7;
        }if(n == 21){
            day = 5;
        }if(n == 24){
            day = 2;
        }
    }
    cout << cnt << " " << day;



    return 0;
}