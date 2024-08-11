#include<bits/stdc++.h>
#define N 3010
using namespace std;
int n,m;
char s[N][N];
char pre[N][N];
char suf[N][N];
bool check(int i){
    for(int j=0;j<n;j++){
        if(i==j) continue;
        if(strcmp(pre[i],suf[j])>0){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
        strcpy(pre[i],s[i]);
        strcpy(suf[i],s[i]);
        sort(pre[i],pre[i]+m);
        for(int j=0;j<m;j++){
            suf[i][j]=pre[i][m-j-1];
        }
    }
    //for(int i=1;i<=n;i++){
    //    cout<<s[i]<<' '<<pre[i]<<' '<<suf[i]<<endl;
    //}
    for(int i=0;i<n;i++){
        putchar(char(check(i))+'0');
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
