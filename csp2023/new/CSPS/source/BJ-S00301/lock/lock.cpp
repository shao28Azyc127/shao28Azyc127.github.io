#include<iostream>
#include<string>
using namespace std;
int lock[9][85][6] = {0};
bool sign[86] = {false};
string s;
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n = 0;
    cin >> n;
    //input make a list tha include all possible
    for(int o = 1; o <= n; o++){
        char s[5] = {0};
        for(int i = 0; i <= 4; i++){
            cin >> s[i];
        }
        //i:the digital changed j:possible situation k:digital
        for(int i = 0; i < 5; i++){
            for(int j = 1; j <= 9; j++){
                for(int k = 1; k <= 5; k++){
                    if(k == i + 1){
                        lock[o][9 * i + j][k] = s[k - 1] - '0' + j;
                        if(lock[o][9 * i + j][k] >= 10){
                            lock[o][9 * i + j][k] -= 10;
                        }
                    }else{
                        lock[o][9 * i + j][k] = s[k - 1] - '0';
                    }
                    
                }
            }
        }
        for(int i = 0; i < 4; i++){
            for(int j = 1; j <= 9; j++){
                for(int k = 1; k <= 5; k++){
                    if(k == i + 1 || k == i + 2){
                        lock[o][45 + 9 * i + j][k] = s[k - 1] - '0' + j;
                        if(lock[o][45 + 9 * i + j][k] >= 10){
                            lock[o][45 + 9 * i + j][k] -= 10;
                        }
                    }else{
                        lock[o][45 + 9 * i + j][k] = s[k - 1] - '0';
                    }
                }
            }
        }
    }
    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 81; j++){
            for(int k = 1; k <= 5; k++){
                cout << lock[i][j][k];
            }
            cout << endl;
        }
    }
    */
    //compare the different list
    //i:the time of the lock j:the num of the code in 1 face k:the num of the code in other faces o:the digital
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= 81; j++){
            if(!sign[j]){
                bool flag1 = false;
                for(int k = 1; k <= 81; k++){
                    int flag = 0;
                    for(int o = 1; o <= 5; o++){
                        if(lock[1][j][o] != lock[i][k][o]){
                            break;
                        }
                        flag++;
                    }
                    if(flag == 5){
                        flag1 = true;
                        break;
                    }
                }
                if(!flag1){
                    sign[j] = true;
                }
            }
        }
    }

    //count the true possible way
    int ans = 0;
    for(int i = 1; i <= 81; i++){
        if(!sign[i]){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}