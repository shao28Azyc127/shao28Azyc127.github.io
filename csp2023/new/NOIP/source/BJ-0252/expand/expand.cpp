#include <iostream>
#include <cstdio>

using namespace std;
int c, n, m, q;
int x[500010], y[500010];
int main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >>  c >>n >>m >>q;
    if(n == 1 && m == 1){
        cin >> x[1] >>y[1];
        if(x[1]> y[1]){
            cout << 1;
        }else{
            cout << 0;
        }
        while(q--){
            int kx, ky;
            cin >> kx >>ky;
            for(int i = 1; i <= kx; i++){
                int px, ux;
                cin >> px >>ux;
                x[px] = ux;
            }
            for(int i = 1; i <= ky; i++){
                int py, uy;
                cin >>py >>uy;
                y[py] = uy;
            }
            if(x[1] >y[1]){
                cout <<1;
            }else{
                cout <<0;
            }
        }
        return 0;
    }else if(n == 1 && m == 2){
         cin >> x[1] >>y[1] >>y[2];
        if(x[1]> y[1] &&x[1] >y[2]){
            cout << 1;
        }else{
            cout << 0;
        }
        while(q--){
            int kx, ky;
            cin >> kx >>ky;
            for(int i = 1; i <= kx; i++){
                int px, ux;
                cin >> px >>ux;
                x[px] = ux;
            }
            for(int i = 1; i <= ky; i++){
                int py, uy;
                cin >>py >>uy;
                y[py] = uy;
            }
            if(x[1] >y[1] && x[1] >y[2]){
                cout <<1;
            }else{
                cout <<0;
            }
        }
        return 0;
    }else if(n == 2 && m == 1){
         cin >> x[1] >> x[2] >>y[1];
        if(x[1]> y[1] && x[2] > y[1]){
            cout << 1;
        }else{
            cout << 0;
        }
        while(q--){
            int kx, ky;
            cin >> kx >>ky;
            for(int i = 1; i <= kx; i++){
                int px, ux;
                cin >> px >>ux;
                x[px] = ux;
            }
            for(int i = 1; i <= ky; i++){
                int py, uy;
                cin >>py >>uy;
                y[py] = uy;
            }
            if(x[1] >y[1] && x[2] >y[1]){
                cout <<1;
            }else{
                cout <<0;
            }
        }
        return 0;
    }else if(n == 2 && m == 2){
         cin >> x[1] >>x[2]>>y[1] >> y[2];
        if(x[1]> y[1] && x[2] >y[2]){
            cout << 1;
        }else{
            cout << 0;
        }
        while(q--){
            int kx, ky;
            cin >> kx >>ky;
            for(int i = 1; i <= kx; i++){
                int px, ux;
                cin >> px >>ux;
                x[px] = ux;
            }
            for(int i = 1; i <= ky; i++){
                int py, uy;
                cin >>py >>uy;
                y[py] = uy;
            }
            if(x[1] >y[1] &&x[2] >y[2]){
                cout <<1;
            }else{
                cout <<0;
            }
        }
        return 0;
    }
    if(8 <= c && c <= 14){
        for(int i = 1; i <= n; i++){
            cin >>x[i];
        }
        for(int i = 1; i <= m; i++){
            cin >> y[i];
        }

        if(x[n] >y[m]){
            cout << 1;
        }else{
            cout << 0;
        }
        while(q--){
            int kx, ky;
            cin >> kx >>ky;
            for(int i = 1; i <= kx; i++){
                int px, ux;
                cin >>px >>ux;
                x[px] = ux;
            }
            for(int i = 1; i <= ky; i++){
                int py, uy;
                cin >> py >> uy;
                y[py] = uy;
            }
            
            if(x[n] > y[m]){
                cout << 1;
            }else{
                cout << 0;
            }
        }
    }
    return 0;
}
//die
