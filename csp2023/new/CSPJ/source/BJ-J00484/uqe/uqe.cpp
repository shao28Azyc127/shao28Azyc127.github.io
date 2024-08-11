#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int  t,m;
    cin>>t>>m;
    for(int i=0;i<t;i++){
        int a,b,c,d;
        cin>>a>>b>>c;
        if(b==0){
            d=-4*a*c;
            if(d<0) cout<<"No"<<endl;
            if(max(-b+sqrt(d),-b-sqrt(d))==0) cout<<0;
            if(-b+sqrt(d)>=-b-sqrt(d)){
                if((-b+sqrt(d))/(2*a)==1) cout<<'1'<<endl;
                if(sqrt(d)/1*1==sqrt(d)) cout<<-b+sqrt(d)<<'/'<<(2*a)<<endl;
                else cout<<-b<<'+'<<"sqrt("<<d<<')'<<'/'<<2*a<<endl;
            }
            else{
                if((-b-sqrt(d))/(2*a)==1) cout<<'1'<<endl;
                if(sqrt(d)/1*1==sqrt(d)) cout<<-b-sqrt(d)<<'/'<<(2*a)<<endl;
                else cout<<-b<<'-'<<"sqrt("<<d<<')'<<'/'<<2*a<<endl;
            }
        }
        if(c==0){
            if(-2*b>0) cout<<-b<<'-'<<b<<'/'<<(2*a)<<endl;
            else if(-2*b=1) cout<<1<<endl;
            else cout<<0;
        }
    }
    return 0;
}

