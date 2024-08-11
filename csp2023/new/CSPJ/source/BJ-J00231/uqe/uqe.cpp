#include <bits/stdc++.h>
using namespace std;
long long T,M,a,b,c;
long double d,x1,x2,q1,q2,q3;
long long gcd(long long a,long long b){
    long long m = a>b?a:b;
    for(long long i = m;i>0;i--){
        if(a%i==0&&b%i==0)return i;
    }
}
int main(){

    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    for(long long i = 0;i<T;i++){
        cin>>a>>b>>c;
        d = b*b-4*a*c;
        if(d<0)cout<<"NO"<<endl;
        else{
            x1 = (0-b+sqrt(d))/2/a;
            x2 = (0-b-sqrt(d))/2/a;

            if(round(x1)!=x1||round(x2)!=x2){
                    if(x1>x2){
                        q1 = (0-b)/2/a;
                        q2 = (1/2/a);
                        q3 = 1/q2;
                        if(q1!=0)cout<<q1/gcd(q1,2*a)<<"/"<<2*a<<"+";
                        if(q2=1)cout<<"sqrt("<<d<<")"<<endl;
                        else if(round(q2)==q2)cout<<q2<<"*"<<"sqrt("<<d<<")"<<endl;
                        else if(round(q3)==q3)cout<<"sqrt("<<d<<")/"<<q3;

                    }
                    else{
                        q1 = (0-b)/2/a;
                        q2 = (1/2/a);
                        q3 = 1/q2;
                        if(q1!=0)cout<<q1/gcd(q1,2*a)<<"/"<<2*a<<"-";
                        if(q2=1)cout<<"sqrt("<<d<<")"<<endl;
                        else if(round(q2)==q2)cout<<q2<<"*"<<"sqrt("<<d<<")"<<endl;
                        else if(round(q3)==q3)cout<<"sqrt("<<d<<")/"<<q3;

                    }

            }else{
                if(x1>x2)cout<<x1<<endl;
                else cout<<x2<<endl;
            }}

        }

    return 0;
}
