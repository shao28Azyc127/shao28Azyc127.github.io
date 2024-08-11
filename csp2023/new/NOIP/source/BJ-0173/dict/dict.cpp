#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 3005
int n,m;
char s[MAXN][MAXN],minn[MAXN][MAXN],maxx[MAXN][MAXN];
bool cmp(char x,char y){
    return x>y;
}
bool check(int x,int y){
    for(int i=1;i<=m;i++){
        if(minn[x][i]<maxx[y][i]) return 1;
        else if(minn[x][i]>maxx[y][i]) return 0;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>(s[i]+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) minn[i][j]=maxx[i][j]=s[i][j];
        sort(minn[i]+1,minn[i]+1+m);
        sort(maxx[i]+1,maxx[i]+1+m,cmp);
    }
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=1;flag&&j<=n;j++){
            if(j==i) continue;
            if(!check(i,j)) flag=0;
        }
        cout<<flag;
    }
    return 0;
}