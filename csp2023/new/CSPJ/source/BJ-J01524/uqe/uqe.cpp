#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    int a,b,c,d;
    for(int i=0;i<t;i++){
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        d=(b*b)-(4*a*c);
        if(d<0) printf("NO");
        else{
            int x=max(((-1*b+sqrt(d))/2*a),((-1*b-sqrt(d))/2*a));
            printf("%d",x);
        }
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
