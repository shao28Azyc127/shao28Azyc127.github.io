#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int t,w,t1;
double x,y;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&w);
    for(int i=1;i<=t;i++){
        scanf("%d%d%d",&a,&b,&c);
        t1=pow(b,2)-4*a*c;
        if(t1<0){
            cout<<"NO";
        }
        if(t1==0){
            cout<<(-b+sqrt(t1))/2*a;
        }
        else{
            x=max((-b+sqrt(t1))/2/a,(-b-sqrt(t1))/2/a);
            y=min((-b+sqrt(t1))/2/a,(-b-sqrt(t1))/2/a);
            if(x==y){

            }
        }
    }
    return 0;
}

