#include<bits/stdc++.h>
using namespace std;
int q,p,q1,q2,r;
long long mi(long long z){
    for(int i=1;i*i<=z;i++){
        if(i*i==z);
        return i;
    }
}
bool panduan(long long z){
    long long jsq=0;
    for(int i=1;i<=z;i++){
        for(int j=0;j<=z;j++){
            if(j/i==z){
                jsq++;
                q=i;
                p=j;
            }
        }
    }
    if(jsq==1){
        return 1;
    }
    else{
        return 0;
    }
}
void jisuan(long long z){
    for(int i=0;i<=z;i++){
        for(int j=1;j*j<=z;j++){
            if((z-i)/j>0){
                q1=i;
                r=j*j;
                q2=(z-i)/j;
            }
        }
    }
}
int main(){
    long long a,b,c,t,m;
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c;
        if((b*b)-(4*a*c)<0){
            cout<<"NO"<<endl;
            continue;
        }
        else if((b*b)-(4*a*c)>=0){
            long long x1,x2,s;
            s=(b*b)-(4*a*c);
            x1=(b*-1+mi(s))/2*a;
            x2=(b*-1-mi(s))/2*a;
            if(panduan(max(x1,x2))){
                if(q==1){
                    cout<<p<<endl;
                }
                else{
                    cout<<p<<"/"<<q<<endl;
                }
                continue;
            }
            else{
                jisuan(max(x1,x2));
                if(q2==1){
                    cout<<"sqrt({"<<r<<"})"<<endl;
                }
            }
        }
        return 0;
    }
}
