#include<iostream>
using namespace std;
int main(){
    freopen ("lock.in","r",stdin);
    freopen ("lock.out","w",stdout);
    int n,a[6][10];
    cin>>n;
    for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
    }
    if(n=1){
        cout<<81;
    }
    return 0;
}
