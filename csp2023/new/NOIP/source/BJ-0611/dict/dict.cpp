#include<bits/stdc++.h>

using namespace std;

char a[3005][3005],min1 = 'z';
int n,m;
string s;

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin >> n >> m;
    s = "";
    min1 = 'z';
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> a[i][j];
        }
        if(a[i][1] < min1){
            min1 = a[i][1];
        }
    }
    if(n == 1){
        s = "1";
    }
    else if(m == 1){
        for(int i = 1;i<=n;i++){
            bool flag = true;//是否w_i<w_j true->是 false->否
            for(int j = 1;j<=n;j++){
                if(j == i){
                    continue;
                }
                if(a[i][1]>=a[j][1]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                s+="1";
                continue;
            }
            s+="0";
        }
    }
    else if(m == 2){
        for(int i = 1;i<=n;i++){
            bool flag = true;//是否w_i<w_j true->是 false->否
            for(int j = 1;j<=n;j++){
                if(j == i){
                    continue;
                }
                if(a[i][1] <= min1||a[i][2]<= min1){
                    break;
                }
                else{
                    flag = false;
                }
            }
            if(flag){
                s+="1";
                continue;
            }
            s+="0";
        }
    }
    cout << s << endl;
    return 0;
}
