#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("upe.in","r",stdin);
    freopen("upe.out","w",stdout);
    int t,m;
    scanf("%d%d",&t,&m);
    int a,b,c;
    for(int i=1;i<=t;i++){
        scanf("%d%d%d",&a,&b,&c);
        int s=b*b-4*a*c;
        if(s<0) printf("NO");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
