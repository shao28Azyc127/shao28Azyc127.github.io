#include<bits/stdc++.h>
using namespace std;
//CSP-S 2023 RP ++!!!
int n, ans;
string a;

bool pd(int l, int r){
    string s = "";
    for(int i = l; i <= r; i ++){
        s += a[i];
    }
    bool flag = 1;
//     cout << l << " " << r << " " << s << ":" << endl;
    while(flag){
        string sk = "";
        flag = 0;
        for(int j = 0; j < s.size() - 1; j ++){
            if(s[j] == s[j + 1] && s[j] != '0'){
                flag = 1;
                s[j] = '0';
                s[j + 1] = '0';
            }
        }
 //     cout << " " << s << " " << endl;
        for(int j = 0; j < s.size(); j ++){
            if(s[j] != '0'){
                sk += s[j];
            }
        }
        s = sk;
  //      cout << sk << endl;
        if(sk == ""){
 //           cout << " ans++" << endl;
            return 1;
        }
    }
    return 0;
}

int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
        cin >> a;
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j ++){

                if(pd(i, j)){
                    ans ++;
                }
            }
        }
        printf("%d", ans);
    return 0;
}
