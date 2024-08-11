#include<bits/stdc++.h>

using namespace std;

#define LL unsigned long long
const int NR=3005;
const LL B=131;

int n,m;
char s[NR];
int t[NR*2][NR];
LL ha[NR*2][NR];

bool work(int x,int y){
    int l=0,r=m,mid,ans=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(ha[x][mid]==ha[y][mid]){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    if(ans==m) return 0;
    return t[x][ans+1]<t[y][ans+1];
}

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=m;j++) t[i][j]=s[j];
        sort(t[i]+1,t[i]+m+1);
        for(int j=1;j<=m;j++) t[i+n][j]=t[i][m-j+1];
        for(int j=1;j<=m;j++){
            ha[i][j]=ha[i][j-1]*B+(LL)t[i][j];
            ha[i+n][j]=ha[i+n][j-1]*B+(LL)t[i+n][j];
        }
    }
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(!work(i,j+n)){
                flag=0;
                break;
            }
        }
        if(!flag) printf("0");
        else printf("1");
    }
    printf("\n");
    return 0;
}