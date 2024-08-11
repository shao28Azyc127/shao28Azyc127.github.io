#include<iostream>
using namespace std;
int n;
char c[3000000];
int a[1000][1000]={};
int check(int i,int j){
    if(((i-j)%2)==0)return 0;
    if((j-i)==1){
        if(c[i]==c[j])return 1;
        return 0;
    }
    for(int k=i+1;k<j;k+=2){
        if(a[i][k]&&a[k+1][j])return 1;
    }
    if(c[i]==c[j]){
        if(a[i+1][j-1])return 1;
    }
    return 0;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n-1;i+=2){
        for(int j=1;j<=n-i;j++){
            a[j][j+i]=check(j,j+i);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans+=a[i][j];
        }
    }
    cout<<ans;
    return 0;
}