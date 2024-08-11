#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n , sum , pos;

void PraseIn(){
    cin >> n;
}
void Core(){
    while(n > 0){
        if(n <= 3){
            sum += n;
            if(pos == 0){
                pos = sum;
            }
            n = 0;
            break;
        }
        sum++;
        if(n % 3 == 1 && pos == 0){
            pos = sum;
        }
        n -= (n + 2) / 3;
    }
}
void WriteOut(){
    cout << sum << " " << pos;
}
int main(){
    freopen("apple.in" , "r" , stdin);
    freopen("apple.out" , "w" , stdout);
    PraseIn();
    Core();
    WriteOut();
    return 0;
}
