#include<iostream>
#include<cmath>
using namespace std;
int t,m;
int gcd(int x,int y){
    int b,temp;
    if(y>0) b=1;
    else b=-1;
    x=abs(x),y=abs(y);
    while(y){
        temp=y;
        y=x%y;
        x=temp;
    }
    return x*b;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int d=b*b-4*a*c;
        if(d<0){
            cout<<"No"<<endl;
            continue;
        }
        double d1=sqrt(d);
        if(a>0){
            if(floor(d1)==ceil(d1)){
                if(d1-b==0){
                    cout<<0<<endl;
                    continue;
                }
                int g=gcd(d1-b,2*a);
                if(2*a==g) cout<<(d1-b)/g<<endl;
                else cout<<(d1-b)/g<<"/"<<2*a/g<<endl;
            }
            else{
                int q1=-b,q3=2*a,m=int(d1);
                int q2,r;
                for(int i=m;i>=1;i--){
                    if(d%(i*i)==0){
                        q2=i;
                        r=d/(i*i);
                        break;
                    }
                }
                int g2=gcd(q2,q3),g1=0;
                if(q1!=0){
                    g1=gcd(q1,q3);
                    if(q3==g1) cout<<q1/g1;
                    else cout<<(q1/g1)<<"/"<<(q3/g1);
                    cout<<"+";
                }
                if(q2==g2&&q3==g2) cout<<"sqrt("<<r<<")"<<endl;
                else if(q3==g2) cout<<q2/g2<<"*sqrt("<<r<<")"<<endl;
                else if(q2==g2) cout<<"sqrt("<<r<<")/"<<q3/g2<<endl;
                else cout<<q2/g2<<"*sqrt("<<r<<")/"<<q3/g2<<endl;
            }
        }
        else{
            if(floor(d1)==ceil(d1)){
                if(-d1-b==0){
                    cout<<0<<endl;
                    continue;
                }
                int g=gcd(-d1-b,2*a);
                if(2*a==g) cout<<(-d1-b)/g<<endl;
                else cout<<(-d1-b)/g<<"/"<<2*a/g<<endl;
            }
            else{
                int q1=-b,q3=2*a,m=int(d1);
                int q2,r;
                for(int i=m;i>=1;i--){
                    if(d%(i*i)==0){
                        q2=-i;
                        r=d/(i*i);
                        break;
                    }
                }
                int g2=gcd(q2,q3),g1=0;
                if(q1!=0){
                    g1=gcd(q1,q3);
                    if(q3==g1) cout<<q1/g1;
                    else cout<<(q1/g1)<<"/"<<(q3/g1);
                    cout<<"+";
                }
                if(q2==g2&&q3==g2) cout<<"sqrt("<<r<<")"<<endl;
                else if(q3==g2) cout<<q2/g2<<"*sqrt("<<r<<")"<<endl;
                else if(q2==g2) cout<<"sqrt("<<r<<")/"<<q3/g2<<endl;
                else cout<<q2/g2<<"*sqrt("<<r<<")/"<<q3/g2<<endl;
            }
        }
    }
    return 0;
}
