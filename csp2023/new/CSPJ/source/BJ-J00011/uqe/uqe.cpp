#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int x,y,a,b,c,p,q,j=0;
    cin>>x>>y;
    for(int i=0;i<x;i++){
        cin>>a>>b>>c;
        int w;
        w=(b*b)-(4*a*c);
        if(w<0){
            cout<<"NO"<<endl;
        }
        else{
            int ans1,ans2;
            ans1=(sqrt(w)-b)/(2*a);
            ans2=(-sqrt(w)-b)/(2*a);
            x=max(ans1,ans2);
            for(int i=0;i>0;i++){
                if(i%x==0){
                    p=i;
                    q=i/x;
                    while(1){
                        if(p%j==0&&q%j==0){
                            if(q==1){
                                cout<<"{"<<p<<"}"<<endl;
                            }
                            else{
                                cout<<"{"<<p<<"}"<<"/"<<"{"<<q<<"}"<<endl;
                            }
                        }
                        j=j+1;
                    }
                }
            }
        }
    }
    return 0;
}
