#include<bits/stdc++.h>
using namespace std;

int n,a[10][10],c[10],cnt;

int qy(int k){
    if(k >= 0){
        return k % 10;
    }else{
        while(k <= 0){
            k += 10;
        }
        return k;
    }
}

bool check(int k){
    int i,j,c1 = 0,c2 = 0;
    bool f = false;
    for(i = 1;i <= 5;i++){
        if(a[k][i] != c[i]){
            if(!f){
                f = true;
                c1 = i;
            }else if(f && a[k][i - 1] != c[i - 1] && a[k][i - 2] == c[i - 2]){
                c2 = i;
            }else{
                return false;
            }
        }
    }
    if(!f){
        return false;
    }
    if(c2 != 0){
        if(qy(a[k][c1] - c[c1]) == qy(a[k][c2] - c[c2])){
            return true;
        }else{
            return false;
        }
    }
    return true;
}

void dfs(int k){
    int i,j,f = true;
    if(k == 6){
        for(i = 1;i <= n;i++){
            if(!check(i)){
                f = false;
                break;
            }
        }
        if(f){
            cnt++;
        }
    }else{
        for(i = 0;i <= 9;i++){
            c[k] = i;
            dfs(k + 1);
        }
    }
}

int main(){
    int i,j;

    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    cin >> n;

    for(i = 1;i <= n;i++){
        for(j = 1;j <= 5;j++){
            cin >> a[i][j];
        }
    }

    dfs(1);

    cout << cnt << endl;
}