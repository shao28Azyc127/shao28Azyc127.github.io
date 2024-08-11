#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d%d",&t,&m);
    for(int i=1;i<=t;++i){
        scanf("%d%d%d",a,b,c);
        int det = b*b-4*a*c;
        if(det<0)
            printf("NO");
        else if(det==0)
            printf("%d",-b+sqrt(det)/2*a);
        else{
            if(sqrt(det)>-sqrt(det))
                printf("%d",-b+sqrt(det)/2*a);
            else
                printf("%d",-b-sqrt(det)/2*a);
        }
        if(b==0&&c==0){
            cout<<"0";
        }
    }
    fcloseall();
}
