#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;
int n,m,c[N][N];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        string s; cin >> s;
        for(int j = 0;j < s.size();j++){
            c[i][j + 1] = s[j] - 'a' + 1;
        }
        sort(c[i] + 1,c[i] + m + 1);
    }
    for(int i = 1;i <= n;i++){
        bool flag = 1;
        for(int j = 1;j <= n;j++){
            if(i == j) continue;
            if(c[i][1] >= c[j][m]) {flag = 0; break;}
        }
        printf("%d",flag);
    }
    printf("\n");
    return 0;
}