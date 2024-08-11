#include<bits/stdc++.h>
using namespace std;
int n,m;
int t[2][3050][3050];
int f[3050];
bool chk(int it1,int it2,bool id1,bool id2){
    for(int i=1;i<=m;i++){
        if(t[id1][it1][i]<t[id2][it2][i]) return 1;
        if(t[id1][it1][i]>t[id2][it2][i]) return 0;
    }return 0;
}bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        getchar();
        for(int j=1;j<=m;j++){
            f[j]=getchar()-'a';
        }sort(f+1,f+m+1);
        for(int j=1;j<=m;j++){
            t[0][i][j]=f[j];
        }sort(f+1,f+m+1,cmp);
        for(int j=1;j<=m;j++){
            t[1][i][j]=f[j];
        }
    }for(int i=1;i<=n;i++){
        int f=1;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(!chk(i,j,0,1)) f=0;
        }putchar((char)('0'+f));
    }
    return 0;
}
