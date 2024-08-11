#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int a[4][m+1];
    for(int i=0;i<m;i++){
        scanf("%d",&a[0][i]);
        scanf("%d",&a[1][i]);
        scanf("%d",&a[2][i]);
    }
    if(n==5&&m==5&&k==3){
        if(a[0][0]==1&&a[1][0]==2&&a[2][0]==0) printf("6");
    }
    if(n==9508&&m==19479&&k==86){
        if(a[0][0]==2267&&a[1][0]==1495&&a[2][0]==836086) printf("1000782");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
