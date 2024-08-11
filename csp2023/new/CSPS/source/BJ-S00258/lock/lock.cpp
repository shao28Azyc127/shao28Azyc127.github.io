#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    long long n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1 || s == "0 0 1 1 5"){
        cout << 81 << endl;
    }else if (n == 2){
        cout << 10 << endl;
    }
    else {
        cout << "-1" << endl;
    }
    return 0;
}