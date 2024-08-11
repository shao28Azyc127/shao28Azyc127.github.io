#include<iostream>
using namespace std;
int n;
int a[10][6];
int b[6];
int ans;
int dist1(int x, int y){
    if(x < y){
        return x + 10 - y;
    }
    else{
        return x - y;
    }
}
int dist2(int x, int y){
    if(x > y){
        return y + 10 - x;
    }
    else{
        return y - x;
    }
}
void dfs(int x){
    if(x > 5){
        bool flag = true;
        for(int i = 1; i <= n; i ++){
            int diff = 0;
            for(int j = 1; j <= 5; j ++){
                if(b[j] != a[i][j]){
                    diff ++;
                }
            }
            if(diff != 1){
                flag = false;
                break;
            }
        }
        if(flag == true){
            ans ++;
        }
        else{
            bool two = true;
            for(int i = 1; i <= n; i ++){
                bool flag = false;
                int diff = 0;
                for(int j = 1; j < 5; j ++){
                    int d1 = dist1(b[j], a[i][j]);
                    int d2 = dist1(b[j + 1], a[i][j + 1]);
                    int d3 = dist2(b[j], a[i][j]);
                    int d4 = dist2(b[j + 1], a[i][j + 1]);
                    if(d1 == d2 || d3 == d4){
                        if(d1 == d2){
                            if(d1 != 0){
                                flag = true;
                            }
                        }
                        else if(d3 == d4){
                            if(d3 != 0){
                                flag = true;
                            }
                        }
                    }
                }
                for(int j = 1; j <= 5; j ++){
                    if(b[j] != a[i][j]){
                        diff ++;
                    }
                }
                if(flag == false || diff != 2){
                    two = false;
                    break;
                }
            }
            if(two == true){
                ans ++;
            }
        }
        return;
    }
    for(int i = 0; i <= 9; i ++){
        b[x] = i;
        dfs(x + 1);
    }
}
int main (){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= 5; j ++){
            cin >> a[i][j];
        }
    }
    dfs(1);
    cout << ans;
    return 0;
}