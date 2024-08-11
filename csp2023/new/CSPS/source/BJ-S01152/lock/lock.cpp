#include<bits/stdc++.h>
using namespace std;
int n,a[8][5],ans;
int c[5];

bool check(){
    int x;
    for(int i = 0;i < n;i++){
        x = 0;
        for(int j = 0;j < 5;j++){
            if(a[i][j] != c[j]){
                x++;
            }
        }
        if(x == 0 || x > 2){
            return false;
        }
        if(x == 1){
            continue;
        }
        x = -1;
        for(int j = 0;j < 5;j++){
            if(a[i][j] != c[j]){
                if(x != -1){
                    if(j-x != 1 || ((a[i][j]-c[j] != a[i][x]-c[x]) && (abs(a[i][j]-c[j]-a[i][x]+c[x]) != 10))){
                        return false;
                    }
                }else{
                    x = j;
                }
            }
        }
    }
    return true;
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 5;j++){
            cin>>a[i][j];
        }
    }
    for(c[0] = 0;c[0] < 10;c[0]++){
        for(c[1] = 0;c[1] < 10;c[1]++){
            for(c[2] = 0;c[2] < 10;c[2]++){
                for(c[3] = 0;c[3] < 10;c[3]++){
                    for(c[4] = 0;c[4] < 10;c[4]++){
                        if(check()){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
