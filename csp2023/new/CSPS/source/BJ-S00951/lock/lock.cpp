#include<bits/stdc++.h>
using namespace std;
long long s[15][15][15][15][15];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    long long n;
    cin >> n;
    for(int a = 0;a <= 9;a++){
        for(int b = 0;b <= 9;b++){
            for(int c = 0;c <= 9;c++){
                for(int d = 0;d <= 9;d++){
                    for(int e = 0;e <= 9;e++){
                        s[a][b][c][d][e] = 0;
                    }
                }
            }
        }
    }
    for(int i = 1;i <= n;i++){
        long long a,b,c,d,e;
        cin >> a >> b >> c >> d >> e;
        for(int j = 0;j <= 9;j++){
            if(a != j)s[j][b][c][d][e]++;
            if(b != j)s[a][j][c][d][e]++;
            if(c != j)s[a][b][j][d][e]++;
            if(d != j)s[a][b][c][j][e]++;
            if(e != j)s[a][b][c][d][j]++;
        }
        for(int j = 1;j <= 9;j++){
            s[(a + j) % 10][(b + j) % 10][c][d][e]++;
            s[a][(b + j) % 10][(c + j) % 10][d][e]++;
            s[a][b][(c + j) % 10][(d + j) % 10][e]++;
            s[a][b][c][(d + j) % 10][(e + j) % 10]++;
        }
    }
    long long ans = 0;
    for(int a = 0;a <= 9;a++){
        for(int b = 0;b <= 9;b++){
            for(int c = 0;c <= 9;c++){
                for(int d = 0;d <= 9;d++){
                    for(int e = 0;e <= 9;e++){
                        if(s[a][b][c][d][e] >= n){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
