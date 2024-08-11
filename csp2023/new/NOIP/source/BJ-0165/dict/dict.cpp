#include<bits/stdc++.h>
using namespace std;
struct IO{
    IO(){
        freopen("dict.in","r",stdin);
        freopen("dict.out","w",stdout);
    }
    ~IO(){
        fclose(stdin);
        fclose(stdout);
    }
}io;
const int N=3007;
int n,m;
char sf[N][N],sb[N][N];//forward,backward
bool ans;
bool cmp(char a,char b){
    return a<b;
}
bool pmc(char a,char b){
    return a>b;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",sf[i]+1);
        for(int j=1;j<=m;j++){
            sb[i][j]=sf[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        stable_sort(sf[i]+1,sf[i]+1+m,cmp);
        stable_sort(sb[i]+1,sb[i]+1+m,pmc);
    }
    for(int i=1;i<=n;i++){
        ans=1;
        for(int j=1;j<=n;j++){
            if(!ans){
                break;
            }
            if(j!=i){
                for(int k=1;k<=m;k++){
                    if(sb[j][k]>sf[i][k]){
                        break;
                    }
                    if(sf[i][k]>sb[j][k]){
                        ans=0;
                        break;
                    }
                }
            }
        }
        printf("%d",(ans?1:0));
    }
    printf("\n");
    return 0;
}
