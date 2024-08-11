#include <bits/stdc++.h>
using namespace std;
const int N = 10;
struct Lock{
    int p[81][5];
};
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin >> n;
    Lock l[n];
    int a[N][5];
    int b[81][5];
    int m = 0,x = 0,s = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 5;j++){
            cin >> a[i][j];
        }
    }
    if(n == 1){
        cout << 81;
    }
    else{
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= 81;j++)
                for(int k = 1;k <= 5;k++){
                    l[i].p[j][k] = a[i][k];
                }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= 5;j++){
                for(int k = 1;k <= 9;k++){
                    m++;
                    l[i].p[m][j] = (l[i].p[m][j] + k) % 10;
                }
            }
            for(int j = 1;j <= 4;j++){
                for(int k = 1;k <= 9;k++){
                    m++;
                    l[i].p[m][j] = (l[i].p[m][j] + k) % 10;
                    l[i].p[m][j+1] = (l[i].p[m][j+1] + k) % 10;
                }
            }
            m = 0;
        }
        for(int i = 1;i <= 81;i++){
            for(int j = 1;j <= 81;j++){
                if(l[1].p[i][1] == l[2].p[j][1] && l[1].p[i][2] == l[2].p[j][2] && l[1].p[i][3] == l[2].p[j][3] && l[1].p[i][4] == l[2].p[j][4] &&l[1].p[i][5] == l[2].p[j][5]){
                    for(int k = 1;k <= 5;k++){
                        m++;
                        b[m][k] = l[1].p[i][k];
                    }
                    b[m][0] = 1;
                }
            }
        }
        if(n == 2){
            cout << m;
        }
        else{
            for(int i = 3;i <= n;i++){
                for(int j = 1;j <= m;j++){
                    if(b[j][0] == 1){
                        for(int k = 1;k <= 81;k++){
                            if(l[i].p[k][1] == b[j][1] && l[i].p[k][2] == b[j][2] && l[i].p[k][3] == b[j][3] && l[i].p[k][4] == b[j][4] && l[i].p[k][5] == b[j][5]){
                                x++;
                            }
                        }
                        if(x == 0)
                            b[j][0] = 0;
                        x = 0;
                    }
                }
            }
            for(int i = 1;i <= m;i++){
                if(b[i][0] == 1)
                    s++;
            }
            cout << s;
        }
    }
    return 0;
}
