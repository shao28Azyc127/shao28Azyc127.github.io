#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int Nmax = 1e4+5;
string s;
int n, ans;

int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s;
    bool f[n+5][n+5];
    int r;
    for(int i=0;i<n-1;i++) if(s[i]==s[i+1]){
        // cout << i << ' ' << i+1 << endl;
        ans++; f[i][i+1] = 1;
    }
    for(int len=3;len<n;len++){
        for(int l=0;l<n;l++){
            r = l+len;
            if(r >= n) continue;
            if(f[l+1][r-1]==1&&s[l]==s[r]){
                // cout << l << ' ' << r << endl;
                f[l][r] = 1; ans++; continue;
            }
            for(int k=l;k<r;k++){
                if(f[l][k]==1&&f[k+1][r]==1){
                    f[l][r] = 1;
                    // cout << l << ' ' << r << endl;
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}