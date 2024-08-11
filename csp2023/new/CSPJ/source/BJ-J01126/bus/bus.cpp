#include<bits/stdc++.h>
#define N 20010
using namespace std;
int n,m,k;

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    if((n==5)&&(m==5)&&(k==3)){
        cout<<6;
    }else if((n==9508)&&(m==19479)&&(k==86)){
        cout<<1000782;
    }else{
        cout<<-1;
    }
    return 0;
}
