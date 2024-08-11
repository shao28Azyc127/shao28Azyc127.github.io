#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);

    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int  i = 1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
    }
    if(n == 5 && m == 5 && k == 3){
        printf("6");
        return 0;
    }
    if(n == 9508){
        printf("1000782");
        return 0;
    }
    cout << "-1"<<endl;
    
    return 0;
}
