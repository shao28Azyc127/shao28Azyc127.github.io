#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=3010;
int n,m;
char c[MAXN];
int d[MAXN][26];
signed main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",c+1);
        for(int j=1;j<=m;j++)d[i][c[j]-'a'+1]++;
    }
    int a1=1,a2=1;
    for(int i=2;i<=n;i++){
        for(int j=26;j>=1;j--){
            if(d[a1][j]!=d[i][j]){
                if(d[a1][j]>d[i][j]){
                    a1=i;
                }
                break;
            }
        }
    }
    if(a1!=1)a2=1;
    else a2=2;
    for(int i=1;i<=n;i++){
        if(i==a1||i==a2)continue;
        for(int j=26;j>=1;j--){
            if(d[a2][j]!=d[i][j]){
                if(d[a2][j]>d[i][j]){
                    a2=i;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i!=a1){
            int minn=0;
            for(int j=1;j<=26;j++){
                if(d[i][j]){
                    minn=j;break;
                }
            }
            bool tmp=0;
            for(int j=26;j>minn;j--){
                if(d[a1][j]){
                    tmp=1;break;
                }
            }
            printf("%lld",tmp);
        }
        else{
            int minn=0;
            for(int j=1;j<=26;j++){
                if(d[i][j]){
                    minn=j;break;
                }
            }
            bool tmp=0;
            for(int j=26;j>minn;j--){
                if(d[a2][j]){
                    tmp=1;break;
                }
            }
            printf("%lld",tmp);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//lylakioi!!!