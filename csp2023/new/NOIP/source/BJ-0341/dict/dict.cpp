#include<bits/stdc++.h>
using namespace std;
const int maxn = 3005;
int n,m,totamn[maxn][26];
bool compV(int a, int b) {
    int sP = 0, eP = 25;
    while(totamn[a][sP] == 0) sP++;
    while(totamn[b][eP] == 0) eP--;
    if(sP < eP) return true;
    if(sP > eP) return false;
    if(totamn[a][sP] == totamn[b][eP]) return false;
    return false;
}
int main () {
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 26; j++) {
            totamn[i][j] = 0;
        }
        for(int j = 0; j < n; j++) {
            char a;
            scanf(" %c",&a);
            totamn[i][a-'a']++;
        }
    }
    for(int i = 0; i < m; i++) {
        bool ans = true;
        for(int j = 0; j < m; j++) {
            if(i != j && compV(i,j) == false) {
                ans = false;
                break;
            }
        }
        printf("%d",ans);
    }
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
