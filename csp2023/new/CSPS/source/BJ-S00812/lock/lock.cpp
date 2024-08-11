#include<iostream>
#include<cstdio>
using namespace std;
    bool flag[10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,a[100010][6];
    cin>>n;
    if(n==1){
        cout<<81;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    int bian=0;
    for(int j=1;j<=5;j++){
        for(int i=2;i<=n;i++){
            if(a[i][j]!=a[i-1][j]){
                bian=j;
                break;
            }
        }
        if(bian!=0){
            break;
        }
    }
    int last=10;
    for(int i=1;i<=n;i++){
        if(!flag[a[i][bian]]){
            flag[a[i][bian]]=true;
            last--;
        }
    }
    cout<<last;
    return 0;
}
