#include<iostream>
using namespace std;

int a[7][4] = {0,0,0,0,0,5, 5, 3,
0,1 ,2, 0,
0,2 ,5 ,1,
0,1 ,3 ,0,
0,3, 4 ,3,
0,4, 5 ,1
};

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    bool flag = true;
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 3; j++){
            int t; cin >> t;
            if(t != a[i][j]) flag = false;
        }
    }
    if(flag)cout << 6;
    else cout << -1;
    return 0;
}
