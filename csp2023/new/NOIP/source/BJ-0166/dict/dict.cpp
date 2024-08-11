#include<bits/stdc++.h>
using namespace std;
char q[3005][3005];
char mn[3005];
char mx[3005];
int ans[3005];
bool cmp1(char a,char b){
    return a<b;
}
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",q[i]+1);
    }
    for(int i=1;i<=n;i++){
        char tmx='a'-1,tmn='z'+1;
        for(int j=1;j<=m;j++){
            tmx=max(q[i][j],tmx);
            tmn=min(q[i][j],tmn);
        }
        mn[i]=tmn;
        mx[i]=tmx;
    }
   //for(int i=1;i<=n;i++){
    //    for(int j=1;j<=m;j++){
   //         cout<<mn[i][j];
    //    }
   // cout<<" ";
    //    for(int j=1;j<=m;j++){
    //        cout<<mx[i][j];
    //    }
    //    cout<<endl;
    //}
    for(int i=1;i<=n;i++){
        if(n==1){
            ans[i]=1;
            continue;
        }
        int f=1;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(mn[i]>=mx[j]){
                f=0;
            }
        }
        ans[i]=f;
    }
    for(int i=1;i<=n;i++){
        printf("%d",ans[i]);
    }
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
