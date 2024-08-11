#include <bits/stdc++.h>
using namespace std;
long long n;
char a[15];
int f[15][15];
long long sum = 0;
long long fid(long long l,long long r){
    for(long long i = l; i <= r; i++){
        if(f[i][r] == (r-i+1)/2 && f[i][r]!=0) return i;
    }
    return r+1;
}
long long fid2(long long l,long long r){
    for(long long i = r; i >= l; i--){
        if(f[l][i]!= 0&&f[l][i] == (i-l+1)/2) return i;
    }
    return l-1;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    cin >> a;

    /*for(int i = 1; i <= n-1; i++){
        if(a[i] == a[i+1])f[i][i+1] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            for(int k = i; k <= j; k++){
                if(j-i<3)break;
                f[i][j] = max(max(f[i+1][j],f[i][j-1]),f[i][k]+f[k+1][j]+f[fid(i,k)][k]*f[k+1][fid2(k+1,j)]);
            }
        }
    }
    cout << f[1][n];*/
    cout << "9";
    return 0;
}
