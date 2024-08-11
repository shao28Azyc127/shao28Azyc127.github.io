#include<bits/stdc++.h>
using namespace std;
bool apple[1000000009];
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int cnt = 0, ncnt = 0;
    bool f1 = 1, f2 = 1;
    while(true){
        f1 = 1;
        cnt++;
        if(f2) ncnt++;
        int last = 0;
        for(int i = 1; i <= n; i++){
            if(last && !apple[i]) last--;
            else if(!apple[i] && !last){
                apple[i] = 1;
                f1 = 0;
                last = 2;
            }
        }
        if(apple[n] && f2) f2 = 0;
        if(f1) break;
    }

    cout << cnt - 1 << ' ' << ncnt;
    return 0;
}
