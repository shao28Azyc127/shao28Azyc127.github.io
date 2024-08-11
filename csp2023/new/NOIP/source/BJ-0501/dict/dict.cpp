#include<iostream>
#include<string>
using namespace std;
int n, m;
string s[3000];
int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    bool sign = true;
    if(m == 1){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i != j){
                    if(s[i] >= s[j]){
                        sign = false;
                    }
                }
            }
            if(sign){
                cout << "1";
            }else{
                cout << "0";
            }
            sign = true;
        }
    }else if(m == 2){
        char letter;
        for(int i = 1; i <= n; i++){
            if(s[i][0] > s[i][1]){
                letter = s[i][0];
                s[i][0] = s[i][1];
                s[i][1] = letter;
            }
            for(int j = 1; j <= n; j++){
                if(i != j){
                    if(s[j][0] < s[j][1]){
                        letter = s[j][0];
                        s[j][0] = s[j][1];
                        s[j][1] = letter;
                    }
                    if(s[i] >= s[j]){
                        sign = false;
                    }
                }
            }
            if(sign){
                cout << "1";
            }else{
                cout << "0";
            }
            sign = true;
        }
    }//70pts
    cout << endl;
    return 0;
}