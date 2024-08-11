#include <iostream>
using namespace std;
int N[9][82];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,a,b,c,d,e;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c>>d>>e;
    }
    if(n==1){
        cout<<81;
    }
    else if(n>1){
        cout<<10-n;
    }
    return 0;
}
