#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int m,n;
    cin >> n >> m;
    int cont = 1;
    int e[n+5][m+5] = {0};//panding shifou bei paixuguo
    int f[n+5] = {0};//cout
    int g[n+5];
    int x,y;//position of d
    char a[n+5][m+5];//cin dictionary
    char b[n+5][m+5];//min  dictionary
    char c[n+5][m+5];//max dictionary
    char d = 'z';
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[i][j];//di i hang di j ge zimu
        }
        g[i] = 1;
    }
    if(n == 1){
        cout << 1;
    }
    else if(m == 1){
        for(int i = 1;i <= n;i++){
            if(a[i][1] <= d)
                d = a[i][1];
        }
        for(int i = 1;i <= n;i++){
            if(a[i][1] == d)
                g[i] = 1;
            else
                g[i] = 0;
        }
        for(int i = 1; i <= n;i++){
            cout << g[i];
        }
    }
    else{
        for(int i = 1;i <= n;i++){//min dictionary
            while(cont <= m ){
                for(int j = 1;j <= m;j++){
                    if(a[i][j] <= d && e[i][j] == 0){
                        d = a[i][j];
                        x = i;
                        y = j;
                    }
                }
                e[x][y] = 1;
                b[i][cont] = d;
                cont++;
                d = 'z';
            }
            cont = 1;
        }
        d = 'a';
        for(int i = 1;i <= n;i++){//max dictionary
            for(int j = 1;j <= m;j++){
                e[i][j] = 0;
            }
        }
        for(int i = 1;i <= n;i++){
            while(cont <= m ){
                for(int j = 1;j <= m;j++){
                    if(a[i][j] >= d && e[i][j] == 0){
                        d = a[i][j];
                        x = i;
                        y = j;
                    }
                }
                e[x][y] = 1;
                c[i][cont] = d;
                cont++;
                d = 'a';
            }
            cont = 1;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(j != i){
                    for(int k = 1;k <= m;k++){
                        while(f[i] == 0 && g[i] == 1){
                            if(b[i][k] < c[j][k]){
                                g[i] = 1;
                                f[i] = 1;
                            }
                            else if(b[i][k] == c[i][k])
                                f[i] = 0;
                            else {
                                f[i] = 1;
                                g[i] = 0;
                            }
                        }
                    }
                    f[i] = 0;
                }
            }
        }
        for(int i = 1; i <= n;i++){
            cout << g[i];
        }
    }
    return 0;
}
