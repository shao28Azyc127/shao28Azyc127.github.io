#include<iostream>
using namespace std;
char a[2000005];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,x=0,ans=0;
    a[0]=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i-x];
        if(a[i-x]==a[i-x-1]){
            a[i-x]=a[i-x-1]=1;
            x+=2;
            ans++;
        }
    }
    if(a[1]=1){
        ans++;
    }
    cout<<ans;
    return 0;
}
