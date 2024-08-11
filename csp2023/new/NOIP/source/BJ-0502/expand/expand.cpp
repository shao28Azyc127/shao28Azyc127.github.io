#include<bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
inline int read(){
    int x = 0, w = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') w *= -1; ch = getchar();}
    while(ch <= '9' && ch >= '0'){x = x * 10 + ch - '0'; ch = getchar();}
    return x * w;
}
int x[500010], y[500010];
int current_x, current_y;
int changed_x_pos, changed_x, changed_y_pos, changed_y;
bool is_bigger, swapped;
int kxs[500010], kxc[500010], kys[500010], kyc[500010], cxs[500010], cys[500010], kx, ky;//s = value, c = pos, idk why
bool check(int a, int b){
    return !((a > b) ^ is_bigger);
}
void reset(){
    current_x = 0;
    current_y = 0;
    if(!swapped){
        for(int i=0;i<kx;i++){
            x[kxc[i]] = cxs[i];
        }
        for(int i=0;i<ky;i++){
            y[kyc[i]] = cys[i];
        }
    }
    else{
        for(int i=0;i<kx;i++){
            y[kyc[i]] = cys[i];
        }
        for(int i=0;i<ky;i++){
            x[kxc[i]] = cxs[i];
        }
    }
    kx = 0;
    ky = 0;
    memset(kxs, 0, sizeof(kxs));
    memset(kys, 0, sizeof(kys));
    memset(kxc, 0, sizeof(kxc));
    memset(kyc, 0, sizeof(kyc));
    memset(cxs, 0, sizeof(cxs));
    memset(cys, 0, sizeof(cys));
}
int main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    int c = read(), n = read(), m = read(), q = read();
    for(int i=0;i<n;i++){
        x[i] = read();
    }
    for(int i=0;i<m;i++){
        y[i] = read();
    }
    if(n < m){
        for(int i=0;i<m;i++){
            swap(x[i], y[i]);
        }
        swap(n, m);
    }
    swapped = n < m;
    int cnt = -1;
    do{
        if(cnt >= 0){
            reset();
            kx = read();
            ky = read();
            //cout<<"wow\n";
            if(!swapped){
                for(int i=0;i<kx;i++){
                    kxc[i] = read() - 1;
                    kxs[i] = read();
                    cxs[i] = x[kxc[i]];
                    x[kxc[i]] = kxs[i];
                    //cout<<"kxc: "<<kxc[i]<<" kxs: "<<kxs[i]<<" xkxc: "<<x[kxc[i]]<<endl;
                }
                for(int i=0;i<ky;i++){
                    kyc[i] = read() - 1;
                    kys[i] = read();
                    cys[i] = y[kyc[i]];
                    y[kyc[i]] = kys[i];
                }
            }
            else{
                for(int i=0;i<kx;i++){
                    kyc[i] = read() - 1;
                    kys[i] = read();
                    cys[i] = y[kyc[i]];
                    y[kyc[i]] = kys[i];
                }
                for(int i=0;i<ky;i++){
                    kxc[i] = read() - 1;
                    kxs[i] = read();
                    cxs[i] = x[kxc[i]];
                    x[kxc[i]] = kxs[i];
                }
            }
        }
        //cout<<"converted array. the result is:\n";
        //for(int i=0;i<n;i++){
        //    cout<<x[i]<<' ';
        //}
        //cout<<endl;
        //for(int i=0;i<m;i++){
        //    cout<<y[i]<<' ';
        //}
        is_bigger = x[0] > y[0];
        int ans = 1;
        if(x[0] != y[0]){
            int mx = is_bigger ? 0 : INF;
            while(current_x < n || current_y < m){
                if(current_y >= m) current_y = m - 1;
                if(current_x >= n) current_x = n - 1;
                if(is_bigger) mx = max(x[current_x], mx);
                else mx = min(x[current_x], mx);
                //cout<<"checking: "<<x[current_x]<<' '<<y[current_y]<<endl;
                if(!check(x[current_x], y[current_y])){
                    //cout<<"error: "<<x[current_x]<<' '<<y[current_y]<<endl;
                    if(current_y == m - 1){
                        ans = 0;
                        break;
                    }
                    if(is_bigger){
                        if(mx > y[current_y]){
                            current_y ++;
                            continue;
                        }
                        else{
                            ans = 0;
                            break;
                        }
                    }
                    else{
                        if(mx < y[current_y]){
                            current_y ++;
                            continue;
                        }
                        else{
                            ans = 0;
                            break;
                        }
                    }
                }
                else{
                    current_x ++;
                    current_y ++;
                }
            }
        }
        else ans = 0;
        cout<<ans;
        cnt++;
    }while(cnt < q);
    return 0;
}
