#include<bits/stdc++.h>
using namespace std;
long long a, t = 1, b[100005], tmp, c, d;
bool flag = true;
int main(){
    freopen("apple.in" ,  "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> a;
    for(int i = 1; i <= a; i ++){
        b[i] = i;
    }
    while(1){
    	tmp = 2;
        for(int i = 1; i <= a; i ++){
            if(b[i] != -1){
                flag = true;
            }
        }
        if(flag == false){
            d = t - 1;
            break;
        }
        for(int i = 1; i <= a; i ++){
            if(b[i] != -1){
                tmp++;
            }
            if(tmp == 3){
                if(i == a){
                    c = t;
                }
                b[i] = -1;
                tmp = 0;
            }
        }
        tmp = 2;
        t++;
        flag = false;
    }
    cout << c << " " << d;
    return 0;
}
