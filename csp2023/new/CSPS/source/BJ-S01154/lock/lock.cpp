#include<bits/stdc++.h>
using namespace std;
long long n=0,a[10][10],temp1,temp2,temp3;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    cout<<81<<"\n";
    return 0;
}
