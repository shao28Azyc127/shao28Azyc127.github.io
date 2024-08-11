#include<bits/stdc++.h>

using namespace std;

long long n,ans,y[10][10];
bool dif[10],ddif[10],alldif = true;
int cnt = 0;

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=5;j++){
            cin >> y[i][j];
        }
    }
    if(n == 1){
        cout << 81;
        return 0;
    }
    bool flag = true;
    for(int i = 1;i<=5;i++){
        flag = true;
        int cnt2 = 0;
        for(int j = 2;j<=n;j++){
            if(y[j][i] == y[j-1][i]){
                cnt2++;
            }
        }
        if(cnt2 == n - 1){
            flag = false;
        }
        dif[i] = flag;
    }
    for(int i = 2;i<=5;i++){
        if(dif[i]&&dif[i-1]){
            ddif[i] = true;
        }
    }
    //for(int i = 1;i<=5;i++){
    //    cout << dif[i] << " ";
    //}
    cnt = 0;
    for(int i = 1;i<=5;i++){
        if(!dif[i]){
            cnt++;
        }
    }
    if(cnt == 4){
        cout << 10;
        return 0;
    }
    if(cnt == 5){
        cout << 81;
        return 0;
    }
    if(cnt <= 2){
        cout << 0;
        return 0;
    }
    for(int i = 2;i<=5;i++){
        if(ddif[i]){
            flag = true;
            for(int j = 2;j<=n;j++){
                if((y[j][i]-y[j][i-1])!=(y[j-1][i]-y[j-1][i-1])){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout << 10;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}
