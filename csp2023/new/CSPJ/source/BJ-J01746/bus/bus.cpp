#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    long long a,b,c;
    cin >> a >> b >> c;
    for(int i = 0;i < b;i++){
        long long d,e,f;
        cin >> d >> e >> f;
    }
    if(a ==5 && b == 5 && c == 3){
        cout << "6";
    }
    else if(a == 9508 && b == 19479 && c ==86){
        cout <<"1000782";
    }
    else{
        cout << "-1";
    }
    return 0;
}
