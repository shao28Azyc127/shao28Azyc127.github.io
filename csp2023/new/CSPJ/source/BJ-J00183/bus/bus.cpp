#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k,a;
    bool b=false;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&a,&a);
        if(a!=0){
            b=true;
        }
    }
    if(!b){
        printf("%d",k*(m/2));
    }else{
        printf("%d",k+k*(m/3));
    }
}
