#include <iostream>
#include <cstdio>
using namespace std;
int a[10][10];
int main(){
    int i,j,n,ans=90;
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;

    for(i=0;i<n;i++){
        for(j=0;j<5;j++){
            cin>>a[i][j];
        }
    }
    if(n==1){
        cout<<81;
        return 0;
    }
 return 0;
}
