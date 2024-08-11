#include<iostream>
using namespace std;
int s[100010] = {};
int n, m, c, t;
char x;
int y, z;
int ans = 0;
bool sign[100010] = {false};
int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> c >> t;
    if(c == 3 || c == 4){
        for(int i = 1; i <= t; i++){
            ans = 0;
            cin >> n >> m;
            for(int i = 1; i <= n; i++){
                s[i] = i;
            }
            for(int j = 1; j <= m; j++){
                cin >> x >> y;
                s[y] = 0;
            }
            for(int j = 1; j <= n; j++){
                if(s[j] == 0){
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }/*20pts*/else if(c == 5 || c == 6){
        bool flag = false;
        for(int i = 1; i <= t; i++){
            flag = false;
            for(int j = 1; j <= n; j++){
                sign[j] = false;
            }
            ans = 0;
            cin >> n >> m;
            for(int i = 1; i <= n; i++){
                s[i] = i;
            }
            for(int j = 1; j <= m; j++){
                cin >> x;
                if(x == '+'){
                    cin >> y >> z;
                    s[y] = s[z];
                }else{
                    cin >> y;
                    s[y] = 0;
                }
            }
            for(int j = 1; j <= n; j++){
                if(s[j] == 0){
                    ans++;
                    sign[j] = true;
                    flag = true;
                }
            }
            while(flag){
                flag = false;
                for(int j = 1; j <= n; j++){
                    if(!sign[j] && sign[s[j]]){
                        sign[j] = true;
                        ans++;
                        flag = true;
                    }
                }
            }
            cout << ans << endl;
        }
    }/*40pts*/
    return 0;
}