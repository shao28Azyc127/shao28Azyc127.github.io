#include <bits/stdc++.h>
using namespace std;
int n,lst[10][5],v[10],d[10],t = 0,cnt = 0;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 5;j++){
            cin >> lst[i][j];
            v[i] = v[i] * 10 + lst[i][j];
        }
    }
    for(int i = 0;i <= 99999;i++){
        t = 0;
        for(int j = 0;j < n;j++){
            for(int z = 0;z < 5;z++){
                int a = i / int(pow(10,z)) % 10,b = v[j] / int(pow(10,z)) % 10;
                d[z] = (a - b + 10) % 10;
            }
            int l = 0,index = -1,zero = 0;
            for(int z = 0;z < 5;z++){
                if(d[z] != 0){
                    if(l == 0){
                        l = d[z];
                        index = z;
                    }
                    else if(l == d[z] && abs(index - z) == 1) l = 11;
                    else l = -1;
                }
                else zero++;
            }
            if(l != -1 && zero != 5){
                t++;
            }
        }
        if(t == n){
            t = 0;
            cnt++;
        }
    }
    cout << cnt<< endl;
    return 0;
}
