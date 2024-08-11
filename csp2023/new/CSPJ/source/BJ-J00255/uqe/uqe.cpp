#include <bits/stdc++.h>
using namespace std;
long long a,b,c,t,m;
int fang[40]={1,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484,529,576,625,676,729,784,841,900,961};
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >>t >>m;
    while(t--){
        cin >>a >>b >>c;
        long long ansl=(b*b)-(4*a*c);
       // cout <<ansl <<'\n';
        if(ansl<0) cout <<"NO" <<'\n';
        else{
            int popp=sqrt(ansl);
            if(popp*popp!=ansl){
                if(a!=0 && b!=0){
                    if((-b)%(2*a)==0)  cout <<(-b)/(2*a) <<"+";
                    else{
                        long long modd=__gcd((-b),(2*a));
                        if((-b)<0 && (2*a)>0) cout <<"-";
                        if((2*a)<0 && (-b)>0) cout <<"-";
                        cout <<abs((-b)/modd) <<'/';
                        cout <<abs((2*a)/modd)<<"+";
                    }
                }
                long long ansn=0;
                long long ansll=ansl;
                //cout <<ansl <<'\n';
                for(int i=49;i>=2;i--){
                    if(ansll%(i*i)==0) ansll/=(i*i),ansn+=i;
                }
                ansn=max(ansn,1ll);
                //cout <<ansll <<" " <<ansn <<'\n';
                if(ansn==(a*2)) cout <<"sqrt(" <<ansll <<")" <<'\n';
                else if(ansn%(2*a)==0) cout <<abs(ansn/(2*a)) <<"*sqrt(" <<ansll <<")" <<'\n';
                else if((2*a)%ansn==0) cout <<"sqrt(" <<ansll <<")/" <<(2*a)/ansn <<'\n';
                else{
                    long long modd=__gcd((2*a),ansn);
                    cout <<ansn/modd <<"*sqrt(" <<ansll <<")/" <<(2*a)/modd <<'\n';
                }

            }else{
                if(a>0){
                    if((-b+popp)%(2*a)==0){
                        cout <<(-b+popp)/(2*a) <<'\n';
                    }else{
                        //fen
                        long long modd=__gcd((-b+popp),(2*a));
                        if(((-b)+popp)<0 && (2*a)>0) cout <<"-";
                        else if((2*a)<0 && ((-b)+popp)>0) cout <<"-";
                        cout <<abs((-b+popp)/modd) <<'/';
                        cout <<abs((2*a)/modd)<<'\n';
                    }
                }else{
                    if((-b-popp)%(2*a)==0){
                        cout <<(-b-popp)/(2*a) <<'\n';
                    }else{
                        //fen
                        long long modd=__gcd((-b-popp),(2*a));
                        if(((-b)-popp)<0 && (2*a)>0) cout <<"-";
                        else if((2*a)<0 && ((-b)-popp)>0) cout <<"-";
                        cout <<abs((-b-popp)/modd) <<'/';
                        cout <<abs((2*a)/modd)<<'\n';
                    }
                }

            }
        }
    }
    return 0;
}
