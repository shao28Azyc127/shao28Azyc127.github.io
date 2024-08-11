#include<iostream>
#include<cmath>
using namespace std;
long long n,fz,day,ans;
int main (){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    fz = n;
    long long i = 0;
    long long i2 = 1;
    while(n){
        day ++;
        n -= ceil(n / 3.0);
        if((fz - (i + i2)) % (day + 2) == 0 && ans == 0){
            ans = day;
        }
        long long tmp = i;
        i = i2;
        i2 = tmp + i2;
    }
    cout << day << " " << ans;
    return 0;
}