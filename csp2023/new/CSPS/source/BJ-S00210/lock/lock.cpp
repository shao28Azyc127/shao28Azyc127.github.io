#include <bits/stdc++.h>
using namespace std;
int n;
int a[10][10];
int b[10][10];
int f=0;
map <string ,int> m;
void p1(){
    cout<<"81";
    return;
}
void p2(){
    if (f==0){
        cout<<"81";
        return;
    }

}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=5;j++){
            cin>>a[i][j];
            if (i>=2){
                if (a[i-1][j]!=a[i][j]){
                    b[i][j]=1;
                    f=1;
                }
            }
        }
    }
    if (n==1){
        p1();
    }else{
        p2();
    }

    return 0;
}
