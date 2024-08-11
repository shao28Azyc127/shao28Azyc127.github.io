#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,d,u[n-1],a[n],q,j,i,ql;
    cin>>n>>d;
    for(i=1;i<=n-1;i++){
        cin>>u[i];
    }
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    if(u[1]%d!=0){
        q=(u[1]/d+1)*a[1];
        j=q/a[1];
    }
    else{
        q=(u[1]/d)*a[1];
        j=q/a[1];
    }
    for(i=2;i<=n-1;i++){

        if(u[2]%d!=0){
            q+=(u[i]-(j-u[i-1])/d+1)*a[i];
            ql=(u[i]-(j-u[i-1])/d+1)*a[i];
            j=q/a[i];
        }
        else{
             q+=(u[i]-(j-u[i-1])/d)*a[i];
             ql=(u[i]-(j-u[i-1])/d+1)*a[i];
            j=q/a[i];
        }
    }
    cout<<q;
    return 0;
}