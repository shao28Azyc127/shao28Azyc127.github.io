#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    if(n <= 10){
        int cla[11] = {0,1,2,3,3,4,4,4,5,5,5};
        int clo[11] = {0,1,2,3,1,4,2,1,5,3,1};
        cout << cla[n] << " " << clo[n];
        return 0;
    }
    int t = 3;
    int ms = 3;
    int an;
    if(n == 1 || n == 2){
        an = 1;
    }
    else{
        bool f = false;
        while(t != n){
            for(int j = 1;j < ms;j++){
                if(t == n){
                    f = true;
                    break;
                }
                t += 1;
            }
            ms += 1;
            if(f){
                break;
            }
        }
        an = ms;
    }
    cout << an << " ";
    if(n % 3 == 1){
        cout << 1;
        return 0;
    }
    vector <int> a;
    for(int i = 1;i <= n;i++){
        a.push_back(i);
    }
    int locate[n + 10];
    int i = 1;
    while(!a.empty()){
        for(int j = 0;j < n;j += 3){
            locate[a[j]] = i;
            a.erase(a.begin() + j);
        }
        i += 1;
    }
    cout << locate[n];
    return 0;
}
