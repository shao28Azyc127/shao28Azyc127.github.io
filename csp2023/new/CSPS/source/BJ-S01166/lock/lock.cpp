#include<bits/stdc++.h>
using namespace std;
int rd(){
    int x=0,f=1;
    char b = getchar();
    while(!isdigit(b)){
        if(b == '-') f = -1;
        b = getchar();
    }
    while(isdigit(b)){
        x = (x << 3) + (x << 1) + (b^48);
        b=getchar();
    }
    return x*f;
}

int n;
int a[20][6];
int tdiff;
bool tflag;
int ttemp[3];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    n=rd();
    if(n==1){
        cout << 81;
        return 0;
    }int cnt = 1;
    for(int i = 1; i <= n ; i ++){
        for(int j = 1 ; j <= 5;j++){
            a[i][j] = rd();
            //bool fl=false;
            if(i == 2 && a[2][j] != a[1][j]){
                tdiff++;
                ttemp[cnt] = j;
                if(cnt == 2 && ttemp[2] != ttemp[1]+1){
                    tflag = true;
                }
                cnt++;
            }
        }
    }
    int diff = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= 5 ;j++){
            for(int k = 0;k<n;k++){
                if(a[i][j] != a[i-k][j]){
                    diff++;
                }
            }
        }
    }
    if(n==2 || diff == 2){
        if(tdiff == 0){
            cout << 81;
            return 0;
        }
        else if(tdiff == 1){
            if(ttemp[1] == 1 || ttemp[1] == 5){
                cout << 10;
                return 0;
            }
            else{
                cout << 12;
                return 0;
            }
        }
        else{
            if(tflag){
                cout << 2;
                return 0;
            }else{
                if(a[1][ttemp[2]] - a[1][ttemp[1]] == a[2][ttemp[2]] - a[2][ttemp[1]]){
                    cout << 10;
                    return 0;
                }else{
                    cout << 2;
                    return 0;
                }
            }
        }

       // cout <<endl <<  ttemp[1] << " " <<ttemp[2] << " " << a[1][ttemp[2]];
    }else{
        if(diff == n){
            cout << 9-n;
            return 0;
            }

    }

    cout << 1;

    return 0;
}
