#include <bits/stdc++.h>
using namespace std;
const int maxn=4e3+5;
int n,m;
char c[2][maxn][maxn];
inline bool comp(int x,int a,int y,int b){
    for (int i=1;i<=m;i++){
        if (c[a][x][i]>c[b][y][i]) return true;
        else if (c[a][x][i]<c[b][y][i]) return false;
    }
    return false;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin>>c[0][i][j];
    for (int i=1;i<=n;i++){
        sort(c[0][i]+1,c[0][i]+m+1);
        for (int j=1;j<=m;j++) c[1][i][j]=c[0][i][m-j+1];
    }
    int minp=0;
    for (int i=1;i<=n;i++){
        if (!minp) minp=i;
        else if (!comp(i,1,minp,1)) minp=i;
    }
    for (int i=1;i<=n;i++){
        int flag=true;
        if (i!=minp && comp(i,0,minp,1)) flag=false;
        printf("%d",flag);
    }
    return 0;
}
