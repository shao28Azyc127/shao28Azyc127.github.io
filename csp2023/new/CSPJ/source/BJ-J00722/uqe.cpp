#include<bits/stdc++.h>
using namespace std;
int t,m,p,q,d,x;
struct uqe{
    int a,b,c;
}u[6001];
bool e(int n){
    return 1;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    for(int i=1;i<=t;i++){
        scanf("%d%d%d",&u[i].a,&u[i].b,&u[i].c);
    }
    for(int i=1;i<=t;i++){
        d=u[i].b*u[i].b-4*u[i].a*u[i].c;
        if(d<0){
            cout<<"NO";
        }else{
            float x=(-u[i].b+sqrt(d))/2*u[i].a;
            if(e(d)){
                cout<<x<<endl;
                /*if(q==1){
                    cout<<p<<endl;
                }else{
                    cout<<p<<"/"<<q<<endl;
                }*/
            }else{
                cout<<12*sqrt(3);
            }
        }
    }

    return 0;
}
