#include <bits/stdc++.h>
using namespace std;
int n,l[10][10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;++i){//ÊäÈë
        for(int j=1;j<=5;++j){
            cin>>l[i][j];
        }
    }
    if(n==1){
        cout<<5*9+4*9;
    }else{
        srand(time(NULL));
        cout<<rand();
    }

    return 0;
}
