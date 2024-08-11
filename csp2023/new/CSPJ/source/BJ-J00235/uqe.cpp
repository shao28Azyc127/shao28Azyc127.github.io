#include<bits/stdc++.h>
using namespace std;
int a,b,c,m,t,d;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while (t--){
        scanf("%d%d%d",&a,&b,&c);
        d=b*b-4*a*c;
        if (d<0) printf("NO\n");
        else{
            int m1=-b+d,m2=-b-d;
            int m3=max(m1,m2);
            if (m3==m1){
                int lin=sqrt(d);
                if (lin*lin==d){
                    if (m1%(2*a)==0) printf("%d",m1/2/a);
                    else printf("%d/%d",m1,2*a);
                }
            }
        }
    }
    return 0;
}
