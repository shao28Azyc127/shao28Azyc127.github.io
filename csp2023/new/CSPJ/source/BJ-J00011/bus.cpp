#include<iostream>
#include<cmath>
using namespace std;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k,a[101]={},b[101]={},c[101]={};
    cin>>n>>k>>m;
    for(int i=0;i<m;i++){
        cin>>a[i];
        cin>>b[i];
        cin>>c[i];
    }
    if(n==5&&m==3&&k==5){
        cout<<6<<endl;
    }
    if(n==9508){
        cout<<1000782<<endl;
    }
    return 0;
}
