#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m;
int p1,p2;
int a[N][N],b[N][N];
bool cmp1(int a,int b){
    return a<b;
}
bool cmp2(int a,int b){
    return a>b;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    if(n==1){
        puts("1");
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch;
            scanf(" %c",&ch);
            a[i][j]=b[i][j]=(ch-'a'+1);
        }
    }
    for(int i=1;i<=n;i++){
        sort(a[i]+1,a[i]+1+m,cmp1);
        sort(b[i]+1,b[i]+1+m,cmp2);
    }
    p1=1,p2=0;
    for(int i=1;i<=n;i++){
        if(i==p1||i==p2) continue;
        int ok1=0,ok2=0;
        for(int j=1;j<=m;j++){
            if(b[i][j]<b[p1][j]){
                ok1=1;
                break;
            }
            else if(b[i][j]>b[p1][j]) break;
        }
        for(int j=1;j<=m;j++){
            if(b[i][j]<b[p2][j]){
                ok2=1;
                break;
            }
            else if(b[i][j]>b[p2][j]) break;
        }
        if(ok1) p2=p1,p1=i;
        else if(ok2) p2=i;
    }
    for(int i=1;i<=n;i++){
        int ok=1;
        if(i==p1){
            for(int j=1;j<=m;j++){
                if(b[p2][j]<a[i][j]){
                    ok=0;
                    break;
                }
                else if(b[p2][j]>a[i][j]) break;
            }
        }
        else{
            for(int j=1;j<=m;j++){
                if(b[p1][j]<a[i][j]){
                    ok=0;
                    break;
                }
                else if(b[p1][j]>a[i][j]) break;
            }
        }
        printf("%d",ok);
    }
    puts("");
    return 0;
}
