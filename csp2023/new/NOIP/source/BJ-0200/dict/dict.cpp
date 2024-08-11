#include <bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m;
char s[N][N];
int mx[N];
int minn[N];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
        minn[i]=100000000;
        for(int j=1;j<=m;j++){
            if(s[i][j]-'a'+1>mx[i]) mx[i]=s[i][j]-'a'+1;
            if(s[i][j]-'a'+1<minn[i]) minn[i]=s[i][j]-'a'+1;
        }
    }
    if(n==1){
        cout<<1;
        return 0;        
    }
    for(int i=1;i<=n;i++){
        bool flg=0;
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            if(minn[i]>mx[j]) {
                flg=1;
                break;
            }
            if(minn[i]==mx[j] && minn[j]<=mx[i]){
                flg=1;
                break;
            }
        }
        if(!flg){
            printf("1");
        }else{
            printf("0");
        }
    }
    return 0;
}