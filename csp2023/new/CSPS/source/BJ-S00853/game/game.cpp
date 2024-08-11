#include<bits/stdc++.h>
using namespace std;
long long n,ans,top=0;
char a[2000005];
char b[2000005];
long long pd(int x,int y){
    top=0;
    for(int i=x;i<=y;i++){
        top++;
        b[top]=a[i];
        if(b[top]==b[top-1]){
            top-=2;
        }
    }
    if(top==0) return 1;
    else return 0;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(pd(i,j)==1)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}