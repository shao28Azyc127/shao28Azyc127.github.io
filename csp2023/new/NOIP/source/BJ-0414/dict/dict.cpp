#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
char s[3005][3005],ts[3005][3005];
bool cmp(char a,char b){
    return a>b;
}
bool pan(int x,int y){
    int i=0;
    while(ts[x][i]==s[y][i]&&i<m){
        i++;
    }
    return ts[x][i]<s[y][i];
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        getchar();
        scanf("%s",&s[i]);
        sort(s[i],s[i]+m,cmp);
    }
    for(int i=1;i<=n;i++){
        ans=0;
        for(int j=0;j<m;j++){
            ts[i][j]=s[i][m-j-1];
        }
        for(int j=1;j<=n;j++){
            if(j!=i){
                if(pan(i,j)){
                    ans=1;
                }
                else{
                    ans=0;
                    break;
                }
            }
        }
        printf("%d",ans);
    }
    printf("\n");
    return 0;
}

