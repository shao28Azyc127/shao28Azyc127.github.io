#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int num[26];
int pre[26][200001];
string x;

bool subst(int tmp1, int tmp2){
    stack <int> s;
    for (int i = tmp1; i <= tmp2; i++){
        if (s.empty() == false && s.top() == x[i]-'a'){
            s.pop();
        }else{
            s.push(x[i]-'a');
        }
    }
    return s.empty();
}

int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    cin >> x;
    int ans = 0;
    int cons = 0;
    for (int i = 0; i < n-1; i++){
        if (x[i] == x[i+1]){
            ans++;
        }
    }
    for (int i = 0; i < n-3; i++){
        for (int j = i+3; j < n; j += 2){
            if (subst(i,j) == true){
                ans++;
            }
        }
    }
    cout << ans;


    /*
    pre[0] = 0;
    for (int i = 0; i < n; i++){
        pre[x[i]-'a'][i+1] = pre[x[i]-'a'][i+1] + 1;
    }
    for (int i = 1; i <= n-1; i++){
        for (int j = i+1; j <= n; j++){
            int flag = 0;
            for (int k = 0; k < 26; k++){
                if ((pre[k][j]-pre[k][i-1]) % 2 == 1){

                }
            }
        }
    }
    */
    return 0;
}
