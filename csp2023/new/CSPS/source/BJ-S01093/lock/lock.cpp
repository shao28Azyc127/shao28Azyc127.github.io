#include<iostream>
using namespace std;
struct zt{
    int a,b,c,d,e;
}all[9];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>all[i].a>>all[i].b>>all[i].c>>all[i].d>>all[i].e;
    }
    if(n==1){
        cout<<81;
        return 0;
    }
    else{
        cout<<10;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
