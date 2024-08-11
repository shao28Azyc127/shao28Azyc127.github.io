#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c,ans;
int num(int a){
    for(int i=0;i<=1005;i++){
        for(int j=0;j<=1005;j++){
            if(j>0&&__gcd(i,j)==1&&a==i/j){
                if(j==1){
                    cout<<i;
                }else{
                    cout<<i<<"/"<<j;
                }
            }
        }
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=0;i<t;i++){
        cin>>a>>b>>c;
        if(pow(b,2)-4*a*c<0){
            cout<<"NO"<<endl;
        }//无解
        if(pow(b,2)-4*a*c==0){
            ans=-b+sqrt(pow(b,2)-4*a*c)/2*a;
        }//有两个相同实根
        if(pow(b,2)-4*a*c>0){

        }//有两个不同实根
    }
    return 0;
}
