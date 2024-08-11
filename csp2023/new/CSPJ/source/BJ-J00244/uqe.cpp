#include<bits/stdc++.h>
using namespace std;
void m(double x){
    int p,q;
    for(int i=1;i<=50;i++){
            for(int j=1;j<=50;i++){
                if(1.0*i/j==x){
                    if(j==1){
                        cout<<i<<endl;
                        return ;
                    }
                    else{
                        cout<<i<<"/"<<j<<endl;
                        return ;
                    }
                }
            }

    }
    return ;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
   int t=0,m=0,a,b,c,d;
   double z,y,x;
   //cin>>t>>m;
   ///for(int i=1;i<=t;i++){
        //cin>>a>b>>c;
        //d=b*b-4*a*c;
        //if(d<0){
            //cout<<"NO"<<endl;
        //}
        //else{
            //z=(-1*b+sqrt(d))/(2*a);
            //y=(-1*b-sqrt(d))/(2*a);
            //x=max(z,y);
            //if((sqrt(d)*100)%10==0){
            //}

       // }
    //}
    for(int i=1;i<=t;i++){
        cout<<"NO"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
