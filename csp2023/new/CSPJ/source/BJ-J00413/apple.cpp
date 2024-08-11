#include<iostream>
using namespace std;
bool apple[1000000010] = {false};
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    long long n;
    cin >> n;
    long long num = n;
    int flag = 1;
    int day = 1;
    bool judge = false;
    int ans = 0;
    while(n > 0){
        int sign = 0;
        while(sign < 3){
            //cout << "sign:" << sign << " flag:" << flag << " n:" << n << " day:" << day << endl;
            if(!apple[flag]){
                sign++;
                if(sign == 1){
                    //cout << "kill:" << flag << endl;
                    apple[flag] = true;
                    n--;
                }
            }
            if(flag >= num){
                day++;
                flag = 1;
                break;
            }
            flag++;
            
        }
        if(apple[num] && !judge){
            ans = day - 1;
            judge = true;
        }
    }
    cout << day - 1 << " " << ans << endl;
    return 0;
}