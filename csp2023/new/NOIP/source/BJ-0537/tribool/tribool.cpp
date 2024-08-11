#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
char a[100005];
int x[100005];
int y[100005];
char cs[100005];
char bh[100005];
char w[6];
int Ul[1005][1005];
bool vis[1005];
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin >> c >> t;
    w[4] = '+';
    w[5] = '-';
    w[1] = 'U';
    w[2] = 'T';
    w[3] = 'F';
    if(c == 1|| c == 2){
        while(t--){
            for(int i = 1; i <= 10; i++){
                cs[i] = 'B';
                bh[i] = 'B';
            }
            cin >> n >> m;
            for(int i = 1; i <= m; i++){
                cin >> a[i];
                if(a[i] == 'U'||a[i]=='T'|| a[i] == 'F'){
                    cin >> x[i];
                }else{
                    cin >> x[i] >> y[i];
                }
            }
            int ans = 100;
            for(int i1 = 1; i1 <= 3; i1++){
                for(int i2 = 1; i2 <= 3; i2++){
                    for(int i3 = 1; i3 <= 3; i3++){
                        for(int i4 = 1; i4 <= 3; i4++){
                            for(int i5 = 1; i5 <= 3; i5++){
                                for(int i6 = 1; i6 <= 3; i6++){
                                    for(int i7 = 1; i7 <= 3; i7++){
                                        for(int i8 = 1; i8 <= 3; i8++){
                                            for(int i9 = 1; i9 <= 3; i9++){
                                                for(int i10 = 1; i10 <= 3; i10++){
                                                    cs[10] = w[i10];
                                                    int sum = 0;
                                                    for(int i = 1; i <= n; i++){
                                                        if(cs[i] == 'U') sum++;
                                                        bh[i] = cs[i];
                                                    }
                                                    if(sum >= ans) continue;
                                                    for(int i = 1; i <= m; i++){
                                                        if(a[i] == 'U') bh[x[i]] = 'U';
                                                        else if(a[i] == 'T') bh[x[i]] = 'T';
                                                        else if(a[i] == 'F') bh[x[i]] = 'F';
                                                        else if(a[i] == '+') bh[x[i]] = bh[y[i]];
                                                        else if(a[i] == '-'){
                                                            bh[x[i]] = bh[y[i]];
                                                            if(bh[x[i]] == 'T') bh[x[i]] = 'F';
                                                            else if(bh[x[i]] == 'F') bh[x[i]] = 'T';
                                                        }
                                                    }
                                                    int flag = 1;
                                                    for(int i = 1; i <= n; i++){
                                                        if(cs[i] != bh[i]){
                                                            flag = 0;
                                                            break;
                                                        }
                                                    }
                                                    if(flag == 1){
                                                        if(ans > sum) ans = sum;
                                                    }
                                                }
                                                cs[9]=w[i9];
                                            }
                                            cs[8]=w[i8];
                                        }
                                        cs[7]=w[i7];
                                    }
                                    cs[6]=w[i6];
                                }
                                cs[5]=w[i5];
                            }
                            cs[4]=w[i4];
                        }
                        cs[3]=w[i3];
                    }
                    cs[2]=w[i2];
                }
                cs[1]=w[i1];
            }
            cout << ans << endl;
        }

    }
    if(c == 3 || c == 4){
        while(t--){

            long long ans = 0;
            cin >> n >> m;
            for(int i = 1; i <= n; i++) bh[i] = 'B';
            for(int i = 1; i <= m; i++){
                cin >> a[i];
                cin >> x[i];
            }
            for(int i = 1; i <= m; i++){
                bh[x[i]] = a[i];
            }
            for(int i = 1; i <= n; i++){
                if(bh[i] == 'U') ans++;
            }
            cout << ans << endl;
        }
    }
    if(c == 5|| c == 6){
        while(t--){
            long long ans = 0;
            cin >> n >> m;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++) Ul[i][j] = 0;
                vis[i] = 0;
                bh[i] = 'B';
                cs[i] = 'B';
            }
            for(int i = 1; i <= m; i++){
                cin >> a[i];
                if(a[i] == 'U') cin >> x[i];
                else cin >> x[i] >> y[i];
            }
            for(int ii = 1; ii<= n; ii++){

                for(int i = 1; i <= m; i++){
                    if(a[i] == 'U') bh[x[i]] = a[i];
                    else if(a[i] == '+') bh[x[i]] = bh[y[i]];
                }
                for(int i = 1; i <= n; i++) {
                    cs[i] = bh[i];
                }
            }
            for(int i = 1; i <= n; i++){
                if(bh[i] == 'U') ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
