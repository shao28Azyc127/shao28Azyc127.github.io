#include <bits/stdc++.h>
using namespace std;
int ans;
int n;
int no = 1;
string s;
vector<int> answe;
int is_y[10005];
void cot(int p,int q){
    for(int k = p;k <= q;k++){
        cout << s[k];
    }
    cout << endl;
}
int is_c(int a6,int b6,int hw){
    int mj = 0;
    int ans = 0;
    if(s[a6] == s[b6] && b6 - a6 == 1){
        mj+=2;
        is_y[a6] = hw;
        is_y[b6] = hw;
        int a7 = a6;
        int b7 = b6;
        while(s[a7] == s[b7]){
            ans++;
            mj+=2;
            is_y[a7] = hw;
            is_y[b7] = hw;
            if(a7 > 0 && b7 < n - 1){
                a7--;
                b7++;
            }else{
                break;
            }
        }
    }
    return ans;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int answ = 0;
    cin >> n;
    cin >> s;
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            int d = answ;
            answ += is_c(i,j,no);
            if(d != answ){
            }
            no++;
        }
    }
    int lt = 0;
    for(int i = 0;i < n;i++){
        if(is_y[i] && is_y[i + 1] && (is_y[i + 1] != is_y[i]) && (s[i] != s[i + 1])){
            lt++;
        }
        if(!is_y[i] && is_y[i + 1]){
            answ += (lt * (lt + 1)) / 2;
            lt = 0;
        }
    }
    answ+=(lt * (lt + 1)) / 2;
    cout << answ << endl;
    return 0;
}
