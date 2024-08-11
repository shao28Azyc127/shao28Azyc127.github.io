#include<bits/stdc++.h>
using namespace std;
int n;
int a[100050][11];
int main(){
    int as=0;
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
     for(int j=1;j<=n;j++){
        for(int i=1;i<=5;i++){
                  cin>>a[j][i];
        }
    }
    int y=1;
    y=0;

    if(n==1){
        cout<<81;
        return 0;
    }
    bool flag=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            if(a[i][j]!=a[i+1][j]) flag=1;
        }
    }
    if(flag==0){
        cout<<81;
        return 0;
    }

    if(n==2){
        int u[11];
        int un=0;
        for(int i=1;i<=5;i++){
            if(a[1][i]!=a[2][i]){
                un++;
                u[un]=i;
            }
        }
        if(un>2){
            cout<<0;
            return 0;
        }
        if(un<=2){
            if(un==2){
                if(a[1][u[1]]-a[2][u[1]]==a[1][u[2]]-a[2][u[2]]){
                    cout<<8;
                    return 0;
                }else{


                }
            }
            if(un==1){
                cout<<10;
                return 0;
            }
        }
        if(un==0){
            cout<<81;
            return 0;
        }

    }
    if(n>2){
        int u[11];
        int un=0;
        for(int i=1;i<=5;i++){
            for(int j=1;j<n;j++){
            if(a[j][i]!=a[j+1][i]){
                un++;
                u[un]=i;
                j++;
                break;
            }
            }
        }
        if(un>2){
            cout<<0;
            return 0;
        }
        if(un==1){
            cout<<10-n;
            return 0;
        }
        if(un==0){
            cout<<81;
            return 0;
        }



}
    cout<<10;


return 0;
}
