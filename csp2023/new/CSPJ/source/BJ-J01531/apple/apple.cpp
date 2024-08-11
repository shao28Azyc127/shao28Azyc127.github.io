#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    long long n, tian = 0;
    cin>>n;
    long long t;
    bool f = false;
    while(n > 0){
        tian++;
        if(n % 3 == 1&&f == false){
            t = tian;
            f = true;
        }
        if(n == 3||n == 2||n == 1)
            n--;
        else
            n = n / 3 * 2 + n % 3 - 1;
    }
    cout<<tian<<" "<<t;
    return 0;
}