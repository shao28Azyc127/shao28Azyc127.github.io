#include<bits/stdc++.h>
using namespace std;
double p,q;
int beint(double c){
    double d=c;
    return d-int(c);
}
void be(double a,double b){
    if(a<0&&b<0){
        a=abs(a);
        b=abs(b);
    }
    a=a*1e8;
    b=b*1e8;
    int minnum=min(a,b);
    for(int i=2;i<sqrt(minnum);i++){
        while(int(a)%i==0&&int(b)%i==0){
            a/=i;
            b/=i;
        }
    }
    p=a;
    q=b;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    cin>>T>>M;
    for(int i=0;i<T;i++){
        double a,b,c;
        cin>>a>>b>>c;
        int sum=b*b-4*a*c;
        if(sum<0) cout<<"NO"<<endl;
        else{
            be(-b,2*a);
            double i=sqrt(sum),x=p/q;
            cout<<i<<x;
            if(x-int(x)==0){
                if(i-int(i)==0) cout<<(x+i)<<endl;
                else cout<<x<<"+"<<"sqrt("<<sum<<")"<<endl;
            }
            else{
                if(i-int(i)==0) cout<<(i*q+p)<<"/"<<q<<endl;
                else cout<<p<<"/"<<q<<"+sqrt("<<sum<<")"<<endl;
            }
        }
    }
    return 0;
}