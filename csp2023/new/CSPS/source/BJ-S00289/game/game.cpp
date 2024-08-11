#include<cstdio>
#include<iostream>
using namespace std;
const int N = 8010;
int n;
char s[N];
bool b[N][N] = {};
long long f[N][N] = {};
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    scanf("%s", s + 1);
    for(int len = 2; len <= n; len++){
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            if(len == 2 && s[l] == s[r]){b[l][r] = 1; continue;}//SS
            if(s[l] == s[r] && b[l + 1][r - 1]){b[l][r] = 1; continue;}//SAS
            for(int k = l + 1; k + 1 < r; k++) if(b[l][k] & b[k + 1][r]){b[l][r] = 1; break;}//ABCD..
        }
    }
    for(int len = 2; len <= n; len++){
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            f[l][r] += f[l][r - 1];
            for(int k = l; k < r; k++){
                if(b[k][r]) f[l][r]++;
            }
        }
    }
    /*for(int len = 2; len <= n; len++){
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            printf("%d %d %d\n", l, r, f[l][r]);
        }
        cout << endl;
    }*/
    printf("%lld\n", f[1][n]);
    return 0;
}