#include<bits/stdc++.h>
using namespace std;

const int NMAX = 3005;
int n, m, cnt[NMAX][50], mx[NMAX], mn[NMAX];
string w[NMAX];

int trs(char x){return x-'a';}

int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> w[i];
        for(int j=0; j<m; j++){
            cnt[i][trs(w[i][j])]++;
        }
        for(int j=25; j>=0; j--){
            if(cnt[i][j]){
                mx[i]=j; break;
            }
        }
        for(int j=0; j<=25; j++){
            if(cnt[i][j]){
                mn[i]=j; break;
            }
        }
    }
    int a[NMAX];
    for(int i=1; i<=n; i++){
        bool flg=true;
        for(int j=1; j<=n; j++){
            if(j==i) continue;
            if(mn[i]>=mx[j]){
                flg=false; break;
            }
        }
        if(flg) printf("1");
        else printf("0");
    }

    return 0;
}
