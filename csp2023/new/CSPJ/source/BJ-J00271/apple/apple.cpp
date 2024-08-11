#include <iostream>
using namespace std;

int n,last_apple,day,dcnt;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    cin >> n;
    last_apple = n;
    while(last_apple > 0){
        dcnt++;
        if((last_apple - 1) % 3 == 0 && day == 0) day = dcnt;
        last_apple -= (last_apple - 1) / 3 + 1;
    }

    cout << dcnt << ' ' << day;
}
