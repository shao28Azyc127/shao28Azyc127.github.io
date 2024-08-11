#include<bits/stdc++.h>
using namespace std;
int n;
int a[11][6];
bool b[5];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=5;j++){
            if(a[i][j]!=a[0][j]){
                b[j]=1;
            }
        }
    }
    if(b[1]+b[2]+b[3]+b[4]+b[5]==0){
        cout<<81;
        return 0;
    }
    if(n==1){
        cout<<81;
        return 0;
    }
    return 0;
}
