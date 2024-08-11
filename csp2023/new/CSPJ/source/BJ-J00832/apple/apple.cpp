
#include <bits\stdc++.h>

using namespace std;

const int maxn = int(1e9+10);

int apples[maxn] = 0;

int main(){

    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    int appleCount;

    cin >> appleCount;

    for(int i = 1; i <= appleCount; i++){
        apples[appleCount] = 1;
    }
    int appleLeft = appleCount, round = 1;
    int nRound;

    while(appleLeft > 0){
            int taken = 0;
        for(int i = 1; i < appleLeft; i+=3){
            if(apples[i+1] == 0){
                nRound = round;
            }
            taken++;
            apples[i] = 0;
        }
        sort(apples, apples+maxn);
        reverse(apple, apples+maxn);
        appleLeft -= taken;
        round++;
    }

    cout << round << ' ' << nRound << endl;

    return 0;
}
