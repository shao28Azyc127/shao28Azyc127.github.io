#include<bits/stdc++.h>
using namespace std;
int n,m;
int cal[3005][30];
inline bool dfgjh(const int &x,const int &y){
    if(x==0)return y;
    if(y==0)return x;
    for(int i=26;i>=0;i--){
        if(cal[x][i]>cal[y][i])return 0;
        if(cal[y][i]>cal[x][i])return 1;
    }
    return 0;
}
inline bool ok(const int &x,const int &y){
//    cout<<x<<" "<<y<<endl;
    int mix=0;
    int mxy=30;
    for(int i=0;i<=26;i++){
        if(cal[y][i]!=0)mxy=i;
    }
    for(int i=26;i>=0;i--){
        if(cal[x][i]!=0)mix=i;
    }
    return mix<mxy;
}
int bigest=0;
int nxbigest=0;
int main(){
    memset(cal,0,sizeof(cal));
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char x;
            cin>>x;
            cal[i][x-'a']++;
        }
        if(dfgjh(i,bigest)){
            nxbigest=bigest;
            bigest=i;
        }else if(dfgjh(i,nxbigest)){
            nxbigest=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(i!=bigest){
            if(ok(i,bigest))cout<<1;
            else cout<<0;
        }else{
            if(ok(i,nxbigest))cout<<1;
            else cout<<0;
        }
    }
    cout<<endl;
    return 0;
}
