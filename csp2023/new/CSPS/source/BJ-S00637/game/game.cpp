#include<bits/stdc++.h>
using namespace std;
const int N = 8005;
int n,ans;
bool c[N][N];
string s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n); cin >> s;
    memset(c,0,sizeof(c));
    for(int i = 0;i + 1 < n;i++)
        if(s[i] == s[i + 1])
            c[i][i + 1] = 1,ans++;
    for(int len = 4;len <= n;len += 2){
        for(int i = 0;i + len - 1 < n;i++){
            int j = i + len - 1;
            for(int k = i + 1;k <= j;k += 2)
                c[i][j] |= c[i][k] && c[k + 1][j];
            if(s[i] == s[j])
                c[i][j] |= c[i + 1][j - 1];
            if(c[i][j]){
                ans++;
                //printf("%d %d\n",i,j);
            }

        }
    }
    printf("%d\n",ans);
    return 0;
}