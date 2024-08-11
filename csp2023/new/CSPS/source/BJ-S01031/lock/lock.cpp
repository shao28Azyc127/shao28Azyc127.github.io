#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int main(){
    freopen("lock.in","r","stdin");
    freopen("lock.out","w","stdout");
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    if(n==1){
        cout<<81;
        return 0;
    }
    else{
        for(int k=1;k<=5;k++){
            for(int i=1;i<=n-1;i++){
                    int f=0;
                for(int j=i+1;j<=n;j++){
                    if(a[i][k]!=a[j][k]){
                        ans+=10;
                        f=1;
                        break;
                    }
                }
            if(f==1) break;
            }
        }
        cout<<ans;
    }
    return 0;
}