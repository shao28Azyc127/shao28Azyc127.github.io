#include <bits/stdc++.h>
#define il inline
using namespace std;
const int N=3005,M=30;
int n,m,in[N][M];char s[N][N];
int mi[N],mx[N],u=26,c;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);if(n==1){printf("1");exit(0);}
    for(int i=1;i<=n;++i){
        scanf("%s",s[i]+1);
        for(int j=1;j<=m;++j) ++in[i][s[i][j]-'a'];
        for(int j=0;j<26;++j){
            if(!in[i][j]) continue;
            mi[i]=j;break;
        }
        for(int j=25;j>=0;--j){
            if(!in[i][j]) continue;
            mx[i]=j;break;
        }
    }
    for(int i=1;i<=n;++i){
        u=26;
        for(int j=1;j<=n;++j) if(i!=j) u=min(u,mx[j]);
        if(u<=mi[i]) putchar('0');
        else putchar('1');
    }
    return 0;
}
