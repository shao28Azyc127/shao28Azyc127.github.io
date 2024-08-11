#include <bits/stdc++.h>
using namespace std;
int n;
int a[10][15];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    int bz[2]={0,0},o=0;
    int flag=0;
    if(n==1){
        cout<<81<<endl;
        return 0;
    }
    else{
        for(int i=1;i<=5;i++){
            flag=a[i][1];
            for(int j=1;j<=n;j++){
                if(flag!=a[i][j]){
                    bz[o++]=i;
                    break;
                }
            }
        }
    }
    //cout<<bz[0]<<" "<<bz[1]<<" ";//
    return 0;
}
